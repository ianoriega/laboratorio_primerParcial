
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "utn.h"
#include "arr.h"
#include "compra.h"



/**
 *\brief marca todos las posiciones del array como empty
 *\param compra array[] recibe direccion de memoria del array
 *\param int limiteArray recibe el limite de posiciones del array
 *\return retorna 0 si pudo validar los datos y -1 si no pudo
 */
int compra_flagEmpty(compra array[],int limiteArray)
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
 *\param compra listaCompras[] recibe la lista
 *\param int lenCompras recibe el limite de la lista
 *\return retorno retorna -1 si no pudo validar / retorna indice encontrado
 */
int compra_posicionLibre(compra listaCompras[],int lenCompras)
{
	int retorno =-1;
	int i;

	if(listaCompras!=NULL && lenCompras>=0)
	{
		for(i=0;i<lenCompras;i++)
		{
			if(listaCompras[i].isEmpty ==1)
			{
				retorno =i;
				break;
			}
		}
	}
	return retorno;
}

/**
 *\brief recibe un indice de la lista y genera un id random dentro del minimo y el maximo
 *\param compra listaCompras[] recibe la lista de items
 *\param int lenCompras recibe el limite de la lista
 *\param int indice recibe la posicion a modificar
 *\param int minimo recibe el minimo del id
 *\param int maximo recibe el maximo del id
 *\return retorno 0 si pudo procesar y -1 si no pudo validar
 */
int compra_idRandom(compra listaCompras[],int lenCompras, int indice, int minimo, int maximo)
{
	int retorno =-1;
	int flagIdRepetido;
	int nuevoId;
	int i;

	if(listaCompras!=NULL && lenCompras>=0 && indice>=0 && minimo<maximo)
	{
		do
		{
			flagIdRepetido =1;

			do
			{
				srand(time(NULL));
				nuevoId = minimo + (rand() % maximo +1 - minimo);

			}while(nuevoId < minimo || nuevoId > maximo);

			for(i=0;i<lenCompras;i++)
			{
				if(listaCompras[i].idCompra== nuevoId)
				{
					break;
				}

				flagIdRepetido =0;
			}

		}while(flagIdRepetido);

		listaCompras[indice].idCompra = nuevoId;

		retorno =0;
	}

	return retorno;
}


/**
 *\brief permite dar de alta una compra
 *\param compra listaCompras[] recibe la lista de las compras
 *\param int lenCompras recibe el limite de la lista de compras
 *\param cliente listaClientes[] recibe la lista de los clientes
 *\param int lenCliente recibe el limite de la lista de los clentes
 *\return retorno devuelve -1 si no pudo validar y 0 si proceso
 */
int compra_alta(compra listaCompras[], int lenCompras, cliente listaClientes[], int lenCliente)
{
	int retorno =-1;
	int idElegido;
	int indiceLibre;
	int barbijosCantidad;

	if(listaCompras!=NULL && lenCompras>=0)
	{
		indiceLibre = compra_posicionLibre(listaCompras, lenCompras);
		//imprimir clientes
		cliente_imprimir(listaClientes, lenCliente);
		//id cliente
		if(utn_getNumero(&idElegido, 5, "\nIngrese el ID del cliente", "Error", 1000, 9999, 1)==0)
		{
			listaCompras[indiceLibre].idClienteElegido = idElegido;

			//cantidad de barbijos
			if(utn_getNumero(&barbijosCantidad, 6, "\nIngrese la cantidad de barbijos que desea comprar", "ERROR", 1, 10000, 1)==0)
			{
				listaCompras[indiceLibre].cantBarbijos = barbijosCantidad;

				//direccion de entrega
				if(utn_getCadena(listaCompras[indiceLibre].direccionEntrega, 64, "\nIngrese la direccion de entrega", "ERROR")==0)
				{
					//color barbijo
					if(utn_getString(listaCompras[indiceLibre].colorBarbijo, 32, "\nIngrese el color del barbijo", "ERROR", 1)==0)
					{
						//id compra
						if(compra_idRandom(listaCompras, lenCompras, indiceLibre, 1000, 9999)==0)
						{
							listaCompras[indiceLibre].isEmpty =0;
							listaCompras[indiceLibre].estadoCompra = PENDIENTE_DE_COBRAR;
							printf("\nID COMPRA: %d",listaCompras[indiceLibre].idCompra);
							retorno =0;
						}
					}
				}
			}
		}

	}

	return retorno;
}


