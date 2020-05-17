/*
 * prestamos.c
 *
 *  Created on: 15 may. 2020
 *      Author: aleja
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "clientes.h"
#include "prestamos.h"
#include "prestamocliente.h"
#include "utn.h"

static ePrestamos nuevoPrestamo(int idPrestamo,int idCliente,float importe, int cuotas);
static int buscarIndicePrestamo(ePrestamos* pArrayPrestamos, int tamArrayPrestamos);
static int buscarPosPrestamoSaldado_ID(ePrestamos* pArrayPrestamos,int valorBuscado, int tamArrayPrestamos);
static int buscarPosPrestamo_ID(ePrestamos* pArrayPrestamos,int valorBuscado, int tamArrayPrestamos);
static void mostrarPrestamoSaldado(ePrestamos pArrayPrestamos, eClientes* pArrayClientes,int tamArrayClientes);

void iniArrayPrestamos(ePrestamos* pArrayPrestamos,int tamArrayPrestamos,int valorInt)
{
	int i;

	if(pArrayPrestamos!=NULL && tamArrayPrestamos>0)
	{
		for(i = 0; i < tamArrayPrestamos; i++)
		{

			pArrayPrestamos[i].isEmpty=valorInt;

		}
	}

}

int hardcodearPrestamos(ePrestamos* pArrayPrestamos, int tamArrayPrestamos, int cantidad)
{

	int cont=0;
	int i;
	if(pArrayPrestamos!=NULL && tamArrayPrestamos>0 && cantidad >0)
	{
		ePrestamos listaAuxiliar[]=
		{
		//id prestamo, importe, cuotas, id cliente, isempty

			{0,50000.50,12,0,0},
			{1,95000.00,18,0,0},
			{2,40500.30,6,0,0},
			{3,58000.80,9,1,0},
			{4,10500.00,12,0,0},
			{5,50560.50,36,0,0},
			{6,200590.00,18,0,0},
			{7,5500.10,3,0,0},
			{8,9500.00,3,0,0},
			{9,105569.50,12,0,0},


		};


		if (cantidad <=tamArrayPrestamos && cantidad <11)
		{
			for(i=0; i<cantidad; i++)
			{
				pArrayPrestamos[i]=listaAuxiliar[i];
				cont++;
			}
		}
	}

return cont;
}


int altaPrestamo(ePrestamos* pArrayPrestamos,int tamArrayPrestamos, int idPrestamo,eClientes* pArrayClientes,int tamArrayClientes,ePrestamoCliente* pArrayPrestamoClientes,int tamArrayPrestamoClientes, int idPrestamoCliente, int limCliente,int* posAlta)
{
	int indice;
	int ret=0;
	float importe;
	int cuotas;
	int idCliente;

			system("CLS()");
			printf("*****Alta Prestamo*****\n\n");
	if(pArrayPrestamos!=NULL && tamArrayPrestamos>=0 && idPrestamo>=0 && pArrayClientes!=NULL && tamArrayClientes>0 &&  pArrayPrestamoClientes!=NULL && tamArrayPrestamoClientes>0 && idPrestamoCliente>=0)
	{
			indice=buscarIndicePrestamo(pArrayPrestamos,tamArrayPrestamos);

			if(indice==-1)
			{
				printf("Sistema completo, no se puede agregar mas Prestamos\n\n");
				system("PAUSE()");
			}
			else
			{
				printf("\n\n");
				mostrarClientesPrestamos(pArrayClientes,tamArrayClientes,pArrayPrestamoClientes,tamArrayPrestamoClientes);
				printf("\n");
				if(utn_getNumero(&idCliente,"Ingrese el ID del cliente para el prestamo\n","Error verifique los datos ingresados quedan %d intentos\n",0,(limCliente-1),3))
				{
					fflush(stdin);
					if(utn_getNumeroConDecimales(&importe,"Ingrese el importe del prestamo\n","Error verifique los datos ingresados quedan %d intentos\n",1,9999999,3))
					{
						fflush(stdin);
						if(utn_getNumero(&cuotas,"Ingrese la cantidad de cuotas\n","Error verifique los datos ingresados quedan %d intentos\n",1,62,3))
						{
							pArrayPrestamos[indice]=nuevoPrestamo(idPrestamo,idCliente,importe,cuotas);
							altaPrestamoCliente( pArrayPrestamoClientes,tamArrayPrestamoClientes,idPrestamoCliente,idPrestamo,idCliente);
							*posAlta=indice;
							ret=1;
						}
					}
				}
			}
	}

return ret;

}


static int buscarIndicePrestamo(ePrestamos* pArrayPrestamos, int tamArrayPrestamos)
{
int indice=-1;
int i;

if(pArrayPrestamos!=NULL && tamArrayPrestamos>0 )
{

	for(i=0;i<tamArrayPrestamos;i++)
	{
		if(pArrayPrestamos[i].isEmpty==1)
		{
			indice=i;
			break;
		}
	}
}

return indice;
}



static ePrestamos nuevoPrestamo(int idPrestamo,int idCliente,float importe, int cuotas)
{
	ePrestamos nuevoPrestamo;

	nuevoPrestamo.idPrestamo=idPrestamo;
	nuevoPrestamo.idCliente=idCliente;
	nuevoPrestamo.importe=importe;
	nuevoPrestamo.cuotas=cuotas;
	nuevoPrestamo.isEmpty=0;

return nuevoPrestamo;
}


void mostrarPrestamos(ePrestamos* pArrayPrestamos,int tamArrayPrestamos,eClientes* pArrayClientes, int tamArrayClientes)
{
	int i;
	int flag=0;
	printf("ID Prestamo\tImporte\t\tCuotas\tCUIL Cliente\n");

	if(pArrayClientes!=NULL && tamArrayClientes>=0 && pArrayPrestamos!=NULL && tamArrayPrestamos>0)
		{
			for(i=0;i<tamArrayPrestamos;i++)
			{
				if(pArrayPrestamos[i].isEmpty==0)
				{
					mostrarPrestamo(pArrayPrestamos[i],pArrayClientes,tamArrayClientes);
					flag=1;
				}
			}

			if(flag==0)
			{
				system("CLS()");
				printf("\n---No hay prestamos que mostrar---\n\n");
				system("PAUSE()");
			}
		}

}

void mostrarPrestamo(ePrestamos pArrayPrestamos, eClientes* pArrayClientes,int tamArrayClientes)
{
	char cuil[15];
	if(buscaCuil_IdCliente(pArrayClientes,tamArrayClientes,pArrayPrestamos.idCliente,cuil))
	{
		printf("%d\t\t%.2f\t%d\t%s\n",pArrayPrestamos.idPrestamo, pArrayPrestamos.importe, pArrayPrestamos.cuotas,cuil);
	}

}

void bajaPrestamoPorIdCliente(ePrestamos* pArrayPrestamos,int tamArrayPrestamos,ePrestamoCliente* pArrayPrestamoClientes,int tamArrayPrestamoClientes,int idClienteBaja)
{
	int i;
	if (pArrayPrestamos!=NULL && tamArrayPrestamos>0 && pArrayPrestamoClientes!=NULL && tamArrayPrestamoClientes>=0 && idClienteBaja>=0 )
	{
		for(i=0;i<tamArrayPrestamos;i++)
			{
				if ((pArrayPrestamos[i].isEmpty==0 || pArrayPrestamos[i].isEmpty==-1) &&pArrayPrestamos[i].idCliente==idClienteBaja)
				{
					pArrayPrestamos[i].isEmpty=1;
				}

			}
		bajaPrestamoYcliente(pArrayPrestamoClientes,tamArrayPrestamoClientes,idClienteBaja);
	}

}


int saldarPrestamo(ePrestamos* pArrayPrestamos, int tamArrayPrestamos,eClientes* pArrayClientes, int tamArrayClientes,ePrestamoCliente* pArrayPrestamoClientes,int tamArrayPrestamoClientes,int limPrestamos)
{
	int indice=-1;
	int posCliente;
	int valorBuscado;
	char respuesta;
	int ret=0;

	system("CLS()");
	printf("*****Saldar Prestamos*****\n\n");
	if(pArrayPrestamos!=NULL && tamArrayPrestamos>0 && pArrayClientes!=NULL && tamArrayClientes>0 && pArrayPrestamoClientes!=NULL && tamArrayPrestamoClientes>0)
	{


		mostrarPrestamos(pArrayPrestamos,tamArrayPrestamos,pArrayClientes,tamArrayClientes);
		printf("\n\n");

		if(utn_getNumero(&valorBuscado,"Ingrese el ID del prestamos a saldar \n","Error verifique los datos ingresados quedan %d intentos\n",0,(limPrestamos-1),3))
		{
		indice=buscarPosPrestamo_ID(pArrayPrestamos,valorBuscado,tamArrayPrestamos);
		}

		if(indice==-1)
		{
			printf("No se encontro prestamo para el ID ingresado\n");
			system("PAUSE()");

		}
		else
		{
			posCliente=buscarPosCliente_ID(pArrayClientes,pArrayPrestamos[indice].idCliente,tamArrayClientes);
			printf("\n\n\n");
			printf("ID Cliente\tNombre\tApellido\tCUIL\n");
			mostrarCliente(pArrayClientes[posCliente]);
			printf("\n\n");

			utn_getCaracter(&respuesta,"Confirma la cancelacion del prestamo (s-n)\n","Error, verifique la respuesta ingresada\n","sn\0",3);


			if(respuesta=='s')
			{
				prestamoSaldado(pArrayPrestamoClientes,tamArrayPrestamoClientes,pArrayPrestamos[indice].idPrestamo);
				 pArrayPrestamos[indice].isEmpty=-1;
				ret=1;
			}

		}
	}

return ret;
}

static int buscarPosPrestamo_ID(ePrestamos* pArrayPrestamos,int valorBuscado, int tamArrayPrestamos)
{
int indice=-1;
int i;
if(pArrayPrestamos!=NULL && tamArrayPrestamos>0 && valorBuscado>=0)
{

	for(i=0;i<tamArrayPrestamos;i++)
	{
		if (pArrayPrestamos[i].isEmpty==0 && pArrayPrestamos[i].idPrestamo==valorBuscado)
		{
			indice=i;
			break;
		}

	}

}
return indice;
}


int mostrarPrestamosSaldados(ePrestamos* pArrayPrestamos,int tamArrayPrestamos,eClientes* pArrayClientes, int tamArrayClientes)
{
	int i;
	int flag=0;
	printf("ID Prestamo\tImporte\t\tCuotas\tCUIL Cliente\n");

	if(pArrayClientes!=NULL && tamArrayClientes>=0 && pArrayPrestamos!=NULL && tamArrayPrestamos>0)
		{
			for(i=0;i<tamArrayPrestamos;i++)
			{
				if(pArrayPrestamos[i].isEmpty==-1)
				{
					mostrarPrestamoSaldado(pArrayPrestamos[i],pArrayClientes,tamArrayClientes);
					flag=1;
				}
			}

			if(flag==0)
			{
				system("CLS()");
				printf("\n---No hay prestamos que mostrar---\n\n");

			}
		}
return flag;
}

static void mostrarPrestamoSaldado(ePrestamos pArrayPrestamos, eClientes* pArrayClientes,int tamArrayClientes)
{
	char cuil[15];
	if(buscaCuil_IdCliente(pArrayClientes,tamArrayClientes,pArrayPrestamos.idCliente,cuil))
	{
		printf("%d\t\t%.2f\t%d\t%s\n",pArrayPrestamos.idPrestamo, pArrayPrestamos.importe, pArrayPrestamos.cuotas,cuil);
	}

}

int reanudarPrestamo(ePrestamos* pArrayPrestamos, int tamArrayPrestamos,eClientes* pArrayClientes, int tamArrayClientes,ePrestamoCliente* pArrayPrestamoClientes,int tamArrayPrestamoClientes,int limPrestamos)
{
	int indice=-1;
	int posCliente;
	int valorBuscado;
	char respuesta;
	int ret=0;

	system("CLS()");
	printf("*****Reanudar Prestamos*****\n\n");
	if(pArrayPrestamos!=NULL && tamArrayPrestamos>0 && pArrayClientes!=NULL && tamArrayClientes>0 && pArrayPrestamoClientes!=NULL && tamArrayPrestamoClientes>0)
	{
		if(mostrarPrestamosSaldados(pArrayPrestamos,tamArrayPrestamos,pArrayClientes,tamArrayClientes))
		{
			printf("\n\n");

			if(utn_getNumero(&valorBuscado,"Ingrese el ID del prestamos a saldar \n","Error verifique los datos ingresados quedan %d intentos\n",0,(limPrestamos-1),3))
			{
				indice=buscarPosPrestamoSaldado_ID(pArrayPrestamos,valorBuscado,tamArrayPrestamos);
			}

			if(indice==-1)
			{
				printf("No se encontro prestamo para el ID ingresado\n");
				system("PAUSE()");

			}
			else
			{
				posCliente=buscarPosCliente_ID(pArrayClientes,pArrayPrestamos[indice].idCliente,tamArrayClientes);
				printf("\n\n\n");
				printf("ID Cliente\tNombre\tApellido\tCUIL\n");
				mostrarCliente(pArrayClientes[posCliente]);
				printf("\n\n");
				utn_getCaracter(&respuesta,"Confirma la baja (s-n)\n","Error, verifique la respuesta ingresada\n","sn\0",3);
				if(respuesta=='s')
				{
					activoPrestamo(pArrayPrestamoClientes,tamArrayPrestamoClientes,pArrayPrestamos[indice].idPrestamo);
					pArrayPrestamos[indice].isEmpty=0;
					ret=1;
				}
			}
		}
		else
		{
			printf("No se encontro prestamo que reanudar\n");

		}
	}

return ret;
}

static int buscarPosPrestamoSaldado_ID(ePrestamos* pArrayPrestamos,int valorBuscado, int tamArrayPrestamos)
{
int indice=-1;
int i;
if(pArrayPrestamos!=NULL && tamArrayPrestamos>0 && valorBuscado>=0)
{

	for(i=0;i<tamArrayPrestamos;i++)
	{
		if (pArrayPrestamos[i].isEmpty==-1 && pArrayPrestamos[i].idPrestamo==valorBuscado)
		{
			indice=i;
			break;
		}

	}

}
return indice;
}

int cantidaDePosVaciasPrestamos(ePrestamos* pArrayPrestamos, int tamArrayPrestamos)
{
int cont=0;
int i;

if(pArrayPrestamos!=NULL && tamArrayPrestamos>0 )
{

	for(i=0;i<tamArrayPrestamos;i++)
	{
		if(pArrayPrestamos[i].isEmpty==1)
		{
			cont++;
		}
	}
}
return cont;
}
