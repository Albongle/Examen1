/*
 * prestamocliente.h
 *
 *  Created on: 15 may. 2020
 *      Author: aleja
 */

#include "clientes.h"
#ifndef PRESTAMOCLIENTE_H_
#define PRESTAMOCLIENTE_H_



typedef struct ePrestamoCliente{
	int id;
	int idPrestamo;
	int idCliente;
	int isEmpty;
}ePrestamoCliente;

/**
 * brief inicializa Array de prestamosclientes
 * param pArrayPrestamoClientes es el Array que se va a inicializar
 * param tamArrayPrestamoCLientes es el tamaño del Array
 * param valorInt es el valor que se va a asignar en todas las posiciones de Array
 */
void iniArrayPrestamoClientes(ePrestamoCliente* pArrayPrestamoClientes,int tamArrayPrestamoCLientes,int valorInt);
/**
 * brief harcodea Array de prestamos clientes
 * param pArrayPrestamoClientes es el Array que se va a Harcodear
 * param tamArrayPrestamoCLientes es el tamaño del Array
 * param cantidad es la cantidad de posiciones que se van a hacodear, la funcion posee 10 registros
 * return la cantidad de posiciones que se pudieron harcodear
 */
int hardcodearPrestamoClientes(ePrestamoCliente* pArrayPrestamoClientes, int tamArrayPrestamoCLientes, int cantidad);
/**
 * brief funcion usada para la cargar de resgistros de idcliente e idprestamo al momento del alta de un nuevo prestamo para un cliente
 * param pArrayPrestamoClientes es el Array sobre el que va a almacenar la informacion
 * param tamArrayPrestamoCLientes es el tamaño del Array
 * param idPrestamoCliente es el id que se le va a asignar a la gestion
 * param idPrestamo es el id del prestamo dado de alta recibido
 * param idCliente es el id del cliente al cual se le dio de alta un nuevo prestamo recibido
 */
void altaPrestamoCliente(ePrestamoCliente* pArrayPrestamoClientes,int tamArrayPrestamoClientes,int idPrestamoCliente, int idPrestamo, int idCliente);
/**
 * brief funcion usada para recorrer el array de cliente y mostrarlos con la cantidad de prestamos que posee cada uno
 * param pArrayClientes es el array de clientes sobre el cual se va a listar
 * param tamArrayClientes es el tamaño del array de clientes
 * param pArrayPrestamoClientes es el array que se va a usar para obtener el id de prestamos y contar la cantidad por cliente
 * param tamArrayPrestamoClientes es el tamaño del array prestamos clientes
 */
void mostrarClientesPrestamos(eClientes* pArrayClientes, int tamArrayClientes, ePrestamoCliente* pArrayPrestamoClientes,int tamArrayPrestamoClientes);
/**
 * brief listar un cliente con la cantidad de prestamos
 * pArrayClientes es el array donde se ecuenta el cliente a mostrar, el mismo debe indicarse acompañado de su subindice
 * param pArrayPrestamoClientes es el array que se va a usar para obtener el id de prestamos y contar la cantidad por cliente
 * param tamArrayPrestamoClientes es el tamaño del array prestamos clientes
 */
void mostrarClientePrestamo(eClientes pArrayClientes, ePrestamoCliente* pArrayPrestamoClientes,int tamArrayPrestamoClientes);
/**
 * brief funcion usada al momento de la baja de un cliente, donde se eliminar junto con sus prestamos dentro de la estructura
 * param pArrayPrestamoClientes es el Array sobre el que va a almacenar la informacion
 * param tamArrayPrestamoCLientes es el tamaño del Array
 * param idClienteBaja es el id del cliente sobre el cual se realizo la baja
 */

void bajaPrestamoYcliente(ePrestamoCliente* pArrayPrestamoClientes,int tamArrayPrestamoClientes,int idClienteBaja);
/**
 * brief funcion usada para cambiar el estado de los prestamos a saldado dentro de la estructura
 * param pArrayPrestamoClientes es el Array sobre el que va a almacenar la informacion
 * param tamArrayPrestamoCLientes es el tamaño del Array
 * param idPrestamo es el id del prestamo sobre el cual se cambia estado saldado
 */
void prestamoSaldado(ePrestamoCliente* pArrayPrestamoClientes,int tamArrayPrestamoClientes,int idPrestamo);
/**
 * brief funcion usada para cambiar el estado de los prestamos a actiuvo dentro de la estructura
 * param pArrayPrestamoClientes es el Array sobre el que va a almacenar la informacion
 * param tamArrayPrestamoCLientes es el tamaño del Array
 * param idPrestamo es el id del prestamo sobre el cual se cambia estado activo
 */
void activoPrestamo(ePrestamoCliente* pArrayPrestamoClientes,int tamArrayPrestamoClientes,int idPrestamo);
/**
 * brief funcion para obtener la cantidad de prestamos activos de un cliente
 * param tamArrayPrestamoCLientes es el tamaño del Array
 * param idCliente es el id del cliente sobre el cual se va a realizar la consulta
 * return la cantidad de prestamos activos del cliente
 */
int cantidadPrestamosActivosCliente(ePrestamoCliente* pArrayPrestamoClientes,int tamArrayPrestamoClientes, int idCliente);
/**
 * brief funcion para obtener la cantidad de prestamos saldados de un cliente
 * param tamArrayPrestamoCLientes es el tamaño del Array
 * param idCliente es el id del cliente sobre el cual se va a realizar la consulta
 * return la cantidad de prestamos saldados del cliente
 */
int cantidadPrestamosSaldadosCliente(ePrestamoCliente* pArrayPrestamoClientes,int tamArrayPrestamoClientes, int idCliente);


#endif /* PRESTAMOCLIENTE_H_ */