/**
 *\brief imprime la lista de las compras
 *\param compra listaCompras[] recibe la lista de las compras
 *\param int lenCompras recibe el largo de la lista
 *\return retorno devuelve -1 si no pudo validar y 0 si valido;
 */
int compra_imprimir(compra listaCompras[], int lenCompras)
{
	int retorno =-1;
	int i;

	if(listaCompras!=NULL && lenCompras>=0)
	{
		printf("\nID - CANT - COLOR - DIRECCION");

		for(i=0;i<lenCompras;i++)
		{
			if(listaCompras[i].isEmpty !=1)
			{
				printf("\n%d  %d  %s  %s",listaCompras[i].idCompra, listaCompras[i].cantBarbijos, listaCompras[i].colorBarbijo, listaCompras[i].direccionEntrega);
			}
		}
		retorno =0;
	}

	return retorno;
}

/**
 *\brief imprime la lista de las compras en la posicion indicada
 *\param compra listaCompras[] recibe la lista de las compras
 *\param int lenCompras recibe el largo de la lista
 *\param int indice recibe la posicion a imprimir
 *\return retorno devuelve -1 si no pudo validar y 0 si valido;
 */
int compra_imprimirPorIndex(compra listaCompras[], int lenCompras, int indice)
{
	int retorno =-1;

	if(listaCompras!=NULL && lenCompras>=0)
	{

		if(listaCompras[indice].isEmpty !=1)
		{
			printf("\n%d  %d  %s  %s",listaCompras[indice].idCompra, listaCompras[indice].cantBarbijos, listaCompras[indice].colorBarbijo, listaCompras[indice].direccionEntrega);
		}

		retorno =0;
	}

	return retorno;
}

/**
 *\brief permite pagar la compra seleccionada y cambiar su estado
 *\param compra listaCompras[] recibe la lista de las compras
 *\param int lenCompras recibe el largo de la lista de compras
 *\param cliente listaClientes[] recibe la lista de los clientes
 *\param int lenClientes recibe el largo de la lista de los clientes
 *\return retorno devuelve -1 si no valido y 0 si proceso
 */
int compra_pagar(compra listaCompras[], int lenCompras, cliente listaClientes[], int lenClientes)
{
	int retorno =-1;
	int idElegido;
	int indiceCliente;
	float importePagado;
	int indiceCompra;
	int opcionElegida;

	if(listaCompras!=NULL && listaClientes!=NULL && lenCompras>=0 && lenClientes>=0)
	{
		compra_imprimir(listaCompras, lenCompras);
		utn_getNumero(&idElegido, 5, "\nIngrese el ID", "ERROR", 1000, 9999, 1);

		indiceCliente = compra_getIndexCLientbyIdCompra(listaCompras, lenCompras, listaClientes, lenClientes, idElegido);
		printf("\nID - NOMBRE - APELLIDO - CUIT");
		printf("\n%d   %s   %s    %s", listaClientes[indiceCliente].idCliente, listaClientes[indiceCliente].nombreCliente, listaClientes[indiceCliente].apellidoCliente, listaClientes[indiceCliente].cuitCliente);

		utn_getFloat(&importePagado, 10, "\nIngrese el importe pagado", "ERROR", 0, 99999999, 1);
		indiceCompra = compra_indicePorId(listaCompras, lenCompras, idElegido);
		listaCompras[indiceCompra].importeCompra = importePagado;

		utn_getNumero(&opcionElegida, 2, "\nDesea cambiar a estado COBRADA? \n[1 CONFIRMAR]\n[2 CANCELAR]", "ERROR ingrese 1 o 2", 1, 2, 3);
		switch(opcionElegida)
		{
			case 1:
				listaCompras[indiceCompra].estadoCompra = COBRADA;
				retorno =0;
				break;
			case 2:
				printf("La compra no cambio su estado");
				break;
		}
	}

	return retorno;
}


