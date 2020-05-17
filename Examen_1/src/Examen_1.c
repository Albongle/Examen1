/*
 =============================================================================================================================================================================================================
 Name        : Examen_1.c
 Author      : Alejandro Bongioanni
 Version     :
 Copyright   : Your copyright notice
 Description : Examen_1 C, Ansi-style
1) Alta de cliente: Se da de alta un cliente con nombre, apellido, y c.u.i.l. Se generará un ID único para este cliente que se imprimirá por pantalla si el alta es correcta.
2) Modificar datos de cliente: Se ingresa el ID de cliente y se permitirá cambiar el nombre, el apellido y el c.u.i.l.
3) Baja de cliente: Se ingresa el ID del cliente y se listarán todos los préstamos de dicho cliente. Luego se preguntará si se quiere confirmar la eliminación,
	la cual implicará la eliminación de todos los préstamos y del cliente.
4) Préstamo: Permitirá crear un nuevo préstamo. Se pedirán los siguientes datos: ID de cliente, importe, cantidad de cuotas.
	Se generará automáticamente un identificador numérico para el préstamo y se imprimirá en pantalla.
5) Saldar préstamo: Se pedirá el ID del préstamo y se imprimirá la información del cliente al que pertenece, luego se pedirá confirmación para cambiarse de estado y se cambiará al estado "saldado".
6) Reanudar préstamo: Se pedirá el ID del préstamo y se imprimirá la información del cliente al que pertenece, luego se pedirá confirmación para cambiarse de estado y se cambiará al estado "activo".
7) Imprimir Clientes: Se imprimirá una lista de clientes con todos sus datos junto con la cantidad de préstamos activos que posee.
8) Imprimir préstamos: Se imprimirá una lista de préstamos activos con todos sus datos junto con el c.u.i.l. del cliente correspondiente.
9) Informar clientes:
a) Cliente con más préstamos activos.
b) Cliente con más préstamos saldados.
10) Informar préstamos:
a) Cantidad de préstamos de importe mayor a 1000: Se ingresará el importe y se imprimirá la cantidad de préstamos activos con ese importe.

Nota 0: El sistema soportará una capacidad máxima de 50 clientes y 50 préstamos
Nota 1: Se deberán desarrollar bibliotecas por cada entidad las cuales contendrán las funciones (Alta, Baja, Modificar, etc.). Los informes deberán estar en una biblioteca aparte.
Nota 2: El código deberá tener comentarios con la documentación de cada una de las funciones y respetar las reglas de estilo de la cátedra.
 ===========================================================================================================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "clientes.h"
#include "prestamos.h"
#include "prestamocliente.h"
#include "informes.h"
#define Q_CLIENTES 50
#define Q_PRESTAMOS 50
#define Q_PRESTAMOS_CLIENTES 50




int menu();
int subMenuInformes_clientes();
int subMenuInformes_prestamos();
int main(void)
{
	system("COLOR E");
	setbuf(stdout, NULL);
	int opcionMenu;
	int opcionMenuCL;
	int opcionMenuPR;
	int idCliente=0;
	int idPrestamo=0;
	int idPrestamoCliente=0;
	int idClienteBaja;
	int posCliente;
	int posPrestamo;

	eClientes arrayClientes[Q_CLIENTES];
	ePrestamos arrayPrestamos[Q_PRESTAMOS];
	ePrestamoCliente arrayPrestamoCliente[Q_PRESTAMOS_CLIENTES];

	iniArrayClientes(arrayClientes,Q_CLIENTES,1);
	iniArrayPrestamos(arrayPrestamos,Q_PRESTAMOS,1);
	iniArrayPrestamoClientes(arrayPrestamoCliente,Q_PRESTAMOS,1);

	/*
	////===============================================================================================================
									//Harcodeo de arrays
	idCliente=idCliente+hardcodearClientes(arrayClientes,Q_CLIENTES,5);
	idPrestamo=idPrestamo+hardcodearPrestamos(arrayPrestamos,Q_PRESTAMOS,5);
	idPrestamoCliente=idPrestamoCliente+hardcodearPrestamoClientes(arrayPrestamoCliente,Q_PRESTAMOS_CLIENTES,5);


	////===============================================================================================================
	 */
	do
			{
				system("CLS()");
				opcionMenu=menu();
				switch (opcionMenu)
				{
					case 1:
					{
						if(altaCliente(arrayClientes,Q_CLIENTES,idCliente,&posCliente))
						{
							printf("\n\n\n----Se dio de alta el cliente----\n\n\n");
							printf("ID Cliente\tNombre\tApellido\tCUIL\n");
							mostrarCliente(arrayClientes[posCliente]);
							idCliente++;

							system("PAUSE()");
						}
						else
						{
							printf("Se cancelo el alta\n");
							system("PAUSE()");

						}
						break;
					}
					case 2:
					{

						if(cantidaDePosVaciasClientes(arrayClientes,Q_CLIENTES)==Q_CLIENTES)
						{
							printf("El sistema aun no posee clientes\n");
							system("PAUSE()");
						}
						else
						{


							if(!(modificarCliente(arrayClientes,Q_CLIENTES,idCliente)))
							{
								printf("Se cancelo la modificacion\n");
								system("PAUSE()");
							}
						}
						break;
					}
					case 3:
					{
						if(cantidaDePosVaciasClientes(arrayClientes,Q_CLIENTES)==Q_CLIENTES)
						{
							printf("El sistema aun no posee clientes\n");
							system("PAUSE()");
						}
						else
						{
							if(!(bajaCliente(arrayClientes,Q_CLIENTES,&idClienteBaja,idCliente)))
							{
								printf("Se cancelo la baja\n");
								system("PAUSE()");
							}
							else
							{

								bajaPrestamoPorIdCliente(arrayPrestamos,Q_PRESTAMOS,arrayPrestamoCliente,Q_PRESTAMOS_CLIENTES,idClienteBaja);
								printf("Se elimino el cliente y sus prestamos\n");
								system("PAUSE()");
							}
						}
						break;
					}

					case 4:
					{
						if(cantidaDePosVaciasClientes(arrayClientes,Q_CLIENTES)==Q_CLIENTES)
						{
							printf("El sistema aun no posee clientes\n");
							system("PAUSE()");
						}
						else
						{
							if(altaPrestamo(arrayPrestamos,Q_PRESTAMOS,idPrestamo,arrayClientes,Q_CLIENTES,arrayPrestamoCliente,Q_PRESTAMOS_CLIENTES,idPrestamoCliente,idCliente,&posPrestamo))
							{
								printf("\n\n\n----Se dio de alta el prestamo---\n\n\n");
								printf("ID Prestamo\tImporte\t\tCuotas\tCUIL Cliente\n");
								mostrarPrestamo(arrayPrestamos[posPrestamo],arrayClientes,Q_CLIENTES);
								idPrestamo++;
								idPrestamoCliente++;
								system("PAUSE()");

							}
							else
							{
								printf("Se cancelo el alta\n");
								system("PAUSE()");
							}
						}

						break;
					}

					case 5:
					{
						if(cantidaDePosVaciasPrestamos(arrayPrestamos,Q_PRESTAMOS)==Q_PRESTAMOS)
						{
							printf("El sistema aun no posee prestamos activos\n");
							system("PAUSE()");
						}
						else
						{

							if(!(saldarPrestamo(arrayPrestamos,Q_PRESTAMOS,arrayClientes,Q_CLIENTES,arrayPrestamoCliente,Q_PRESTAMOS_CLIENTES,idPrestamo)))
							{
								printf("Se cancelo la accion \n");
								system("PAUSE()");
							}
						}

						break;
					}

					case 6:
					{
						if(!(reanudarPrestamo(arrayPrestamos,Q_PRESTAMOS,arrayClientes,Q_CLIENTES,arrayPrestamoCliente,Q_PRESTAMOS_CLIENTES,idPrestamo)))
						{
							printf("Se cancelo la accion \n");
							system("PAUSE()");
						}

						break;
					}

					case 7:
					{
						if(cantidaDePosVaciasClientes(arrayClientes,Q_CLIENTES)==Q_CLIENTES)
						{
							printf("El sistema aun no posee clientes\n");
							system("PAUSE()");
						}
						else
						{
							printf("\n\n");
							mostrarClientesPrestamos(arrayClientes,Q_CLIENTES,arrayPrestamoCliente,Q_PRESTAMOS_CLIENTES);
							system("PAUSE()");
						}
						break;
					}
					case 8:
					{
						if(cantidaDePosVaciasPrestamos(arrayPrestamos,Q_PRESTAMOS)==Q_PRESTAMOS)
						{
							printf("El sistema aun no posee prestamos cargados\n");
							system("PAUSE()");
						}
						else
						{
							printf("\n\n");
							mostrarPrestamos(arrayPrestamos,Q_PRESTAMOS,arrayClientes,Q_CLIENTES);
							system("PAUSE()");
						}

						break;
					}
					case 9:
					{
						do
						{
							system("CLS()");
							opcionMenuCL=subMenuInformes_clientes();
							switch (opcionMenuCL)
											{
												case 1:
												{
													if(cantidaDePosVaciasClientes(arrayClientes,Q_CLIENTES)==Q_CLIENTES)
													{
														printf("El sistema aun no posee clientes\n");
														system("PAUSE()");
													}
													else
													{
														printf("\n\n");
														clienteMasPrestamosActivos(arrayClientes,Q_CLIENTES,arrayPrestamoCliente,Q_PRESTAMOS_CLIENTES);
														system("PAUSE()");
													}
													break;
												}

												case 2:
												{

													if(cantidaDePosVaciasClientes(arrayClientes,Q_CLIENTES)==Q_CLIENTES)
													{
														printf("El sistema aun no posee clientes\n");
														system("PAUSE()");
													}
													else
													{
														printf("\n\n");
														clienteMasPrestamosSaldados(arrayClientes,Q_CLIENTES,arrayPrestamoCliente,Q_PRESTAMOS_CLIENTES);
														system("PAUSE()");
													}
													break;
												}


											}


						}while(opcionMenuCL!=0);

						break;
					}
					case 10:
					{
						do
						{
							system("CLS()");
							opcionMenuPR=subMenuInformes_prestamos();
							switch (opcionMenuPR)
							{
								case 1:
								{
									if(cantidaDePosVaciasPrestamos(arrayPrestamos,Q_PRESTAMOS)==Q_PRESTAMOS)
									{
										printf("El sistema aun no posee prestamos cargados\n");
										system("PAUSE()");
									}
									else
									{
										prestamosImporteMayor(arrayPrestamos,Q_PRESTAMOS);
										system("PAUSE()");
									}

								break;
								}

							}

						}while(opcionMenuPR!=0);


						break;
					}

				}

			}while(opcionMenu!=0);

	system("PAUSE()");
	return EXIT_SUCCESS;
}




