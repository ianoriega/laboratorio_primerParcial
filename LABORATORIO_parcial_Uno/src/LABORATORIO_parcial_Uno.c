/**
 * Parcial primer cuatrimestre, laboratorio programacion, alumno Iñaki Noriega
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "utn.h"
#include "arr.h"
#include "compra.h"
#include "cliente.h"
#include "cuits.h"
#include "barbijos.h"

#define CANT_CLIENTES 99
#define CANT_COMPRAS 999
int main(void)
{
	int opcionElegida;
	int continuar;
	cliente listaClientes[CANT_CLIENTES];
	compra listaCompras[CANT_COMPRAS];
	cuits listaCuits[CANT_CLIENTES];
	barbijo listaBarbijos[CANT_COMPRAS];

	cliente_flagEmpty(listaClientes, CANT_CLIENTES);
	compra_flagEmpty(listaCompras, CANT_COMPRAS);
	cuits_flagEmpty(listaCuits, CANT_CLIENTES);
	barbijo_flagEmpty(listaBarbijos, CANT_COMPRAS);

	cliente_precarga(listaClientes, CANT_CLIENTES);
	compra_cargar(listaCompras);

	printf("BIENVENIDO");

	do
	{
		printf("\n");
		printf("\n[1] CLIENTE, ALTA");
		printf("\n[2] CLIENTE, MODIFICAR");
		printf("\n[3] CLIENTE, BAJA");
		printf("\n[4] COMPRA, REALIZAR");
		printf("\n[5] COMPRA, PAGAR");
		printf("\n[6] COMPRA, CANCELAR");
		printf("\n[7] IMPRIMIR CLIENTES");
		printf("\n[8] INFORMES");
		printf("\n[9] INFORMES PARCIAL");
		printf("\n[10] SALIR");
		printf("\n");

		utn_getNumero(&opcionElegida, 2, "\n-INGRESE LA OPCION DESEADA", "\nERROR opcion invalida", 1, 10, 1);

		continuar =1;
		switch(opcionElegida)
		{
			case 1:
				cliente_Alta(listaClientes, CANT_CLIENTES);
				break;
			case 2:
				cliente_modificacion(listaClientes, CANT_CLIENTES);
				break;
			case 3:
				compra_bajaCliente(listaClientes, CANT_CLIENTES, listaCompras, CANT_COMPRAS);
				break;
			case 4:
				compra_alta(listaCompras, CANT_COMPRAS, listaClientes, CANT_CLIENTES);
				break;
			case 5:
				compra_pagar(listaCompras, CANT_COMPRAS, listaClientes, CANT_CLIENTES);
				break;
			case 6:
				compra_cancelar(listaCompras, CANT_COMPRAS, listaClientes, CANT_CLIENTES);
				break;
			case 7:
				cliente_crearListaCuits(listaClientes, CANT_CLIENTES, listaCuits);
				compra_imprimirClientes(listaCompras, CANT_COMPRAS, listaClientes, CANT_CLIENTES, listaCuits, CANT_CLIENTES);
				break;
			case 8:
				compra_crearListaBarbijos(listaCompras, CANT_COMPRAS, listaBarbijos);
				compra_informes(listaCompras, CANT_COMPRAS, listaBarbijos);
				break;
			case 9:
				compra_informesParcial(listaCompras, CANT_COMPRAS, listaClientes, CANT_CLIENTES);
				break;
			case 10:
				continuar =0;
				break;
		}

	}while(continuar==1);

	printf("GRACIAS POR UTILIZAR LA APLICACION!!");

	return EXIT_SUCCESS;
}