/**
 *\brief permite obtener el indice de un cliente desde el id de la compra
 *\param compra listaCompras[] recibe la lista de las compras
 *\param int lenCompras recibe el largo de la lista de las compras
 *\param cliente listaClientes[] recibe la lista de los clientes
 *\param int lenClientes recibe el largo de la lista de los clientes
 *\param int compraId recibe el id de la compra
 *\return retorno devuelve -1 si no pudo validar, devuelve el indice del cliente
 */
int compra_getIndexCLientbyIdCompra(compra listaCompras[], int lenCompras, cliente listaClientes[], int lenClientes, int compraId)
{
	int retorno =-1;
	int i;
	int bufferIdCliente;
	int indiceCLiente;

	if(listaCompras!=NULL && listaClientes!=NULL && lenCompras>=0 && lenClientes>=0)
	{
		for(i=0;i<lenCompras;i++)
		{
			if(listaCompras[i].isEmpty !=1 && listaCompras[i].idCompra == compraId)
			{
				bufferIdCliente = listaCompras[i].idClienteElegido;
			}
		}

		indiceCLiente = cliente_indicePorId(listaClientes, lenClientes, bufferIdCliente);
		retorno = indiceCLiente;
	}

	return retorno;
}


/**
 *\brief permite obtener el indice de una compra desde el id de un cliente
 *\param compra listaCompras[] recibe la lista de las compras
 *\param int lenCompras recibe el largo de la lista de las compras
 *\param cliente listaClientes[] recibe la lista de los clientes
 *\param int lenClientes recibe el largo de la lista de los clientes
 *\param int clienteId recibe el id del cliente
 *\return retorno devuelve -1 si no pudo validar, devuelve el indice de la compra
 */
int compra_getIndexComprabyIdCliente(compra listaCompras[], int lenCompras, cliente listaClientes[], int lenClientes, int clienteId)
{
	int retorno =-1;
	int i;
	int bufferIdCompra;
	int indiceCompra;

	if(listaCompras!=NULL && listaClientes!=NULL && lenCompras>=0 && lenClientes>=0)
	{
		for(i=0;i<lenCompras;i++)
		{
			if(listaCompras[i].isEmpty !=1 && listaCompras[i].idClienteElegido == clienteId)
			{
				bufferIdCompra = listaCompras[i].idCompra;
			}
		}

		indiceCompra = compra_indicePorId(listaCompras, lenCompras, bufferIdCompra);
		retorno = indiceCompra;
	}

	return retorno;
}

/**
 *\brief recibe un id, lo busca en la lista y devuelve el index
 *\param compra listaCompras[] recibe la lista de clientes
 *\param int lenCompras recibe el largo de la lista
 *\param int idIngresado recibe el id a buscar
 *\return retorno retorna el index encontrado
 */
