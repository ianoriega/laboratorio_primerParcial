/*
 * compra.h
 *
 *  Created on: 1 may. 2021
 *      Author: inoriega
 */

#ifndef COMPRA_H_
#define COMPRA_H_

#include "cliente.h"
#include "cuits.h"
#include "barbijos.h"

#define PENDIENTE_DE_COBRAR 0
#define COBRADA 1

typedef struct
{
	int idClienteElegido;
	int cantBarbijos;
	char direccionEntrega[64];
	char colorBarbijo[32];
	int idCompra;
	float importeCompra;
	int estadoCompra;
	int isEmpty;
}compra;

/**
 *\brief marca todos las posiciones del array como empty
 *\param compra array[] recibe direccion de memoria del array
 *\param int limiteArray recibe el limite de posiciones del array
 *\return retorna 0 si pudo validar los datos y -1 si no pudo
 */
int compra_flagEmpty(compra array[],int limiteArray);

/**
 *\brief encuentra una posicion libre en la lista
 *\param compra listaCompras[] recibe la lista
 *\param int lenCompras recibe el limite de la lista
 *\return retorno retorna -1 si no pudo validar / retorna indice encontrado
 */
int compra_posicionLibre(compra listaCompras[],int lenCompras);

/**
 *\brief recibe un indice de la lista y genera un id random dentro del minimo y el maximo
 *\param compra listaCompras[] recibe la lista de items
 *\param int lenCompras recibe el limite de la lista
 *\param int indice recibe la posicion a modificar
 *\param int minimo recibe el minimo del id
 *\param int maximo recibe el maximo del id
 *\return retorno 0 si pudo procesar y -1 si no pudo validar
 */
int compra_idRandom(compra listaCompras[],int lenCompras, int indice, int minimo, int maximo);

/**
 *\brief permite dar de alta una compra
 *\param compra listaCompras[] recibe la lista de las compras
 *\param int lenCompras recibe el limite de la lista de compras
 *\param cliente listaClientes[] recibe la lista de los clientes
 *\param int lenCliente recibe el limite de la lista de los clentes
 *\return retorno devuelve -1 si no pudo validar y 0 si proceso
 */
int compra_alta(compra listaCompras[], int lenCompras, cliente listaClientes[], int lenCliente);

/**
 *\brief imprime la lista de las compras
 *\param compra listaCompras[] recibe la lista de las compras
 *\param int lenCompras recibe el largo de la lista
 *\return retorno devuelve -1 si no pudo validar y 0 si valido;
 */
int compra_imprimir(compra listaCompras[], int lenCompras);

/**
 *\brief permite obtener el indice de un cliente desde el id de la compra
 *\param compra listaCompras[] recibe la lista de las compras
 *\param int lenCompras recibe el largo de la lista de las compras
 *\param cliente listaClientes[] recibe la lista de los clientes
 *\param int lenClientes recibe el largo de la lista de los clientes
 *\param int compraId recibe el id de la compra
 *\return retorno devuelve -1 si no pudo validar, devuelve el indice del cliente
 */
int compra_getIndexCLientbyIdCompra(compra listaCompras[], int lenCompras, cliente listaClientes[], int lenClientes, int compraId);

/**
 *\brief recibe un id, lo busca en la lista y devuelve el index
 *\param compra listaCompras[] recibe la lista de clientes
 *\param int lenCompras recibe el largo de la lista
 *\param int idIngresado recibe el id a buscar
 *\return retorno retorna el index encontrado
 */
int compra_indicePorId(compra listaCompras[], int lenCompras, int idIngresado);

/**
 *\brief permite pagar la compra seleccionada y cambiar su estado
 *\param compra listaCompras[] recibe la lista de las compras
 *\param int lenCompras recibe el largo de la lista de compras
 *\param cliente listaClientes[] recibe la lista de los clientes
 *\param int lenClientes recibe el largo de la lista de los clientes
 *\return retorno devuelve -1 si no valido y 0 si proceso
 */
int compra_pagar(compra listaCompras[], int lenCompras, cliente listaClientes[], int lenClientes);

/**
 *\brief permite cancelar una compra que no fue cobrada
 *\param compra listaCompras[] recibe la lista de las compras
 *\param int lenCompras recibe el largo de la lista de compras
 *\param cliente listaClientes[] recibe la lista de los clientes
 *\param int lenClientes recibe el largo de la lista de los clientes
 *\return retorno devuelve -1 si no valido y 0 si proceso
 */
int compra_cancelar(compra listaCompras[], int lenCompras, cliente listaClientes[], int lenClientes);

/**
 *\brief imprime la lista de las compras en la posicion indicada
 *\param compra listaCompras[] recibe la lista de las compras
 *\param int lenCompras recibe el largo de la lista
 *\param int indice recibe la posicion a imprimir
 *\return retorno devuelve -1 si no pudo validar y 0 si valido;
 */
int compra_imprimirPorIndex(compra listaCompras[], int lenCompras, int indice);

/**
 *\brief permite obtener el indice de una compra desde el id de un cliente
 *\param compra listaCompras[] recibe la lista de las compras
 *\param int lenCompras recibe el largo de la lista de las compras
 *\param cliente listaClientes[] recibe la lista de los clientes
 *\param int lenClientes recibe el largo de la lista de los clientes
 *\param int clienteId recibe el id del cliente
 *\return retorno devuelve -1 si no pudo validar, devuelve el indice de la compra
 */
int compra_getIndexComprabyIdCliente(compra listaCompras[], int lenCompras, cliente listaClientes[], int lenClientes, int clienteId);

