
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "utn.h"
#include "arr.h"
#include <time.h>
#include "cliente.h"

/**
 * \brief marca todos las posiciones del array como empty
 *\param cliente array[] recibe direccion de memoria del array
 *\param int limiteArray recibe el limite de posiciones del array
 *\return retorna 0 si pudo validar los datos y -1 si no pudo
 */
int cliente_flagEmpty(cliente array[],int limiteArray)
{
	int retorno = -1;
	int i;

	if(array != NULL && limiteArray != 0)
	{
		for(i=0; i<limiteArray; i++)
		{
			array[i].isEmpty = 1;
		}

		retorno =0;
	}
	return retorno;
}

/**
 *\brief encuentra una posicion libre en la lista
 *\param cliente listaclientes[] recibe la lista
 *\param int lenCliente recibe el limite de la lista
 *\return retorno retorna -1 si no pudo validar / retorna indice encontrado
 */
int cliente_posicionLibre(cliente listaclientes[],int lenCliente)
{
	int retorno =-1;
	int i;

	if(listaclientes!=NULL && lenCliente>=0)
	{
		for(i=0;i<lenCliente;i++)
		{
			if(listaclientes[i].isEmpty ==1)
			{
				retorno =i;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief recibe un indice de la lista y genera un id random dentro del minimo y el maximo
 * \param cliente listaclientes[] recibe la lista de items
 * \param int lenCliente recibe el limite de la lista
 * \param int indice recibe la posicion a modificar
 * \param int minimo recibe el minimo del id
 * \param int maximo recibe el maximo del id
 * \return retorno 0 si pudo procesar y -1 si no pudo validar
 */
int cliente_idRandom(cliente listaclientes[], int lenCliente, int indice, int minimo, int maximo)
{
	int retorno =-1;
	int flagIdRepetido;
	int nuevoId;
	int i;

	if(listaclientes!=NULL && lenCliente>=0 && indice>=0 && minimo<maximo)
	{
		do
		{
			flagIdRepetido =1;

			do
			{
				srand(time(NULL));
				nuevoId = minimo + (rand() % maximo +1 - minimo);

			}while(nuevoId < minimo || nuevoId > maximo);

			for(i=0;i<lenCliente;i++)
			{
				if(listaclientes[i].idCliente== nuevoId)
				{
					break;
				}

				flagIdRepetido =0;
			}

		}while(flagIdRepetido);

		listaclientes[indice].idCliente = nuevoId;

		retorno =0;
	}

	return retorno;
}


/**
 * \brief permite dar de alta al cliente
 * \param cliente listaClientes[] recibe la lista de los clientes
 * \param int lenCliente recibe el limite de la lista
 * \return retorno devuelve -1 si no pudo validar y 0 si pudo procesar
 */
int cliente_Alta(cliente listaClientes[], int lenCliente)
{
	int retorno =-1;
	int indiceLibre;

	if(listaClientes!=NULL && lenCliente>=0)
	{
		//posicion libre
		indiceLibre = cliente_posicionLibre(listaClientes, lenCliente);

		//nombre cliente
		if(utn_getString(listaClientes[indiceLibre].nombreCliente, lenCliente, "\nIngrese el nombre del cliente", "ERROR", 1)==0)
		{
			//apellido cliente
			if(utn_getString(listaClientes[indiceLibre].apellidoCliente,lenCliente, "\nIngrese el apellido del cliente", "ERROR", 1)==0)
			{
				//cuit cliente
				if(utn_getCUIT(listaClientes[indiceLibre].cuitCliente, 12, "\nIngrese el CUIT", "ERROR")==0)
				{
					//id cliente
					if(cliente_idRandom(listaClientes, lenCliente, indiceLibre, 1000, 9999)==0)
					{
						listaClientes[indiceLibre].isEmpty =0;
						retorno =0;
						printf("\nEl cliente se genero correctamente\nID CLIENTE: %d", listaClientes[indiceLibre].idCliente);
					}
				}
			}
		}

	}

	return retorno;
}


/**
 *\brief imprime la lista de los clientes
 *\param cliente listaCliente[] recibe la lista de los clientes
 *\param int lenCliente recibe el limite de la lista
 *\return retorno devuelve -1 si no pudo validar y 0 si valido
 */
int cliente_imprimir(cliente listaCliente[], int lenCliente)
{
	int retorno =-1;
	int i;

	if(listaCliente!=NULL && lenCliente>=0)
	{
		retorno =0;
		printf("\nID - NOMBRE - APELLIDO - CUIT");
		for(i=0;i<lenCliente;i++)
		{
			if(listaCliente[i].isEmpty !=1)
			{
				printf("\n%d   %s   %s    %s", listaCliente[i].idCliente, listaCliente[i].nombreCliente, listaCliente[i].apellidoCliente, listaCliente[i].cuitCliente);
			}
		}
	}

	return retorno;
}

/**
 * \brief recibe un id, lo busca en la lista y devuelve el index
 * \param cliente listaClientes[] recibe la lista de clientes
 * \param int lenCliente recibe el largo de la lista
 * \param int idIngresado recibe el id a buscar
 * \return retorno retorna el index encontrado
 */
int cliente_indicePorId(cliente listaClientes[], int lenCliente, int idIngresado)
{
	int retorno = -1;
	int i;

	if(listaClientes!=NULL && lenCliente>=0)
	{
		for(i=0;i<lenCliente;i++)
		{
			if(listaClientes[i].isEmpty !=1)
			{
				if(listaClientes[i].idCliente == idIngresado)
				{
					retorno = i;
					break;
				}
			}
		}
	}

	return retorno;
}

/**
 * \brief permite modificar al cliente
 * \param cliente listaClientes[] recibe la lista de los clientes
 * \param int lenCliente recibe el limite de la lista
 * \return retorno devuelve -1 si no pudo validar y 0 si pudo procesar
 */
int cliente_modificacion(cliente listaClientes[], int lenCliente)
{
	int retorno =-1;
	int idElegido;
	int indiceCliente;

	if(listaClientes!=NULL && lenCliente>=0)
	{
		//imprimir lista clientes
		cliente_imprimir(listaClientes, lenCliente);

		//posicion a modificar
		utn_getNumero(&idElegido, 5, "\nIngrese el ID que desea modificar", "Error", 1000, 9999, 1);

		//buscar el indice
		indiceCliente = cliente_indicePorId(listaClientes, lenCliente, idElegido);

		//nombre cliente
		if(utn_getString(listaClientes[indiceCliente].nombreCliente, lenCliente, "\nIngrese el nombre del cliente", "ERROR", 1)==0)
		{
			//apellido cliente
			if(utn_getString(listaClientes[indiceCliente].apellidoCliente,lenCliente, "\nIngrese el apellido del cliente", "ERROR", 1)==0)
			{
				//cuit cliente
				if(utn_getCUIT(listaClientes[indiceCliente].cuitCliente, 12, "\nIngrese el CUIT", "ERROR")==0)
				{
						retorno =0;
						printf("\nEl cliente se modifico correctamente");
				}
			}
		}

	}

	return retorno;
}

/**
 *\brief harcodeo
 */
int cliente_precarga(cliente listaClientes[], int lenClientes)
{
	int retorno =-1;

	if(listaClientes!=NULL && lenClientes>=0)
	{
		strcpy(listaClientes[0].nombreCliente, "Jose");
		strcpy(listaClientes[0].apellidoCliente, "Pastoriza");
		strcpy(listaClientes[0].cuitCliente, "25145694838");
		listaClientes[0].idCliente = 1111;
		listaClientes[0].isEmpty =0;

		strcpy(listaClientes[1].nombreCliente, "Americo");
		strcpy(listaClientes[1].apellidoCliente, "Gallego");
		strcpy(listaClientes[1].cuitCliente, "25138495838");
		listaClientes[1].idCliente = 2222;
		listaClientes[1].isEmpty =0;

		strcpy(listaClientes[2].nombreCliente, "Julio");
		strcpy(listaClientes[2].apellidoCliente, "Falcioni");
		strcpy(listaClientes[2].cuitCliente, "25225943458");
		listaClientes[2].idCliente = 3333;
		listaClientes[2].isEmpty =0;

	}

	return retorno;
}


/**
 *\brief crea lista de cuits en base a la lista de clientes
 *\param cliente listaClientes[] recibe la lista de clientes
 *\param int lenClientes recibe el largo de la lista de clientes
 *\param cuits listaCuits[] recibe la lista de cuits
 *\return retorno devuelve -1 si no valido y 0 si proceso
 */
int cliente_crearListaCuits(cliente listaClientes[], int lenClientes, cuits listaCuits[])
{
	int retorno =-1;
	int i;

	if(listaClientes!=NULL && lenClientes>=0 && listaCuits!=NULL)
	{
		for(i=0;i<lenClientes;i++)
		{
			if(listaClientes[i].isEmpty != 1)
			{
				if(cuits_noEsRepetido(listaCuits, lenClientes, listaClientes[i].cuitCliente)==1)
				{
					strcpy(listaCuits[i].cuit,listaClientes[i].cuitCliente);
					listaCuits[i].isEmpty =0;

				}
			}
		}
		retorno =0;
	}


	return retorno;
}


















