
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "utn.h"
#include "arr.h"
#include <time.h>
#include "barbijos.h"

/**
 *\brief marca todos las posiciones del array como empty
 *\param barbijo array[] recibe direccion de memoria del array
 *\param int limiteArray recibe el limite de posiciones del array
 *\return retorna 0 si pudo validar los datos y -1 si no pudo
 */
int barbijo_flagEmpty(barbijo array[],int limiteArray)
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
 *\param barbijo listaBarbijos[] recibe la lista de barbijos
 *\param int lenBarbijos recibe el largo de la lista
 *\param char colorBarbijo[] recibe el color del barbijo
 *\return retorno devuelve 1 si el colorBarbijo no es repetido y -1 si no pudo validar o el colorBarbijo es repetido
 */
int  barbijo_noEsRepetido(barbijo listaBarbijos[], int lenBarbijos, char colorBarbijo[])
{
	int retorno =-1;
	int i;
	char bufferBarbijo[32];

	if(listaBarbijos!=NULL && lenBarbijos>=0 && colorBarbijo!=NULL)
	{
		for(i=0;i<lenBarbijos;i++)
		{
			retorno=1;
			if(strcmp(bufferBarbijo,colorBarbijo)==0)
			{
				retorno =-1;
				break;
			}
		}
	}

	return retorno;
}
