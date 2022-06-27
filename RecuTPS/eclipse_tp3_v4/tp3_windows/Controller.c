#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "utn.h"
/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    FILE* pArchivo = NULL;

    if(pArrayListPassenger!=NULL && path != NULL)
    {
    	pArchivo = fopen(path,"r");
    	if(pArchivo!=NULL)
    	{
    		retorno = parser_PassengerFromText(pArchivo , pArrayListPassenger);
    		if(retorno == 0)
    		{
    			printf("\nCargado de archivo exitoso!");
    		}
    	}
    	else
    	{
    		printf("\nNO SE ENCONTRO EL ARCHIVO!");
    	}
    }
	return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	FILE* pArchivo = NULL;

	 if(pArrayListPassenger!=NULL && path != NULL)
	 {
		 pArchivo = fopen(path,"rb");
		 if(pArchivo!=NULL)
		 {
			 retorno = parser_PassengerFromBinary(pArchivo , pArrayListPassenger);
			 if(retorno == 0)
			 {
				 printf("\nCargado de archivo exitoso!");
			 }
		 }
		 else
		 {
			 printf("\nNO SE ENCONTRO EL ARCHIVO!");
		 }
	 }
		return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger,int* idControl)
{
	int retorno = -1;
	Passenger* aux;

	int bufId;
	char bufName[50];
	char bufApellido[50];
	float bufPrice;
	char bufCode[7];
	int bufType;
	char bufcType[50];
	char bufStatus[21];
	if(pArrayListPassenger!=NULL)
	{
		if(utn_getStr(bufName,"\nIngrese el nombre: ","\nERROR!",50,3)==0 &&
				utn_getStr(bufApellido,"\nIngrese el Apellido: ","\nERROR!",50,3)==0 &&
				utn_pedirFloat(&bufPrice, "\nIngrese el precio: ","\nERROR!", 1,9999999,3)==0 &&
				utn_myGets(bufCode,"\nCodigo de vuelo: ",8)==0 &&
				utn_getStr(bufStatus,"\nEscriba el estado de su vuelo: ","\nERROR!",21,3)==0 &&
				utn_pedirInt(&bufType,"\nTipo de pasajero: \n1)Economy.\n2)Executive.\n3)FirstClass.","\nERROR!",1,3,3)==0)
		{
			*idControl+=1;
			bufId = *idControl;

			if(bufType==1){
				strcpy(bufcType,"EconomyClass");
			}else if(bufType==2){
				strcpy(bufcType,"ExecutiveClass");
			}else{
				strcpy(bufcType,"FirstClass");
			}

			aux = Passenger_newParametros(bufId,bufName,bufApellido,bufPrice,bufcType,bufCode,bufStatus);
			if(aux!=NULL){
				ll_add(pArrayListPassenger,aux);
				retorno = 0;
			}


		}
	}

    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
   int retorno = -1;
   int idToModify=-1;
   int actualId=-1;
   int tam = -1;
   //int aux;
   int opcion;

   Passenger* auxp = NULL;

   char nombre[50];
   char apellido[50];
   float precio;
   char codigo[7];
   int clase;
   char tipo[21];
   char estado[21];

   if(pArrayListPassenger!=NULL)
   {
	   tam = ll_len(pArrayListPassenger);
	   if(utn_pedirInt(&idToModify,"\nIngrese el ID para MODIFICAR: ","\nERROR",1,9999,3)==0)
	   {
		   for(int i=0;i<tam;i++){
			   auxp=ll_get(pArrayListPassenger,i);
			   Passenger_getId(auxp,&actualId);
			   if(actualId==idToModify){

				   if(utn_pedirInt(&opcion,"MODIFICAR:\n1)Nombre\n2)Apellido\n3)Precio\n4)Codigo\n5)Clase\n6)Estado","\nERROR!",1,6,4)==0)
				   {
					   switch(opcion)
					   {
					   	   case 1:
					   		   if(utn_getStr(nombre,"\nNuevo nombre: ","\nERROR",50,3)==0){
					   			   Passenger_setNombre(auxp,nombre);
					   			   printf("\nACTUALIZADO OK!");
					   		   }
					   		   break;
					   	   case 2:
					   		   if(utn_getStr(apellido,"\nNuevo Apellido: ","\nERROR",50,3)==0)
					   		   {
					   			   Passenger_setApellido(auxp,apellido);
					   			   printf("\nACTUALIZADO OK!");
					   			}break;
					   	   case 3:
					   		   if(utn_pedirFloat(&precio, "\nIngrese el nuevo precio: ","\nERROR!", 1,9999999,3)==0){
					   			   Passenger_setPrecio(auxp,precio);
					   			   printf("\nACTUALIZADO OK!");
					   		   }break;
					   	   case 4:
					   		   if(utn_myGets(codigo,"\nCodigo de vuelo: ",8)==0){
					   			Passenger_setCodigoVuelo(auxp,codigo);
					   			printf("\nACTUALIZADO OK!");
					   		   }break;
					   	   case 5:
					   		   if(utn_pedirInt(&clase,"\nTipo de pasajero: \n1)Economy.\n2)Executive.\n3)FirstClass.","\nERROR!",1,3,3)==0)
					   		   {
					   			if(clase==1){
					   				strcpy(tipo,"EconomyClass");
					   				}else if(clase==2){
					   				strcpy(tipo,"ExecutiveClass");
					   				}else{
					   				strcpy(tipo,"FirstClass");
					   				}
					   			Passenger_setTipoPasajero(auxp,tipo);
					   		   }break;
					   	   case 6:
					   		   if(utn_getStr(estado,"\nEscriba el estado de su vuelo: ","\nERROR!",21,3)==0)
					   		   {
					   			   Passenger_setEstado(auxp,estado);
					   		   }

					   }

				   }

			   }
		   }
	   }
   }

   return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    int retorno = -1;
	int idToSearch = -1;
	int tempId=-1;
	int tam;
	Passenger* aux;

    if(pArrayListPassenger!=NULL)
    {
    	tam = ll_len(pArrayListPassenger);
    	if(utn_pedirInt(&idToSearch,"\nIngrese el id del pasajero a eliminar: ","\nERROR!",1,9999,4)==0)
    	{
    		for(int i=0;i<tam;i++)
    		{
    			aux=ll_get(pArrayListPassenger,i);
    			Passenger_getId(aux,&tempId);
    			if(tempId==idToSearch)
    			{
    				if(ll_remove(pArrayListPassenger,i)==0)
    				{
    					printf("--------Pasajero eliminado!-------");
    					retorno =0;
    				}else{
    					printf("\nNo se pudo encontrar/eliminar el pasajero");
    					retorno = -1;
    				}
    				break;
    			}
    		}
    	}
    }

	return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* this)
{
	int retorno = -1;
	int tam;
	Passenger* pasajero;
//50 50 7 21
	int bufId;
	char bufNombre[50];
	char bufApellido[50];
	float bufPrecio;
	char bufCode[7];
	char bufTipo[50];
	char bufEstado[21];

	if(this!=NULL)
	{
		tam = ll_len(this);
		for(int i=0;i<tam;i++)
		{
			pasajero = ll_get(this,i);
			if(pasajero!=NULL)
			{//
				Passenger_getId(pasajero,&bufId);
				Passenger_getNombre(pasajero,bufNombre);
				Passenger_getApellido(pasajero,bufApellido);
				Passenger_getPrecio(pasajero,&bufPrecio);
				Passenger_getCodigoVuelo(pasajero,bufCode);
				Passenger_getTipoPasajero(pasajero,bufTipo);
				Passenger_getEstado(pasajero,bufEstado);

				printf("\n-----------------------------"
						"\n|ID: %-10d"
						"\n|NOMBRE: %-10s"
						"\n|APELLIDO: %-10s"
						"\n|PRECIO: %.2f"
						"\n|CODIGO: %-10s"
						"\n|TIPO PASAJERO: %-10s"
						"\n|ESTADO VUELO: %-10s",
						bufId,bufNombre,bufApellido,bufPrecio,bufCode,bufTipo,bufEstado);
			}

		}
		retorno = 0;
		system("PAUSE");
	}


    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
   int retorno = -1;

   if(pArrayListPassenger!=NULL)
   {
	   printf("\nOrdenando...");
	   retorno = ll_sort(pArrayListPassenger,Passenger_sortByName,1);
	   if(retorno == 0)
	   {
		   printf("\nOrdenado completo!");
	   }
   }

   return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
    int retorno = -1;

    int tam=-1;
    FILE* pFile=NULL;
    Passenger* aux;

    int bufId;
    char bufName[50];
    char bufApellido[50];
    float bufPrice;
    char bufCode[7];
    char bufType[15];
    char bufStatus[21];

	if(pArrayListPassenger != NULL && path != NULL)
	{
		pFile = fopen(path,"w");
		if(pFile != NULL)
		{
			tam = ll_len(pArrayListPassenger);
			fprintf(pFile,"id,name,lastname,price,flycode,typePassenger,statusFlight");
			for(int i=0;i<tam;i++)
			{
				aux = ll_get(pArrayListPassenger,i);
				if(aux!=NULL)
				{
					Passenger_getId(aux,&bufId);
					Passenger_getNombre(aux,bufName);
					Passenger_getApellido(aux,bufApellido);
					Passenger_getPrecio(aux,&bufPrice);
					Passenger_getCodigoVuelo(aux,bufCode);
					Passenger_getTipoPasajero(aux,bufType);
					Passenger_getEstado(aux,bufStatus);
					fprintf(pFile,"%d,%s,%s,%.2f,%s,%s,%s\n",bufId,bufName,bufApellido,bufPrice,bufCode,bufType,bufStatus);
				}
			}
			printf("\nGuardado de txt exitoso!");
			retorno = 0;
		}

	}

	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int tam=-1;
	FILE* pFile=NULL;
	Passenger* aux = NULL;

	if(path!=NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path,"wb");
		if(pFile!=NULL)
		{
			tam = ll_len(pArrayListPassenger);
			for(int i=0;i<tam;i++)
			{
				aux = ll_get(pArrayListPassenger,i);
				fwrite(aux,sizeof(Passenger),1,pFile);
			}
			printf("\nGuardado finalizado!");
			retorno = 0;
			if(fclose(pFile)!=0){
				printf("\nError al cerrar el archivo!");
			}
		}
	}

	return retorno;
}

int controller_deleteAll(LinkedList*this)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = ll_deleteLinkedList(this);
	}

	return retorno;
}

