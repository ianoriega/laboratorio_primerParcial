
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "utn.h"
#include "arr.h"
#include <time.h>
#include "cuits.h"

/**
 *\brief marca todos las posiciones del array como empty
 *\param compra array[] recibe direccion de memoria del array
 *\param int limiteArray recibe el limite de posiciones del array
 *\return retorna 0 si pudo validar los datos y -1 si no pudo
 */
int cuits_flagEmpty(cuits array[],int limiteArray)
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
 *\brief permite saber si un cuit no se encuentra en la lista de cuits
 *\param cuits listaCuits[]
 *\param int lenCuits
 *\param char cuitCliente
 *\return retorno devuelve 1 si el cuit no es repetido y -1 si no pudo validar o el cuit es repetido
 */
int  cuits_noEsRepetido(cuits listaCuits[], int lenCuits, char cuitCliente[])
{
	int retorno =-1;
	int i;
	char bufferCuit[12];

	if(listaCuits!=NULL && lenCuits>=0 && cuitCliente!=NULL)
	{
		for(i=0;i<lenCuits;i++)
		{
			retorno=1;
			if(strcmp(bufferCuit,cuitCliente)==0)
			{
				retorno =-1;
				break;
			}
		}
	}

	return retorno;
}



























