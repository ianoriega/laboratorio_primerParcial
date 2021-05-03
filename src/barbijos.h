/*
 * barbijos.h
 *
 *  Created on: 2 may. 2021
 *      Author: inoriega
 */

#ifndef BARBIJOS_H_
#define BARBIJOS_H_


typedef struct
{
	char colorBarbijo[32];
	int isEmpty;

}barbijo;


/**
 *\brief marca todos las posiciones del array como empty
 *\param barbijo array[] recibe direccion de memoria del array
 *\param int limiteArray recibe el limite de posiciones del array
 *\return retorna 0 si pudo validar los datos y -1 si no pudo
 */
int barbijo_flagEmpty(barbijo array[],int limiteArray);

/**
 *\brief permite saber si un cuit no se encuentra en la lista de cuits
 *\param barbijo listaBarbijos[] recibe la lista de barbijos
 *\param int lenBarbijos recibe el largo de la lista
 *\param char colorBarbijo[] recibe el color del barbijo
 *\return retorno devuelve 1 si el colorBarbijo no es repetido y -1 si no pudo validar o el colorBarbijo es repetido
 */
int  barbijo_noEsRepetido(barbijo listaBarbijos[], int lenBarbijos, char colorBarbijo[]);

#endif /* BARBIJOS_H_ */
