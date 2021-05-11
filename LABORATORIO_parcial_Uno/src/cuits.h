/*
 * cuits.h
 *
 *  Created on: 2 may. 2021
 *      Author: inoriega
 */

#ifndef CUITS_H_
#define CUITS_H_

typedef struct
{
	char cuit[12];
	int isEmpty;
}cuits;

/**
 *\brief marca todos las posiciones del array como empty
 *\param compra array[] recibe direccion de memoria del array
 *\param int limiteArray recibe el limite de posiciones del array
 *\return retorna 0 si pudo validar los datos y -1 si no pudo
 */
int cuits_flagEmpty(cuits array[],int limiteArray);

/**
 *\brief permite saber si un cuit no se encuentra en la lista de cuits
 *\param cuits listaCuits[]
 *\param int lenCuits
 *\param char cuitCliente
 *\return retorno devuelve 1 si el cuit no es repetido y -1 si no pudo validar o el cuit es repetido
 */
int  cuits_noEsRepetido(cuits listaCuits[], int lenCuits, char cuitCliente[]);

#endif /* CUITS_H_ */
