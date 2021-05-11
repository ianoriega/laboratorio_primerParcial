/*
 * cliente.h
 *
 *  Created on: 1 may. 2021
 *      Author: inoriega
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "cuits.h"

typedef struct
{
	char nombreCliente[50];
	char apellidoCliente[50];
	char cuitCliente[12];
	int idCliente;
	int isEmpty;
}cliente;

/**
 * \brief marca todos las posiciones del array como empty
 *\param cliente array[] recibe direccion de memoria del array
 *\param int limiteArray recibe el limite de posiciones del array
 *\return retorna 0 si pudo validar los datos y -1 si no pudo
 */
int cliente_flagEmpty(cliente array[],int limiteArray);

/**
 *\brief encuentra una posicion libre en la lista
 *\param cliente listaclientes[] recibe la lista
 *\param int lenCliente recibe el limite de la lista
 *\return retorno retorna -1 si no pudo validar / retorna indice encontrado
 */
int cliente_posicionLibre(cliente listaclientes[],int lenCliente);

/**
 * \brief recibe un indice de la lista y genera un id random dentro del minimo y el maximo
 * \param cliente listaclientes[] recibe la lista de items
 * \param int lenCliente recibe el limite de la lista
 * \param int indice recibe la posicion a modificar
 * \param int minimo recibe el minimo del id
 * \param int maximo recibe el maximo del id
 * \return retorno 0 si pudo procesar y -1 si no pudo validar
 */
int cliente_idRandom(cliente listaclientes[], int lenCliente, int indice, int minimo, int maximo);

/**
 * \brief permite dar de alta al cliente
 * \param cliente listaClientes[] recibe la lista de los clientes
 * \param int lenCliente recibe el limite de la lista
 * \return retorno devuelve -1 si no pudo validar y 0 si pudo procesar
 */
int cliente_Alta(cliente listaClientes[], int lenCliente);

/**
 *\brief imprime la lista de los clientes
 *\param cliente listaCliente[] recibe la lista de los clientes
 *\param int lenCliente recibe el limite de la lista
 *\return retorno devuelve -1 si no pudo validar y 0 si valido
 */
int cliente_imprimir(cliente listaCliente[], int lenCliente);

/**
 * \brief recibe un id, lo busca en la lista y devuelve el index
 * \param cliente listaClientes[] recibe la lista de clientes
 * \param int lenCliente recibe el largo de la lista
 * \param int idIngresado recibe el id a buscar
 * \return retorno retorna el index encontrado
 */
int cliente_indicePorId(cliente listaClientes[], int lenCliente, int idIngresado);

/**
 * \brief permite modificar al cliente
 * \param cliente listaClientes[] recibe la lista de los clientes
 * \param int lenCliente recibe el limite de la lista
 * \return retorno devuelve -1 si no pudo validar y 0 si pudo procesar
 */
int cliente_modificacion(cliente listaClientes[], int lenCliente);

/**
 *\brief harcodeo
 */
int cliente_precarga(cliente listaClientes[], int lenClientes);

/**
 *\brief crea lista de cuits en base a la lista de clientes
 *\param cliente listaClientes[] recibe la lista de clientes
 *\param int lenClientes recibe el largo de la lista de clientes
 *\param cuits listaCuits[] recibe la lista de cuits
 *\return retorno devuelve -1 si no valido y 0 si proceso
 */
int cliente_crearListaCuits(cliente listaClientes[], int lenClientes, cuits listaCuits[]);

#endif /* CLIENTE_H_ */
