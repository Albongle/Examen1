/*
 * prestamocliente.c
 *
 *  Created on: 15 may. 2020
 *      Author: aleja
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "clientes.h"
#include "prestamocliente.h"





void iniArrayPrestamoClientes(ePrestamoCliente* pArrayPrestamoClientes,int tamArrayPrestamoCLientes,int valorInt)
{
	int i;

	if(pArrayPrestamoClientes!=NULL && tamArrayPrestamoCLientes>0)
	{
		for(i=0; i<tamArrayPrestamoCLientes; i++)
		{

			pArrayPrestamoClientes[i].isEmpty=valorInt;

		}
	}

}

int hardcodearPrestamoClientes(ePrestamoCliente* pArrayPrestamoClientes, int tamArrayPrestamoCLientes, int cantidad)
{

	int cont=0;
	int i;
	if(pArrayPrestamoClientes!=NULL && tamArrayPrestamoCLientes>0 && cantidad >0)
	{
		ePrestamoCliente listaAuxiliar[]=
		{
				//id prestamoC, id prestammo. id cliente, isempty
				{0,0,0,0},
				{1,1,0,0},
				{2,2,0,0},
				{3,3,1,0},
				{4,4,0,0},
				{5,5,0,0},
				{6,6,0,0},
				{7,7,0,0},
				{8,8,0,0},
				{9,9,0,0},

		};


		if (cantidad <=tamArrayPrestamoCLientes && cantidad <11)
		{
			for(i=0; i<cantidad; i++)
			{
				pArrayPrestamoClientes[i]=listaAuxiliar[i];
				cont++;
			}
		}
	}

return cont;
}

void altaPrestamoCliente(ePrestamoCliente* pArrayPrestamoClientes,int tamArrayPrestamoClientes,int idPrestamoCliente, int idPrestamo, int idCliente)
{

	if(pArrayPrestamoClientes!=NULL && idPrestamoCliente<=tamArrayPrestamoClientes)
	{
		pArrayPrestamoClientes[idPrestamoCliente].id=idPrestamoCliente;
		pArrayPrestamoClientes[idPrestamoCliente].idCliente=idCliente;
		pArrayPrestamoClientes[idPrestamoCliente].idPrestamo=idPrestamo;
		pArrayPrestamoClientes[idPrestamoCliente].isEmpty=0;
	}

}




void mostrarClientesPrestamos(eClientes* pArrayClientes, int tamArrayClientes, ePrestamoCliente* pArrayPrestamoClientes,int tamArrayPrestamoClientes)
{
	int i;
	int flag=0;
	printf("ID\tNombre\tApellido\tCuil\t\tCantidad de Prestamos\n");

	if(pArrayClientes!=NULL && tamArrayClientes>=0 && pArrayPrestamoClientes!=NULL && tamArrayPrestamoClientes>0)
		{
			for(i=0;i<tamArrayClientes;i++)
			{
				if(pArrayClientes[i].isEmpty==0)
				{
					mostrarClientePrestamo(pArrayClientes[i],pArrayPrestamoClientes,tamArrayPrestamoClientes);
					flag=1;
				}
			}

			if(flag==0)
			{
				system("CLS()");
				printf("\n---No hay Clientes que mostrar---\n\n");
				system("PAUSE()");
			}
		}

}

void mostrarClientePrestamo(eClientes pArrayClientes, ePrestamoCliente* pArrayPrestamoClientes,int tamArrayPrestamoClientes)
{
	int qPrestamos=0;
	qPrestamos=cantidadPrestamosActivosCliente(pArrayPrestamoClientes,tamArrayPrestamoClientes,pArrayClientes.idCliente);
	mostrarCliente_Prestamo(pArrayClientes,qPrestamos);

}



int cantidadPrestamosActivosCliente(ePrestamoCliente* pArrayPrestamoClientes,int tamArrayPrestamoClientes, int idCliente)
{
	int cantidad=0;
	int i;
	if(pArrayPrestamoClientes!=NULL && tamArrayPrestamoClientes>0 && idCliente>=0)
	{
		for(i=0; i<tamArrayPrestamoClientes; i++)
		{
			if(pArrayPrestamoClientes[i].isEmpty==0 && pArrayPrestamoClientes[i].idCliente==idCliente)
			{
				cantidad++;
			}

		}
	}

return cantidad;
}
int cantidadPrestamosSaldadosCliente(ePrestamoCliente* pArrayPrestamoClientes,int tamArrayPrestamoClientes, int idCliente)
{
	int cantidad=0;
	int i;
	if(pArrayPrestamoClientes!=NULL && tamArrayPrestamoClientes>0 && idCliente>=0)
	{
		for(i=0; i<tamArrayPrestamoClientes; i++)
		{
			if(pArrayPrestamoClientes[i].isEmpty==-1 && pArrayPrestamoClientes[i].idCliente==idCliente)
			{
				cantidad++;
			}

		}
	}

	return cantidad;
}

void bajaPrestamoYcliente(ePrestamoCliente* pArrayPrestamoClientes,int tamArrayPrestamoClientes,int idClienteBaja)
{
	int i;
	if (pArrayPrestamoClientes!=NULL && tamArrayPrestamoClientes>=0 && idClienteBaja>=0 )
	{
		for(i=0;i<tamArrayPrestamoClientes;i++)
			{
				if ((pArrayPrestamoClientes[i].isEmpty==0 || pArrayPrestamoClientes[i].isEmpty==-1) && pArrayPrestamoClientes[i].idCliente==idClienteBaja)
				{
					pArrayPrestamoClientes[i].isEmpty=1;
				}

			}
	}

}

void prestamoSaldado(ePrestamoCliente* pArrayPrestamoClientes,int tamArrayPrestamoClientes,int idPrestamo)
{
	int i;
	if (pArrayPrestamoClientes!=NULL && tamArrayPrestamoClientes>=0 && idPrestamo>=0 )
	{
		for(i=0;i<tamArrayPrestamoClientes;i++)
			{
				if (pArrayPrestamoClientes[i].isEmpty==0 && pArrayPrestamoClientes[i].idPrestamo==idPrestamo)
				{
					pArrayPrestamoClientes[i].isEmpty=-1;
				}

			}
	}

}

void activoPrestamo(ePrestamoCliente* pArrayPrestamoClientes,int tamArrayPrestamoClientes,int idPrestamo)
{
	int i;
	if (pArrayPrestamoClientes!=NULL && tamArrayPrestamoClientes>=0 && idPrestamo>=0 )
	{
		for(i=0;i<tamArrayPrestamoClientes;i++)
			{
				if (pArrayPrestamoClientes[i].isEmpty==-1 && pArrayPrestamoClientes[i].idPrestamo==idPrestamo)
				{
					pArrayPrestamoClientes[i].isEmpty=0;
				}

			}
	}

}




