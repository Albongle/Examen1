/*
 * clientes.h
 *
 *  Created on: 15 may. 2020
 *      Author: aleja
 */

#ifndef CLIENTES_H_
#define CLIENTES_H_

typedef struct eClientes{
	int idCliente;
	char nombre[20];
	char apellido[20];
	char cuil[15];
	int isEmpty;
}eClientes;


/**
 * brief inicializa Array de clientes
 * param pArrayClientes es el Array que se va a inicializar
 * param tamArrayCLientes es el tamaño del Array
 * param valorInt es el valor que se va a asignar en todas las posiciones de Array
 */
void iniArrayClientes(eClientes* pArrayClientes,int tamArrayCLientes,int valorInt);
/**
 * brief harcodea Array de clientes
 * param pArrayClientes es el Array que se va a Harcodear
 * param tamArrayCLientes es el tamaño del Array
 * param cantidad es la cantidad de posiciones que se van a hacodear, la funcion posee 10 registros
 * return la cantidad de posiciones que se pudieron harcodear
 */
int hardcodearClientes(eClientes* pArrayClientes, int tamArrayCLientes, int cantidad);
/**
 * brief realiza el alta de un cliente nuevo
 * param pArrayClientes es el array donde se van almacenar los datos del nuevo cliente
 * param tamArrayClientes es el tamaño del array recibido
 * param idCliente es valor del ID actual que se va a asignar al momento del alta del cliente
 * *posAlta retorna por puntero la posicion donde se guardo el alta para luego imprimir por patalla los datos
 * return 1 en caso de haber realizado el alta de manera correcta.
 */
int altaCliente(eClientes* pArrayClientes,int tamArrayClientes, int idCliente,int* posAlta);
/**
 * brief realiza la modificacion de un cliente existente
 * param pArrayClientes es el array donde se van almacenar los datos del cliente
 * param tamArrayClientes es el tamaño del array recibido
 * param limCliente es la cantidad de clientes existentes en el sistema, la cual controlara el ingreso al momento de seleccionar un ID de cliente a modificar
 * return 1 en caso de haber realizado la modificacion de manera exitosa
 */
int modificarCliente(eClientes* pArrayClientes,int tamArrayClientes,int limCliente);
/**
 * brief realiza la baja de un cliente existente
 * param pArrayClientes es el array donde se va a realizar la baja
 * param tamArrayClientes es el tamaño del array recibido
 * param limCliente es la cantidad de clientes existentes en el sistema, la cual controlara el ingreso al momento de seleccionar un ID de cliente a modificar
 * return 1 en caso de haber realizado la baja de manera exitosa
 */
int bajaCliente(eClientes* pArrayClientes, int tamArrayClientes, int* IdBaja,int limCliente);
/**
 * brief funcion utilziada para listar todos los clientes
 * param pArrayClientes es el array que se va a listar
 * param tamArrayClientes es el tamaño del array recibido
 */
void mostrarClientes(eClientes* pArrayClientes, int tamArrayClientes);
/**
 * brief funcion utilziada para listar un solo cliente
 * param pArrayClientes es el array donde se ecuenta el cliente a mostrar, el mismo debe indicarse acompañado de su subindice
 */
void mostrarCliente(eClientes pArraysClientes);
/**
 * brief funcion utilziada para listar un solo cliente y la cantidad de prestamos que el mismo posee
 * param pArrayClientes es el array donde se ecuenta el cliente a mostrar, el mismo debe indicarse acompañado de su subindice
 * param qPrestamos es la cantidad de prestamos que posee ese cliente en particular
 */
void mostrarCliente_Prestamo(eClientes pArrayClientes, int qPrestamos);
/**
 * brief funcion utilziada para buscar el cuil de un cliente en particular
 * param pArrayClientes es el array sobre el cual se va a realizar la busqueda
 * param tamArrayClientes es el tamaño del array recibido
 * param idCliente es el valor que se pasa pos refencia y que va a ser considerado al momento de la busqueda
 * cuil de volvera por puntero el cuil del Cliente encontrado
 * return 1 en caso exitoso
 */
int buscaCuil_IdCliente(eClientes* pArrayClientes,int tamArrayClientes, int idCliente, char cuil[]);
/**
 * brief funcion utilziada para buscar la posicion donde se encuentra almacenado un cliente dentro del Array
 * param pArrayClientes es el array sobre el cual se va a realizar la busqueda
 * param tamArrayClientes es el tamaño del array recibido
 * param valorBuscado es el valor que se pasa pos refencia y que va a ser considerado al momento de la busqueda
 * cuil de volvera por puntero el cuil del Cliente encontrado
 * return la posicion donde fue encontrado el valor indicado, en caso contrario return -1
 */
int buscarPosCliente_ID(eClientes* pArrayClientes,int valorBuscado, int tamArrayClientes);
/**
 * brief funcion utilizada para validar la cantidad de posiciones libres que posee un Array
 * param pArrayClientes es el array sobre el cual se va a realizar la validacion
 * param tamArrayClientes es el tamaño del array recibido
 * return la cantidad de posiciones
 */
int cantidaDePosVaciasClientes(eClientes* pArrayPClientes, int tamArrayClientes);

#endif /* CLIENTES_H_ */