int menu()
{
	int opcion=-1;

	printf("Menu de opciones\n\n");
	printf("1-Alta de Cliente\n");
	printf("2-Modificar Cliente\n");
	printf("3-Baja Cliente\n");
	printf("4-Alta Prestamo\n");
	printf("5-Saldar Prestamo\n");
	printf("6-Reanudar Prestamo\n");
	printf("7-Imprimir Clientes\n");
	printf("8-Imprimir Prestamos\n");
	printf("9-Informar Clientes\n");
	printf("10-Informar Prestamos\n");
	printf("0-Salir\n");

	if(!(utn_getNumero(&opcion,"Elija un opcion: ","Error verifique los datos ingresados quedan %d intentos\n",0,10,3)))
	{
		printf("No se reconocio el ingreso, supero el maximo de posibilidades\n");
		system("PAUSE()");
	}



return opcion;
}

int subMenuInformes_clientes()
{
	int opcion=-1;

	printf("Menu de informes Cliente\n\n");
	printf("1-Cliente con mas prestamos activos\n");
	printf("2-Cliente con mas prestamos saldados\n");
	printf("0-Salir\n");

	if(!(utn_getNumero(&opcion,"Elija un opcion: ","Error verifique los datos ingresados quedan %d intentos\n",0,2,3)))
	{
		printf("No se reconocio el ingreso, supero el maximo de posibilidades\n");
		system("PAUSE()");
	}

return opcion;
}

int subMenuInformes_prestamos()
{
	int opcion=-1;

	printf("Menu de informes Cliente\n\n");
	printf("1-Cantidad de prestamos de importe mayor a 1000\n");
	printf("0-Salir\n");

	if(!(utn_getNumero(&opcion,"Elija un opcion: ","Error verifique los datos ingresados quedan %d intentos\n",0,1,3)))
	{
		printf("No se reconocio el ingreso, supero el maximo de posibilidades\n");
		system("PAUSE()");
	}

return opcion;
}
