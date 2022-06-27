#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn.h"
/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto). fscanf, los cargo en memoria y los recorro.
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main(void)
{
   setbuf(stdout,NULL);
	int opcion = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();
    int idAux=1000;

    do
    {
    	if(utn_pedirInt(&opcion,"MENU\n1)Cargar los datos desde data.csv(texto)." //OK
    			"\n2)Cargar los datos desde data.csv(binario)."//OK
    			"\n3)Alta de pasajero."//OK
    			"\n4)Modificar pasajero."//OK
    			"\n5)Baja de passajero."//OK
    			"\n6)Listar pasajeros."//OK
    			"\n7)Orden pasajeros."//OK
    			"\n8)Guardar en el archivo csv(texto)."//OK
    			"\n9)Guardar en el archivo csv(binario)."//OK
    			"\n10)Salir.",//OK
				"\nERROR!",1,10,4)==0)
    	{
    		switch(opcion)
    		{
    			case 1:
    				controller_loadFromText("data.csv",listaPasajeros);
    				break;
    			case 2:
    				controller_loadFromBinary("dataBin.csv",listaPasajeros);
    				break;
    			case 3:
    				controller_addPassenger(listaPasajeros,&idAux);
    				break;
    			case 4:
    				controller_editPassenger(listaPasajeros);
    				break;
    			case 5:
    				controller_removePassenger(listaPasajeros);
    				break;
    			case 6:
    				controller_ListPassenger(listaPasajeros);
    				break;
    			case 7:
    				controller_sortPassenger(listaPasajeros);
    				break;
    			case 8:
    				controller_saveAsText("data.csv",listaPasajeros);
    				break;
    			case 9:
    				controller_saveAsBinary("dataBin.csv",listaPasajeros);
    				break;
    			case 10:
    				controller_deleteAll(listaPasajeros);
    				break;
    		}


    	}
    }while(opcion!=10);

    return 0;
}
