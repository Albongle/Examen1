/*
 * clientes.c
 *
 *  Created on: 15 may. 2020
 *      Author: aleja
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "clientes.h"
#include "utn.h"



static eClientes nuevoCliente(int idCliente,char nombre[],char apellido[],char cuil[]);
static int buscarIndiceCliente(eClientes* pArrayClientes, int tamArrayClientes);
static int opcionesModificacion();
static int modiCliente(eClientes clienteRec ,int opcion, eClientes* auxCliente);

void iniArrayClientes(eClientes* pArrayClientes,int tamArrayCLientes,int valorInt)
{
	int i;

	if(pArrayClientes!=NULL && tamArrayCLientes>0)
	{
		for(i = 0; i < tamArrayCLientes; i++)
		{

			pArrayClientes[i].isEmpty=valorInt;

		}
	}

}

int hardcodearClientes(eClientes* pArrayClientes, int tamArrayCLientes, int cantidad)
{

	int cont=0;
	int i;
	if(pArrayClientes!=NULL && tamArrayCLientes>0 && cantidad >0)
	{
		eClientes listaAuxiliar[]=
		{
			{0, "Cliente", "Uno","00-00000001-0",0},
			{1, "Cliente", "Dos","00-00000002-1",0},
			{2, "Cliente", "Tres","00-00000003-2",0},
			{3, "Cliente", "Cuatro","00-00000004-3",0},
			{4, "Cliente", "Cinco","00-00000005-4",0},
			{5, "Cliente", "Seis","00-00000006-5",0},
			{6, "Cliente", "Siete","00-00000007-6",0},
			{7, "Cliente", "Ocho","00-00000008-7",0},
			{8, "Cliente", "Nueve","00-00000009-8",0},
			{9, "Cliente", "Diez","00-00000010-9",0},

		};


		if (cantidad <=tamArrayCLientes && cantidad <11)
		{
			for(i=0; i<cantidad; i++)
			{
				pArrayClientes[i]=listaAuxiliar[i];
				cont++;
			}
		}
	}

return cont;
}


int altaCliente(eClientes* pArrayClientes,int tamArrayClientes, int idCliente, int* posAlta)
{
	int indice;
	int ret=0;
	char bufferNombre[20];
	char bufferApellido[20];
	char bufferCuil[15];

			system("CLS()");
			printf("*****Alta Cliente*****\n\n");
	if(pArrayClientes!=NULL && tamArrayClientes>=0 && idCliente>=0)
	{
			indice=buscarIndiceCliente(pArrayClientes,tamArrayClientes);

			if(indice==-1)
			{
				printf("Sistema completo, no se puede agregar mas clientes\n\n");
				system("PAUSE()");
			}
			else
			{
				fflush(stdin);
				if(utn_getTexto(bufferNombre,"Ingrese el nombre del cliente\n","Error verifique los datos ingresados quedan %d intentos\n",3,20))
				{
					fflush(stdin);
					if(utn_getTexto(bufferApellido,"Ingrese Apellido del cliente\n","Error verifique los datos ingresados quedan %d intentos\n",3,20))
					{
						fflush(stdin);
						if(utn_getCuil(bufferCuil,"Ingrese el CUIL del cliente (00-00000000-0) del cliente\n","Error verifique los datos ingresados quedan %d intentos\n",3,15))
						{
							pArrayClientes[indice]=nuevoCliente(idCliente,bufferNombre,bufferApellido,bufferCuil);
							*posAlta=indice;
							ret=1;
						}

					}
				}
			}
	}

return ret;

}


static int buscarIndiceCliente(eClientes* pArrayClientes, int tamArrayClientes)
{
int indice=-1;
int i;

if(pArrayClientes!=NULL && tamArrayClientes>0 )
{

	for(i=0;i<tamArrayClientes;i++)
	{
		if(pArrayClientes[i].isEmpty==1)
		{
			indice=i;
			break;
		}
	}
}

return indice;
}



static eClientes nuevoCliente(int idCliente,char nombre[],char apellido[],char cuil[])
{
	eClientes nuevoCliente;

	nuevoCliente.idCliente=idCliente;
	strcpy(nuevoCliente.nombre,nombre);
	strcpy(nuevoCliente.apellido,apellido);
	strcpy(nuevoCliente.cuil,cuil);
	nuevoCliente.isEmpty=0;

return nuevoCliente;
}





void mostrarCliente_Prestamo(eClientes pArrayClientes, int qPrestamos)
{

	printf("%d\t%s\t%s\t\t%s\t\t%d\n",pArrayClientes.idCliente, pArrayClientes.nombre,pArrayClientes.apellido,pArrayClientes.cuil,qPrestamos);

}


int buscaCuil_IdCliente(eClientes* pArrayClientes,int tamArrayClientes, int idCliente, char cuil[])
{
	int i;
	int ret=0;
	if(pArrayClientes!=NULL && tamArrayClientes>0 && idCliente>=0 && cuil!=NULL)
	{
		for(i=0; i<tamArrayClientes; i++)
		{
			if(pArrayClientes[i].isEmpty==0 && pArrayClientes[i].idCliente==idCliente)
			{
				strcpy(cuil,pArrayClientes[i].cuil);
				ret=1;
				break;
			}
		}
	}

return ret;
}


int modificarCliente(eClientes* pArrayClientes,int tamArrayClientes, int limCliente)
{
	int indice=-1;
	int valorBuscado;
	char respuesta;
	eClientes auxCliente;
	int ret=0;
	int opcion;

	system("CLS()");
	printf("*****Modificar Musico*****\n\n");
	if(pArrayClientes!=NULL && tamArrayClientes>0)
	{


		mostrarClientes(pArrayClientes,tamArrayClientes);
		printf("\n\n");
		if(utn_getNumero(&valorBuscado,"Ingrese el Id del cliente que desea modificar \n","Error verifique los datos ingresados quedan %d intentos\n",0,(limCliente-1),3))
		{

			indice=buscarPosCliente_ID(pArrayClientes,valorBuscado,tamArrayClientes);
		}


		if(indice==-1)
		{
			printf("No se encontro el cliente para el id ingresado\n");
			system("PAUSE()");
		}
		else
		{

			printf("\n\n\n");
			printf("ID Cliente\tNombre\tApellido\tCUIL\n");
			mostrarCliente(pArrayClientes[indice]);

			printf("\n\n");


			opcion=opcionesModificacion();
			if(modiCliente(pArrayClientes[indice],opcion,&auxCliente))
			{

				utn_getCaracter(&respuesta,"Confirma la modificacion (s-n)\n","Error, verifique la respuesta ingresada\n","sn\0",3);

			}

			if(respuesta=='s')
			{
				pArrayClientes[indice]=auxCliente;
				printf("Se modifico el Cliente\n");
				ret=1;
			}

		}
	}

return ret;
}

int buscarPosCliente_ID(eClientes* pArrayClientes,int valorBuscado, int tamArrayClientes)
{
int indice=-1;
int i;
if(pArrayClientes!=NULL && tamArrayClientes>0 && valorBuscado>=0)
{

	for(i=0;i<tamArrayClientes;i++)
	{
		if (pArrayClientes[i].isEmpty==0 && pArrayClientes[i].idCliente==valorBuscado)
		{
			indice=i;
			break;
		}

	}

}
return indice;
}

static int modiCliente(eClientes clienteRec ,int opcion, eClientes* auxCliente)
{
	eClientes modifCliente;
	int ret=0;
	char bufferNombre[20];
	char bufferApellido[20];
	char bufferCuil[15];


	modifCliente=clienteRec;

	switch(opcion)
	{
		case 1:
				{
					if(utn_getTexto(bufferNombre,"Ingrese el nuevo nombre del cliente\n","Error verifique los datos ingresados quedan %d intentos\n",3,50))
					{
						strcpy(modifCliente.nombre,bufferNombre);
						*auxCliente=modifCliente;
						ret=1;
					}
					else
					{
						printf("No se pudo modificar el nombre\n");
						system("PAUSE()");
					}

					break;
				}
		case 2:
				{

					if(utn_getTexto(bufferApellido,"Ingrese el nuevo apellido del cliente\n","Error verifique los datos ingresados quedan %d intentos\n",3,50))
					{
						strcpy(modifCliente.apellido,bufferApellido);
						*auxCliente=modifCliente;
						ret=1;
					}
					else
					{
						printf("No se pudo modificar el apellido\n");
						system("PAUSE()");
					}

					break;
				}
		case 3:
				{
					if(utn_getCuil(bufferCuil,"Ingrese el CUIL del cliente (00-00000000-0) del cliente\n","Error verifique los datos ingresados quedan %d intentos\n",3,15))
					{
						strcpy(modifCliente.cuil,bufferCuil);
						*auxCliente=modifCliente;
						ret=1;
					}
					else
					{
						printf("No se pudo modificar el CUIL\n");
						system("PAUSE()");
					}

				break;
				}

		default:
				{
					break;
				}
	}

return ret;
}





static int opcionesModificacion()
{
	int opcion=0;
	printf("*****Opciones de Modificacion*****\n\n");

	printf("1-Nombre\n");
	printf("2-Apellido\n");
	printf("3-CUIL\n");
	printf("0-Salir\n");

	if(!(utn_getNumero(&opcion,"Elija un opcion: \n","Error verifique los datos ingresados quedan %d intentos\n",0,3,3)))
	{
		printf("No se reconocio el ingreso, supero el maximo de posibilidades\n");
		system("PAUSE()");
	}

return opcion;
}


void mostrarClientes(eClientes* pArrayClientes, int tamArrayClientes)
{
	int i;
	int flag=0;
	printf("ID Cliente\tNombre\tApellido\tCUIL\n");

	if(pArrayClientes!=NULL && tamArrayClientes>=0 )
		{
			for(i=0;i<tamArrayClientes;i++)
			{
				if(pArrayClientes[i].isEmpty==0)
				{
					mostrarCliente(pArrayClientes[i]);
					flag=1;
				}
			}

			if(flag==0)
			{
				system("CLS()");
				printf("\n---No hay clientes que mostrar---\n\n");
			}
		}

}

void mostrarCliente(eClientes pArraysClientes)
{


		printf("%d\t\t%s\t%s\t\t%s\n",pArraysClientes.idCliente,pArraysClientes.nombre,pArraysClientes.apellido,pArraysClientes.cuil);


}

int bajaCliente(eClientes* pArrayClientes, int tamArrayClientes, int* IdBaja, int limCliente)
{
	int indice=-1;
	int valorBuscado;
	char respuesta;
	int ret=0;

	system("CLS()");
	printf("*****Baja Cliente*****\n\n");
	if(pArrayClientes!=NULL && tamArrayClientes>0)
	{


		mostrarClientes(pArrayClientes,tamArrayClientes);
		printf("\n\n");

		if(utn_getNumero(&valorBuscado,"Ingrese el ID del cliente a dar de baja \n","Error verifique los datos ingresados quedan %d intentos\n",0,(limCliente-1),3))
		{
		indice=buscarPosCliente_ID(pArrayClientes,valorBuscado,tamArrayClientes);
		}

		if(indice==-1)
		{
			printf("No se encontro cliente para el ID ingresado\n");

		}
		else
		{

			printf("\n\n\n");
			printf("ID Cliente\tNombre\tApellido\tCUIL\n");
			mostrarCliente(pArrayClientes[indice]);
			printf("\n\n");

			utn_getCaracter(&respuesta,"Confirma la baja (s-n)\n","Error, verifique la respuesta ingresada\n","sn\0",3);


			if(respuesta=='s')
			{
				*IdBaja=pArrayClientes[indice].idCliente;
				pArrayClientes[indice].isEmpty=1;
				ret=1;
			}

		}
	}

return ret;
}

int cantidaDePosVaciasClientes(eClientes* pArrayPClientes, int tamArrayClientes)
{
int cont=0;
int i;

if(pArrayPClientes!=NULL && tamArrayClientes>0 )
{

	for(i=0;i<tamArrayClientes;i++)
	{
		if(pArrayPClientes[i].isEmpty==1)
		{
			cont++;
		}
	}
}
return cont;
}



