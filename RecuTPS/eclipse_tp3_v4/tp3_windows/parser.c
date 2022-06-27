#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;


	Passenger* aux = NULL;

	char bufId[10];
	char bufName[50];
	char bufApellido[50];
	float bufPrice;
	char bufCode[7];
	char bufType[15];
	char bufStatus[21];

	if(pArrayListPassenger != NULL && pFile != NULL)
	{
		//LECTURA FANTASMA!//
		fscanf(pFile,"%[^,],%[^,],%[^,],%f,%[^,],%[^,],%[^\n]\n",bufId,bufName,bufApellido,&bufPrice,bufCode,bufType,bufStatus);
		do{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%f,%[^,],%[^,],%[^\n]\n",bufId,bufName,bufApellido,&bufPrice,bufCode,bufType,bufStatus)==7)
			{
				//printf("\nEsto es lo que lei: %s,%s,%s,%.2f,%s,%s,%s",bufId,bufName,bufApellido,bufPrice,bufCode,bufType,bufStatus);
				//system("PAUSE");
				aux = Passenger_newParametros(atoi(bufId),bufName,bufApellido,bufPrice,bufType,bufCode,bufStatus);//ATOI A BUFF STATUS?
				retorno = ll_add(pArrayListPassenger,aux);
			}


		}while(!feof(pFile));
		if(fclose(pFile)!=0)
		{
			printf("\nNo se pudo cerrar el archivo!");
			retorno = -1;
		}
	}

    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	Passenger* aux=NULL;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		retorno = 0;
		do{
			aux = Passenger_new();
			if(aux!=NULL)
			{
				fread(aux,sizeof(Passenger),1,pFile);
				ll_add(pArrayListPassenger,aux);
			}
		}while(!feof(pFile));

		if(fclose(pFile)!=0)
		{
			printf("\nHubo un error al intentar cerral el archivo!");
			retorno = -1;
		}
	}

    return retorno;
}