/**
 *\brief permite dar de baja a un cliente y a todas sus compras
 *\param compra listaCompras[] recibe la lista de las compras
 *\param int lenCompras recibe el largo de la lista de compras
 *\param cliente listaClientes[] recibe la lista de los clientes
 *\param int lenClientes recibe el largo de la lista de los clientes
 *\return retorno retorna -1 si no puede validar y 0 si procesa
 */
int compra_bajaCliente(cliente listaClientes[], int lenClientes, compra listaCompras[], int lenCompras);


/**
 *\brief imprime las compras de un cliente por su ID
 *\param compra listaCompras[] recibe la lista de las comras
 *\param int lenCompra recibe el limite de la lista
 *\param int clienteId recibe el id del cliente en cuestion
 *\return retorno retorna -1 si no pudo validar y 0 si pudo procesar
 */
int compra_imprimirPorIdCliente(compra listaCompras[], int lenCompra, int clienteId);

/**
 *\brief imprime el cliente y sus compras por el cuit del cliente
 *\param compra listaCompras[] recibe la lista de las compras
 *\param int lenCompras recibe el largo de la lista de compras
 *\param cliente listaClientes[] recibe la lista de los clientes
 *\param int lenClientes recibe el largo de la lista de los clientes
 *\param char cuitCliente[] recibe el cuit del cliente
 *\return retorno retorna -1 si no pudo validar y 0 si pudo procesar
 */
int compra_imprimirPorCuitCliente(compra listaCompras[], int lenCompras, cliente listaClientes[], int lenClientes, char cuitCliente[]);

/**
 * \brief harcodeo
 */
int compra_cargar(compra listaCompras[]);

/**
 *\brief crea lista de color de barbijo en base a la lista de compras
 *\param compra listaCompras[] recibe la lista de compras
 *\param int lenCompras recibe el limite de la lista de compras
 *\param barbijo listaBarbijos[] recibe la lista de barbijos
 *\return retorno devuelve -1 si no valido y 0 si proceso
 */
int compra_crearListaBarbijos(compra listaCompras[], int lenCompras, barbijo listaBarbijos[]);

/**
 *\brief permite obtener la cantidad de barbijos del mismo color en la lista de compras
 *\param compra listaCompras[] recibe la lista de compras
 *\param nt lenCompras recibe el largo de la lista de compras
 *\param char colorBarbijo[] recibe el color del barbijo
 *\return retorno retorna -1 si no pudo validar / la cantidad de barbijos del color indicado
 */
int compra_cantidadDeBarbijosIgualColor(compra listaCompras[], int lenCompras, char colorBarbijo[]);

/**
 *\brief calcula el barbijo que se compro mas veces
 *\param barbijo listaBarbijos[]
 *\param int lenBarbijos
 *\param compra listaCompras[]
 *\param int lenCompras
 *\return retorno devuelve -1 si no pudo validar y 0 si proceso
 */
int compra_colorBarbijosMasComprado(barbijo listaBarbijos[], int lenBarbijos, compra listaCompras[], int lenCompras);

/**
 *\brief calcula la cantidad de compras en estado pendiente
 *\param compra listaCompras[] recibe la lista de las compras
 *\param int lenCompra recibe el largo de la lista
 *\return retorno retorna -1 si no pudo validar y 0 si pudo procesar
 */
int compra_cantPendientes(compra listaCompras[], int lenCompra);

/**
 *\brief calcula el precio por unidad mas bajo de las compras
 *\param compra listaCompras[] recibe la lista de las compras
 *\param int lenCompras recibe el largo de las compras
 *\return retorno retorna -1 si no pudo validar y 0 si pudo validar
 */
int compra_precioPorUnidadMasBajo(compra listaCompras[], int lenCompras);


/**
 *\brief calcula y muestra los informes
 *\param compra listaCompras[] recibe la lista de las compras
 *\param int lenCompras recibe el largo de la lista de compras
 *\param barbijo listaBarbijos[] recibe la lista de los barbijos
 *\return retorno retorna -1 si no puede validar y 0 si pudo procesar
 */
int compra_informes(compra listaCompras[], int lenCompras, barbijo listaBarbijos[]);


/**
 *\brief calcula la cantidad de compras de un cliente pagadas
 */
int compra_cantComprasPorCLientePagadas(compra listaCompras[], int lenCompras, int clienteId);

/**
 * \brief calcula el cliente con mas compras pagadas
 */
int compra_clienteConMasComPagadas(compra listaCompras[], int lenCompras, cliente listaClientes[], int lenClientes);

/**
 *\brief informes del parcial
 */
int compra_informesParcial(compra listaCompras[], int lenCompras, cliente listaClientes[], int lenClientes);


/**
 *\brief calcula la cantidad de compras de un cliente pendientes
 */
int compra_cantComprasPorCLientePendientes(compra listaCompras[], int lenCompras, int clienteId);

/**
 * \brief calcula el cliente con mas compras pendientes
 */
int compra_clienteConMasComPendientes(compra listaCompras[], int lenCompras, cliente listaClientes[], int lenClientes);


/**
 *\brief imprime los datos del cliente por id
 */
int compra_imprimirDatosClientePorID(cliente listaClientes[], int lenClientes,int clienteId);


/**
 * \brief lista de compras pendientes de pago con informacion de la compra y el cliente
 */
int compra_listaPendientesPagoConInfo(compra listaCompras[], int lenCompras, cliente listaClientes[], int lenCliente);

#endif /* COMPRA_H_ */