int compra_indicePorId(compra listaCompras[], int lenCompras, int idIngresado)
{
	int retorno = -1;
	int i;

	if(listaCompras!=NULL && lenCompras>=0)
	{
		for(i=0;i<lenCompras;i++)
		{
			if(listaCompras[i].isEmpty !=1)
			{
				if(listaCompras[i].idCompra == idIngresado)
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
 *\brief permite cancelar una compra que no fue cobrada
 *\param compra listaCompras[] recibe la lista de las compras
 *\param int lenCompras recibe el largo de la lista de compras
 *\param cliente listaClientes[] recibe la lista de los clientes
 *\param int lenClientes recibe el largo de la lista de los clientes
 *\return retorno devuelve -1 si no valido y 0 si proceso
 */
int compra_cancelar(compra listaCompras[], int lenCompras, cliente listaClientes[], int lenClientes)
{
	int retorno =-1;
	int idElegido;
	int indiceCliente;
	int indiceCompra;
	int confirmacion;

	if(listaCompras!=NULL && listaClientes!=NULL && lenCompras>=0 && lenClientes>=0)
	{
		compra_imprimir(listaCompras, lenCompras);
		utn_getNumero(&idElegido, 5, "\nIngrese el ID", "ERROR", 1000, 9999, 1);

		indiceCliente = compra_getIndexCLientbyIdCompra(listaCompras, lenCompras, listaClientes, lenClientes, idElegido);
		printf("\nID - NOMBRE - APELLIDO - CUIT");
		printf("\n%d   %s   %s    %s", listaClientes[indiceCliente].idCliente, listaClientes[indiceCliente].nombreCliente, listaClientes[indiceCliente].apellidoCliente, listaClientes[indiceCliente].cuitCliente);

		indiceCompra = compra_indicePorId(listaCompras, lenCompras, idElegido);

		utn_getNumero(&confirmacion, 2, "\nEsta seguro que desea Eliminar la compra?\n[1 SI]\n[2 NO]", "ERROR", 1, 2, 3);

		if(confirmacion ==1 && listaCompras[indiceCompra].estadoCompra == PENDIENTE_DE_COBRAR)
		{
			listaCompras[indiceCompra].isEmpty =1;
			printf("\nLa compra SI fue cancelada");
		}
		else if(confirmacion ==1 && listaCompras[indiceCompra].estadoCompra == COBRADA)
		{
			printf("\nERROR la compra NO fue cancaleada: la compra fue COBRADA");
		}
		else
		{
			printf("\nLa compra NO fue cancelada");
		}
		retorno =0;
	}

	return retorno;
}

/**
 *\brief permite dar de baja a un cliente y a todas sus compras
 *\param compra listaCompras[] recibe la lista de las compras
 *\param int lenCompras recibe el largo de la lista de compras
 *\param cliente listaClientes[] recibe la lista de los clientes
 *\param int lenClientes recibe el largo de la lista de los clientes
 *\return retorno retorna -1 si no puede validar y 0 si procesa
 */
int compra_bajaCliente(cliente listaClientes[], int lenClientes, compra listaCompras[], int lenCompras)
{
	int retorno =-1;
	int idCliente;
	int i;
	int opcionElegida;
	int indiceCliente;

	if(listaClientes!=NULL && listaCompras !=NULL && lenClientes>=0 && lenCompras>=0)
	{
		cliente_imprimir(listaClientes, lenClientes);
		utn_getNumero(&idCliente, 5, "\nIngrese el ID del cliente", "ERROR", 1000, 9999, 3);

		printf("\nCOMPRAS DEL CLIENTE:");
		printf("\nID - CANT - COLOR - DIRECCION");
		for(i=0;i<lenCompras;i++)
		{
			if(listaCompras[i].idClienteElegido == idCliente && listaCompras[i].isEmpty !=1)
			{
				printf("\n%d  %d  %s  %s",listaCompras[i].idCompra, listaCompras[i].cantBarbijos, listaCompras[i].colorBarbijo, listaCompras[i].direccionEntrega);
			}
		}

		utn_getNumero(&opcionElegida, 2, "\nDesea confirmar la eliminacion?\n[1 SI]\n[2 NO]", "ERROR", 1, 2, 3);

		if(opcionElegida == 1)
		{
			for(i=0;i<lenCompras;i++)
			{
				if(listaCompras[i].idClienteElegido == idCliente)
				{
					listaCompras[i].isEmpty =1;
				}
			}

			indiceCliente = cliente_indicePorId(listaClientes, lenClientes, idCliente);
			listaClientes[indiceCliente].isEmpty =1;
			retorno =0;
		}
		else
		{
			printf("\nNo se elimino los datos");
		}
	}

	return retorno;
}


/**
 *\brief imprime los clientes a traves del cuit
 *\param compra listaCompras[] recibe la lista de las compras
 *\param int lenCompras recibe el largo de la lista de compras
 *\param cliente listaClientes[] recibe la lista de los clientes
 *\param int lenClientes recibe el largo de la lista de los clientes
 *\param cuits listaCuits[] recibe la lista de cuits
 *\param int lenCuits recibe el largo de la lista de cuits
 *\return retorno retorna -1 si no pudo validar y 0 si valido
 */
int compra_imprimirClientes(compra listaCompras[], int lenCompras, cliente listaClientes[], int lenClientes, cuits listaCuits[], int lenCuits)
{
	int retorno =-1;
	int i;

	if(listaCompras!=NULL && lenCompras >=0 && listaClientes!=NULL && lenClientes>=0 && listaCuits!=NULL && lenCuits>=0)
	{
		for(i=0;i<lenCuits;i++)
		{
			if(listaCuits[i].isEmpty != 1)
			{
				compra_imprimirPorCuitCliente(listaCompras, lenCompras, listaClientes, lenClientes, listaCuits[i].cuit);
			}
		}
		retorno =0;
	}


	return retorno;
}

/**
 *\brief imprime el cliente y sus compras por el cuit del cliente
 *\param compra listaCompras[] recibe la lista de las compras
 *\param int lenCompras recibe el largo de la lista de compras
 *\param cliente listaClientes[] recibe la lista de los clientes
 *\param int lenClientes recibe el largo de la lista de los clientes
 *\param char cuitCliente[] recibe el cuit del cliente
 *\return retorno retorna -1 si no pudo validar y 0 si pudo procesar
 */
int compra_imprimirPorCuitCliente(compra listaCompras[], int lenCompras, cliente listaClientes[], int lenClientes, char cuitCliente[])
{
	int retorno =-1;
	int i;
	int bufferIdCLiente;

	if(listaCompras!=NULL && lenCompras>=0 && listaClientes!=NULL && lenClientes>=0 && cuitCliente!=NULL)
	{
		printf("\n");
		printf("\n-DATOS DEL CLIENTE:");
		printf("\nID - NOMBRE - APELLIDO - CUIT");
		for(i=0;i<lenClientes;i++)
		{
			if(strcmp(listaClientes[i].cuitCliente,cuitCliente)==0)
			{
				printf("\n%d   %s   %s    %s", listaClientes[i].idCliente, listaClientes[i].nombreCliente, listaClientes[i].apellidoCliente, listaClientes[i].cuitCliente);
				bufferIdCLiente = listaClientes[i].idCliente;
				compra_imprimirPorIdCliente(listaCompras, lenCompras, bufferIdCLiente);
			}
		}

		retorno=0;
	}

	return retorno;
}


/**
 *\brief imprime las compras de un cliente por su ID
 *\param compra listaCompras[] recibe la lista de las comras
 *\param int lenCompra recibe el limite de la lista
 *\param int clienteId recibe el id del cliente en cuestion
 *\return retorno retorna -1 si no pudo validar y 0 si pudo procesar
 */
int compra_imprimirPorIdCliente(compra listaCompras[], int lenCompra, int clienteId)
{
	int retorno =-1;
	int i;
	int acumuladorCompras=0;

	if(listaCompras!=NULL && lenCompra>=0 && clienteId>=0)
	{
		printf("\n-COMPRAS DEL CLIENTE:");
		printf("\nID - CANT - COLOR - DIRECCION");
		for(i=0;i<lenCompra;i++)
		{
			if(listaCompras[i].idClienteElegido == clienteId)
			{
				printf("\n%d  %d  %s  %s",listaCompras[i].idCompra, listaCompras[i].cantBarbijos, listaCompras[i].colorBarbijo, listaCompras[i].direccionEntrega);
				acumuladorCompras = acumuladorCompras+1;
			}
		}
		printf("\n-CANTIDAD DE COMPRAS: %d",acumuladorCompras);
		printf("\n");
		retorno =0;
	}


	return retorno;
}


/**
 * \brief harcodeo
 */
int compra_cargar(compra listaCompras[])
{
	listaCompras[0].idClienteElegido = 1111;
	listaCompras[0].cantBarbijos = 100;
	strcpy(listaCompras[0].direccionEntrega,"sucasa11");
	strcpy(listaCompras[0].colorBarbijo,"rojo");
	listaCompras[0].idCompra = 1234;
	listaCompras[0].importeCompra = 100;
	listaCompras[0].estadoCompra = COBRADA;
	listaCompras[0].isEmpty =0;

	listaCompras[1].idClienteElegido = 2222;
	listaCompras[1].cantBarbijos = 200;
	strcpy(listaCompras[1].direccionEntrega,"sucasa22");
	strcpy(listaCompras[1].colorBarbijo,"azul");
	listaCompras[1].idCompra = 2345;
	listaCompras[1].importeCompra = 200;
	listaCompras[1].estadoCompra = COBRADA;
	listaCompras[1].isEmpty =0;

	listaCompras[2].idClienteElegido = 3333;
	listaCompras[2].cantBarbijos = 300;
	strcpy(listaCompras[2].direccionEntrega,"sucasa33");
	strcpy(listaCompras[2].colorBarbijo,"rosa");
	listaCompras[2].idCompra = 3456;
	listaCompras[2].importeCompra = 300;
	listaCompras[2].estadoCompra = COBRADA;
	listaCompras[2].isEmpty =0;

	listaCompras[3].idClienteElegido = 1111;
	listaCompras[3].cantBarbijos = 150;
	strcpy(listaCompras[3].direccionEntrega,"sucasa11");
	strcpy(listaCompras[3].colorBarbijo,"rojo");
	listaCompras[3].idCompra = 5678;
	listaCompras[3].importeCompra = 20;
	listaCompras[3].estadoCompra = COBRADA;
	listaCompras[3].isEmpty =0;
	return 0;
}

/**
 *\brief crea lista de color de barbijo en base a la lista de compras
 *\param compra listaCompras[] recibe la lista de compras
 *\param int lenCompras recibe el limite de la lista de compras
 *\param barbijo listaBarbijos[] recibe la lista de barbijos
 *\return retorno devuelve -1 si no valido y 0 si proceso
 */
int compra_crearListaBarbijos(compra listaCompras[], int lenCompras, barbijo listaBarbijos[])
{
	int retorno =-1;
	int i;

	if(listaCompras!=NULL && lenCompras>=0 && listaBarbijos!=NULL)
	{
		for(i=0;i<lenCompras;i++)
		{
			if(listaCompras[i].isEmpty != 1)
			{
				if(barbijo_noEsRepetido(listaBarbijos, lenCompras, listaCompras[i].colorBarbijo)==1)
				{
					strcpy(listaBarbijos[i].colorBarbijo,listaCompras[i].colorBarbijo);
					listaBarbijos[i].isEmpty =0;
				}
			}
		}

	}

	return retorno;
}

/**
 *
 */
int compra_informes(compra listaCompras[], int lenCompras, barbijo listaBarbijos[])
{
	int retorno =-1;
	char opcionElegida[2];

	if(listaCompras!=NULL && lenCompras>=0 && listaBarbijos!=NULL)
	{
		printf("\n a) Color de barbijo que se compro mas veces");
		printf("\n b) Cantidad de compras pendientes");
		printf("\n c) Compra con precio por unidad mas bajo");
		printf("\n");
		utn_getString(opcionElegida, 2, "\nIngrese la opcion deseada:", "ERROR", 3);

		if(strcmp(opcionElegida,"a")==0)
		{
			compra_colorBarbijosMasComprado(listaBarbijos, lenCompras, listaCompras, lenCompras);
		}
		else if(strcmp(opcionElegida,"b")==0)
		{
			compra_cantPendientes(listaCompras, lenCompras);
		}
		else if(strcmp(opcionElegida,"c")==0)
		{
			compra_precioPorUnidadMasBajo(listaCompras, lenCompras);
		}
		else
		{
			printf("\nOpcion incorrecta");
		}
	}

	return retorno;
}

/**
 *\brief calcula el barbijo que se compro mas veces e imprime la informacion
 *\param barbijo listaBarbijos[]
 *\param int lenBarbijos
 *\param compra listaCompras[]
 *\param int lenCompras
 *\return retorno devuelve -1 si no pudo validar y 0 si proceso
 */
int compra_colorBarbijosMasComprado(barbijo listaBarbijos[], int lenBarbijos, compra listaCompras[], int lenCompras)
{
	int retorno =-1;
	int i;
	int bufferMayorColor;
	char bufferColorMasComprado[32];
	int cantComprasMayorColor;
	char colorMasComprado[32];

	if(listaBarbijos!=NULL && lenBarbijos>=0 && listaCompras!=NULL && lenCompras>=0)
	{
		for(i=0;i<lenBarbijos;i++)
		{
			bufferMayorColor = compra_cantidadDeBarbijosIgualColor(listaCompras, lenCompras, listaBarbijos[i].colorBarbijo);
			strcpy(bufferColorMasComprado,listaBarbijos[i].colorBarbijo);

			if(i == 0)
			{
				cantComprasMayorColor = bufferMayorColor;
				strcpy(colorMasComprado,bufferColorMasComprado);
			}
			else
			{
				if(bufferMayorColor > cantComprasMayorColor)
				{
					cantComprasMayorColor = bufferMayorColor;
					strcpy(colorMasComprado,bufferColorMasComprado);
				}
			}
		}

		printf("\nBarbijo mas comprado: %s cant: %d",colorMasComprado,cantComprasMayorColor);

		retorno =0;

	}

	return retorno;
}

/**
 *\brief permite obtener la cantidad de barbijos del mismo color en la lista de compras
 *\param compra listaCompras[] recibe la lista de compras
 *\param nt lenCompras recibe el largo de la lista de compras
 *\param char colorBarbijo[] recibe el color del barbijo
 *\return retorno retorna -1 si no pudo validar / la cantidad de barbijos del color indicado
 */
int compra_cantidadDeBarbijosIgualColor(compra listaCompras[], int lenCompras, char colorBarbijo[])
{
	int retorno =-1;
	int i;
	int bufferContador=0;

	if(listaCompras!=NULL && lenCompras>=0 && colorBarbijo!=NULL)
	{
		for(i=0;i<lenCompras;i++)
		{
			if(strcmp(colorBarbijo,listaCompras[i].colorBarbijo)==0)
			{
				bufferContador = bufferContador +listaCompras[i].cantBarbijos;
			}
		}
		retorno = bufferContador;
	}

	return retorno;
}

/**
 *\brief calcula la cantidad de compras en estado pendiente
 *\param compra listaCompras[] recibe la lista de las compras
 *\param int lenCompra recibe el largo de la lista
 *\return retorno retorna -1 si no pudo validar y 0 si pudo procesar
 */
int compra_cantPendientes(compra listaCompras[], int lenCompra)
{
	int retorno =-1;
	int i;
	int contadorPendientes =0;

	if(listaCompras!=NULL && lenCompra>=0)
	{
		for(i=0;i<lenCompra;i++)
		{
			if(listaCompras[i].isEmpty != 1)
			{
				if(listaCompras[i].estadoCompra == PENDIENTE_DE_COBRAR)
				{
					contadorPendientes++;
				}
			}
		}

		printf("\nCANTIDAD DE COMPRAS PENDIENTES: %d",contadorPendientes);
		retorno =0;
	}

	return retorno;
}


/**
 *\brief calcula el precio por unidad mas bajo de las compras
 *\param compra listaCompras[] recibe la lista de las compras
 *\param int lenCompras recibe el largo de las compras
 *\return retorno retorna -1 si no pudo validar y 0 si pudo validar
 */
int compra_precioPorUnidadMasBajo(compra listaCompras[], int lenCompras)
{
	int retorno=-1;
	int i;
	float precioUnidadMasBajo;
	float bufferPrecioMasBajo;
	int bufferIndice;

	if(listaCompras!=NULL && lenCompras>=0)
	{
		retorno =0;
		for(i=0;i<lenCompras;i++)
		{
			if(listaCompras[i].isEmpty !=1 && listaCompras[i].estadoCompra == COBRADA)
			{
				bufferPrecioMasBajo = listaCompras[i].importeCompra / listaCompras[i].cantBarbijos;

				if(i==0)
				{
					precioUnidadMasBajo = bufferPrecioMasBajo;
					bufferIndice = i;
				}
				else if(bufferPrecioMasBajo < precioUnidadMasBajo)
				{
					precioUnidadMasBajo = bufferPrecioMasBajo;
					bufferIndice = i;
				}
			}
		}

		printf("\nCompra con precio por unidad mas bajo:");
		printf("\nID - CANT - COLOR - DIRECCION");
		compra_imprimirPorIndex(listaCompras, lenCompras, bufferIndice);
		printf("\nPrecio por unidad: %.2f",precioUnidadMasBajo);

	}

	return retorno;
}
























