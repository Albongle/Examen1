/*
 * prestamos.h
 *
 *  Created on: 15 may. 2020
 *      Author: aleja
 */
#include "prestamocliente.h"
#include "clientes.h"

#ifndef PRESTAMOS_H_
#define PRESTAMOS_H_

typedef struct ePrestamos{
	int idPrestamo;
	float importe;
	int cuotas;
	int idCliente;
	int isEmpty;
}ePrestamos;

/**
 * brief inicializa Array de prestamos
 * param pArrayPrestamos es el Array que se va a inicializar
 * param tamArrayPrestamos es el tamaño del Array
 * param valorInt es el valor que se va a asignar en todas las posiciones de Array
 */
void iniArrayPrestamos(ePrestamos* pArrayPrestamos,int tamArrayPrestamos,int valorInt);
/**
 * brief harcodea Array de prestamos
 * param pArrayprestamos es el Array que se va a Harcodear
 * param tamArrayPrestamos es el tamaño del Array
 * param cantidad es la cantidad de posiciones que se van a hacodear, la funcion posee 10 registros
 * return la cantidad de posiciones que se pudieron harcodear
 */
int hardcodearPrestamos(ePrestamos* pArrayPrestamos, int tamArrayPrestamos, int cantidad);
/**
 * brief realiza el alta de nuevos prestamos
 * param pArrayPrestamos es el array sobre el cual se va a almacenar la nueva alta
 * param tamArrayPrestamos es el tamaño del array de prestamos
 * param idPrestamo es el id que se le va a asignar al nuevo prestamo
 * param pArrayClientes es el array de clientes, se usa para listar los clientes al momento de dar de alta el prestamo
 * param tamArrayClientes es el tamaño del array de clientes
 * param pArrayPrestamoClientes es el array que relaciona los clientes con los prestamos
 * param tamArrayPrestamoClientes es el tamaño del array prestamosclientes
 * param idPrestamoCliente es el id que se le va a asignar al array de prestamos-clientes al momento del alta
 * param limCliente es la cantidad de clientes existentes en el sistema, la cual controlara el ingreso al momento de seleccionar un ID de cliente
 * return 1 en caso de haber sido exitosa el alta
 */
int altaPrestamo(ePrestamos* pArrayPrestamos,int tamArrayPrestamos, int idPrestamo,eClientes* pArrayClientes,int tamArrayClientes,ePrestamoCliente* pArrayPrestamoClientes,int tamArrayPrestamoClientes, int idPrestamoCliente, int limCliente,int* posAlta);
/**
 * brief funcion usada para saldar prestamos
 * param pArrayPrestamos es el array sobre el cual se va a realizar la accion
 * param tamArrayPrestamos es el tamaño del array de prestamos
 * param pArrayClientes es el array de clientes, se usa para listar los clientes al momento de saldar el prestamo
 * param tamArrayClientes es el tamaño del array de clientes
 * param pArrayPrestamoClientes es el array que relaciona los clientes con los prestamos
 * param tamArrayPrestamoClientes es el tamaño del array prestamosclientes
 * param limPrestamos es la cantidad de prestamos existentes en el sistema, la cual controlara el ingreso al momento de seleccionar un ID de prestamo
 * *posAlta retorna por puntero la posicion donde se guardo el alta para luego imprimir por patalla los datos
 * return 1 en caso de haber sido exitosa la accion de saldar prestamo
 */
int saldarPrestamo(ePrestamos* pArrayPrestamos, int tamArrayPrestamos,eClientes* pArrayClientes, int tamArrayClientes,ePrestamoCliente* pArrayPrestamoClientes,int tamArrayPrestamoClientes, int limPrestamos);
/**
 * brief funcion usada para reanudar prestamos
 * param pArrayPrestamos es el array sobre el cual se va a realizar la accion
 * param tamArrayPrestamos es el tamaño del array de prestamos
 * param pArrayClientes es el array de clientes, se usa para listar los clientes al momento de saldar el prestamo
 * param tamArrayClientes es el tamaño del array de clientes
 * param pArrayPrestamoClientes es el array que relaciona los clientes con los prestamos
 * param tamArrayPrestamoClientes es el tamaño del array prestamosclientes
 * param limPrestamos es la cantidad de prestamos existentes en el sistema, la cual controlara el ingreso al momento de seleccionar un ID de prestamo
 * return 1 en caso de haber sido exitosa la accion de reanudar prestamo
 */
int reanudarPrestamo(ePrestamos* pArrayPrestamos, int tamArrayPrestamos,eClientes* pArrayClientes, int tamArrayClientes,ePrestamoCliente* pArrayPrestamoClientes,int tamArrayPrestamoClientes,int limPrestamos);
/**
 * brief funcion usada para dar de baja los prestamos al momento de la baja de un cliente
 * param pArrayPrestamos es el array sobre el cual se va a realizar la accion
 * param tamArrayPrestamos es el tamaño del array de prestamos
 * param pArrayClientes es el array de clientes, se usa para listar los clientes al momento de saldar el prestamo
 * param tamArrayClientes es el tamaño del array de clientes
 * param pArrayPrestamoClientes es el array que relaciona los clientes con los prestamos
 * param tamArrayPrestamoClientes es el tamaño del array prestamosclientes
 * param idClienteBaja es el id de cliente que se pasa por referencia y se daran de baja sus prestamos
 */
void bajaPrestamoPorIdCliente(ePrestamos* pArrayPrestamos,int tamArrayPrestamos,ePrestamoCliente* pArrayPrestamoClientes,int tamArrayPrestamoClientes,int idClienteBaja);
/**
 * brief funcion utilziada para listar un solo prestamo
 * param pArrayPrestamos es el array donde se ecuenta el prestamo a mostrar, el mismo debe indicarse acompañado de su subindice
 * param pArrayClientes es el array de clientes se va a usar para buscar el cuil del mismo al momento de mostrar el prestamo
 * param tamArrayClientes es el tamaño del array de cliente
 * param pArrayPrestamoClientes
 * param tamArrayPrestamoClientes
 */
void mostrarPrestamo(ePrestamos pArrayPrestamos, eClientes* pArrayClientes,int tamArrayClientes);
/**
 * brief funcion utilziada para listar los prestamo
 * param pArrayPrestamos es el array sobre donde se van a mostrar los prestamos
 * param tamArrayPrestamos es tmaño del array de prestamos
 * param pArrayClientes es el array de clientes se va a usar para buscar el cuil del mismo al momento de mostrar el prestamo
 * param tamArrayClientes es el tamaño del array de cliente
 * param pArrayPrestamoClientes
 * param tamArrayPrestamoClientes
 */
void mostrarPrestamos(ePrestamos* pArrayPrestamos,int tamArrayPrestamos,eClientes* pArrayClientes, int tamArrayClientes);
/**
 * brief funcion utilizada para validar la cantidad de posiciones libres que posee un Array
 * param pArrayPrestamos es el array sobre el cual se va a realizar la validacion
 * param tamArrayPrestamos es el tamaño del array recibido
 * return la cantidad de posiciones
 */
int cantidaDePosVaciasPrestamos(ePrestamos* pArrayPrestamos, int tamArrayPrestamos);


#endif /* PRESTAMOS_H_ */
