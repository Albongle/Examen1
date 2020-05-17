/*
 * informes.c
 *
 *  Created on: 15 may. 2020
 *      Author: aleja
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "clientes.h"
#include "prestamos.h"
#include "prestamocliente.h"

void clienteMasPrestamosActivos(eClientes* pArrayClientes, int tamArrayClientes,ePrestamoCliente* pArrayPrestamoClientes,int tamArrayPrestamoClientes)
{
	int i;
	int maxPrestamos;
	int cantidad;
	int posCliente;
	int flag=0;

	if(pArrayClientes!=NULL && tamArrayClientes>0 && pArrayPrestamoClientes!=NULL && tamArrayPrestamoClientes>0)
	{
		for(i=0; i<tamArrayClientes; i++)
		{
			if(pArrayClientes[i].isEmpty==0)
			{
				cantidad=cantidadPrestamosActivosCliente(pArrayPrestamoClientes,tamArrayPrestamoClientes,pArrayClientes[i].idCliente);

				if(flag==0 || cantidad>maxPrestamos)
				{
					maxPrestamos=cantidad;
					posCliente=i;
					flag=1;
				}
			}
		}
	}

	if(maxPrestamos>0)
	{
	printf("----El cliente con mas prestamos activos es----\n\n\n");
	printf("ID\tNombre\tApellido\tCuil\t\tCantidad de Prestamos\n");
	mostrarCliente_Prestamo(pArrayClientes[posCliente],maxPrestamos);
	}
	else
	{
		printf("----No se encontro cliente con prestamos activos----\n\n\n");
	}


}


void clienteMasPrestamosSaldados(eClientes* pArrayClientes, int tamArrayClientes,ePrestamoCliente* pArrayPrestamoClientes,int tamArrayPrestamoClientes)
{
	int i;
	int maxPrestamos;
	int cantidad;
	int posCliente;
	int flag=0;

	if(pArrayClientes!=NULL && tamArrayClientes>0 && pArrayPrestamoClientes!=NULL && tamArrayPrestamoClientes>0)
	{
		for(i=0; i<tamArrayClientes; i++)
		{
			if(pArrayClientes[i].isEmpty==0)
			{
				cantidad=cantidadPrestamosSaldadosCliente(pArrayPrestamoClientes,tamArrayPrestamoClientes,pArrayClientes[i].idCliente);
				fflush(stdin);
				if(flag==0 || cantidad>maxPrestamos)
				{
					maxPrestamos=cantidad;
					posCliente=i;
					flag=1;
				}
			}
		}
	}
	if(maxPrestamos>0)
	{
	printf("----El cliente con mas prestamos Saldados es es----\n\n\n");
	printf("ID\tNombre\tApellido\tCuil\t\tCantidad de Prestamos\n");
	mostrarCliente_Prestamo(pArrayClientes[posCliente],maxPrestamos);
	}
	else
	{
		printf("----No se encontro cliente con prestamos saldados----\n\n\n");
	}

}

void prestamosImporteMayor(ePrestamos* pArrayPrestamos,int tamArrayPrestamos)
{
	int i;
	float importe;
	int cont=0;
	if(pArrayPrestamos!=NULL && tamArrayPrestamos>0)
	{
		if(utn_getNumeroConDecimales(&importe,"Ingrese el importe del prestamo (debe ser mayor a 1000)\n","Error verifique los datos ingresados quedan %d intentos\n",1000,9999999,3))
		{
			for(i=0; i<tamArrayPrestamos; i++)
			{
				if(pArrayPrestamos[i].isEmpty==0 && pArrayPrestamos[i].importe==importe)
				{
					cont++;
				}
			}


			if(cont>0)
			{

				printf("----Existen [%d] prestamos con el importe ingresado----\n", cont);
			}
			else
			{
				printf("----No se encontraron prestamos con el importe ingresado----");
			}

		}
		else
		{
			printf("----Se cancelo la comprobacion----\n\n\n");

		}
	}


}


