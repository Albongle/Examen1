/*
 * informes.h
 *
 *  Created on: 15 may. 2020
 *      Author: aleja
 */

#include "clientes.h"
#include "prestamocliente.h"
#ifndef INFORMES_H_
#define INFORMES_H_


/**
 * brief funcion usada para listar los clientes con mas prestamos activos
 * param pArrayClientes es el array de clientes que se va a recorrer
 * param tamArrayClientes es el tama�o del array de clientes
 * param pArrayPrestamoClientes es el array donde se va a validar la cantidad de prestamos activos del cliente
 * param tamArrayPrestamoClientes es el tama�o del array prestamos cliente
 */
void clienteMasPrestamosActivos(eClientes* pArrayClientes, int tamArrayClientes,ePrestamoCliente* pArrayPrestamoClientes,int tamArrayPrestamoClientes);
/**
 * brief funcion usada para listar los clientes con mas prestamos saldados
 * param pArrayClientes es el array de clientes que se va a recorrer
 * param tamArrayClientes es el tama�o del array de clientes
 * param pArrayPrestamoClientes es el array donde se va a validar la cantidad de prestamos saldados del cliente
 * param tamArrayPrestamoClientes es el tama�o del array prestamos cliente
 */
void clienteMasPrestamosSaldados(eClientes* pArrayClientes, int tamArrayClientes,ePrestamoCliente* pArrayPrestamoClientes,int tamArrayPrestamoClientes);
/**
 * brief funcion usada para mostrar la cantidad de prestos iguales a un importe ingresado
 * param pArrayPrestamos es el array sobre el cual se va a realizar la comprobacion
 * param tamArrayPrestamos es el tama�o del array
 */
void prestamosImporteMayor(ePrestamos* pArrayPrestamos,int tamArrayPrestamos);

/**
 * brief funcion usada para mostrar listar los clientes con mas prestamos
 * param pArrayClientes es el array de clientes que se va a recorrer
 * param tamArrayClientes es el tama�o del array de clientes
 * param pArrayPrestamos es el array sobre el cual se va a realizar la comprobacion
 * param tamArrayPrestamos es el tama�o del array
 */
void clienteMasPrestamos(eClientes* pArrayClientes, int tamArrayClientes,ePrestamoCliente* pArrayPrestamoClientes,int tamArrayPrestamoClientes);
/**
 * brief funcion usada para mostrar listar los de acuerdo a un importe de cupta ingresado
 * param pArrayClientes es el array de clientes que se va a recorrer
 * param tamArrayClientes es el tama�o del array de clientes
 * param pArrayPrestamos es el array sobre el cual se va a realizar la comprobacion
 * param tamArrayPrestamos es el tama�o del array
 */

void prestamoPorcuota(ePrestamos* pArrayPrestamos,int tamArrayPrestamos, eClientes* pArrayClientes, int tamArrayClientes);
/**
 * brief funcion usada para mostrar la cantidad de prestamos de acuerdo a un ingreso
 * param pArrayClientes es el array de clientes que se va a recorrer
 * param tamArrayClientes es el tama�o del array de clientes
 * param pArrayPrestamos es el array sobre el cual se va a realizar la comprobacion
 * param tamArrayPrestamos es el tama�o del array
 */

void QprestamosPorCuota(ePrestamos* pArrayPrestamos,int tamArrayPrestamos);

#endif /* INFORMES_H_ */
