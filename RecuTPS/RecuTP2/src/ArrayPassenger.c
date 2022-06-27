/*
 * ArrayPassenger.c
 *
 *  Created on: 10 may. 2022
 *      Author: Leandro
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ArrayPassenger.h"
#include "utn.h"


int initPassengers(ePassenger* list, int len)
{
	int ret = -1;

	if(list != NULL && len >0){
		for(int i=0;i<len;i++)
		{
			(*(list+i)).isEmpty=1;
		}
		return 0;
	}

	return ret;
}

int addPassenger(ePassenger* list, int len, int id, char name[],//QUITAR CORCHETES NO OLVIDARME
char lastName[], float price, int passengerType, char flycode[],int status, int index)
{
	int ret = -1;

	if(list != NULL && len>0)
	{
		strcpy((*(list+index)).name,name);
		strcpy((*(list+index)).lastName,lastName);
		strcpy((*(list+index)).flyCode,flycode);
		(*(list+index)).id = id;
		(*(list+index)).price = price;
		(*(list+index)).passengerType = passengerType;
		(*(list+index)).statusFlight = status;
		(*(list+index)).isEmpty = 0;
		ret = 0;
	}

	return ret;
}

int findPassengerById(ePassenger* list, int len, int id,int*pindex)
{
	int ret = -1;

	if(list != NULL && len>0){
		for(int i=0;i<len;i++){
			if((*(list+i)).id==id && (*(list+i)).isEmpty==0){
				*pindex=i;
				ret = 0;
			}
		}
	}

	return ret;
}

int removePassenger(ePassenger*list,int len,int id)
{
	int retAux=-1;
	if(list != NULL && len>0 && id>100)
	{
		for(int i=0;i<len;i++)
		{
			if((*(list+i)).id==id)
			{
				(*(list+i)).isEmpty=1;
				retAux = 0;
				break;
			}
		}
	}

	return retAux;
}

int sortPassengers(ePassenger*list,int len, int order)
{
	int ret = -1;
	ePassenger eAux;

	if(list != NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			for(int j=i+1;j<len;j++)
			{
				if((strcmp((*(list+i)).lastName,(*(list+j)).lastName)>0&&order==1)||
					(strcmp((*(list+i)).lastName,(*(list+j)).lastName)<0&&order==0))
				{
					eAux = (*(list+i));
					(*(list+i)) = (*(list+j));
					(*(list+j)) = eAux;
				}
				else if(strcmp((*(list+i)).lastName,(*(list+j)).lastName)==0&&
						(*(list+i)).passengerType>(*(list+j)).passengerType)
				{
					eAux = (*(list+i));
					(*(list+i)) = (*(list+j));
					(*(list+j)) = eAux;
				}
			}
		}

		ret = 0;
	}
	return ret;
}

int printPassengers(ePassenger*list,eTypes*tList,int len,int typesLen)
{
	int ret = -1;

	if(list != NULL && len>0)
	{
		printf("\n----------------------------------------------------------------------------\n");
		printf("|    ID    |     LAST  NAME     |   PASSENGER TYPE   |   CODE   |   STATUS  |\n");

		for(int i=0;i<len;i++)
		{
			for(int j=0;j<typesLen;j++)
			{
				if((*(list+i)).isEmpty==0 && (*(list+i)).passengerType==(*(tList+j)).passengerType)
				{
					printf("----------------------------------------------------------------------------");
					printf("\n|%10d|%-20s|%20s|%10s|%10d|",(*(list+i)).id,(*(list+i)).lastName,(*(tList+j)).desc,(*(list+i)).flyCode,(*(list+i)).statusFlight);
					printf("\n----------------------------------------------------------------------------\n");
				}
			}
		}
		ret = 0;
	}

	return ret;
}

int sortPassengersByCode(ePassenger*list,int len, int order)
{
	int ret = -1;
	ePassenger eAux;

	if(list != NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			for(int j=i+1;j<len;j++)
			{
				if((strcmp((*(list+i)).flyCode,(*(list+j)).flyCode)>0&&order==1)||
					(strcmp((*(list+i)).flyCode,(*(list+j)).flyCode)<0&&order==0))
				{
					eAux = (*(list+i));
					(*(list+i)) = (*(list+j));
					(*(list+j)) = eAux;
				}
				else if(strcmp((*(list+i)).flyCode,(*(list+j)).flyCode)==0&&
						(*(list+i)).statusFlight<(*(list+j)).statusFlight)
				{
					eAux = (*(list+i));
					(*(list+i)) = (*(list+j));
					(*(list+j)) = eAux;
				}
			}
		}

		ret = 0;
	}
	return ret;
}


int newPassenger(ePassenger* list, int len, int*idCounter)
{
	int ret = -1;
	int index = -1;
	int id;

	char bufName[51];
	char bufLastName[51];
	float bufPrice;
	int bufType;
	char bufFlyCode[10];
	int bufStatus;

	if(list != NULL && len>0){
		for(int i=0;i<len;i++){
			if((*(list+i)).isEmpty==1){
				index = i;
				break;
			}
		}
	}

	if(index != -1){
		system("CLS");
		if(utn_getStr(bufName,"\nNAME: ","\nERROR!",51,3)==0 &&
			utn_getStr(bufLastName,"\nLast name: ","\nERROR!",51,3)==0 &&
			utn_pedirFloat(&bufPrice,"\nPrice: ","\nERROR",1,1000000,3)==0 &&
			utn_pedirInt(&bufType,"\nPassenger Type:\n1)Minor.\n2)Student.\n3)Regular.\n4)Retired.","\nERROR!",1,4,3)==0 &&
			utn_myGets(bufFlyCode,"\nFlycode: ",10)==0 &&
			utn_pedirInt(&bufStatus,"\nFlight status:\n0)CANCELLED.\n1)ACTIVE.","\nERROR!",0,1,3)==0)
		{
			printf("\nworking...");
			*idCounter+=1;
			id = *idCounter;

			if(addPassenger(list,len,id,bufName,bufLastName,bufPrice,bufType,bufFlyCode,bufStatus,index)==0)
			{
				printf("\nPassenger OK! >>NEW ID:%d<<\n",id);
				ret = 0;
				Pause();
			}
		}
		else
		{
			printf("\nThere was an error during data entry!\n");
			Pause();
			fflush(stdin);
			fflush(stdout);
		}

	}else{
		printf("\nNO MORE SPACE!\n");
		Pause();
	}

	return ret;
}

int modifyPassenger(ePassenger*list,int index)
{
	int ret = -1;
	int opcion=-1;
	int control=1;
	char bufFlyCode[10];

	if(list != NULL && index!=-1){

		do{
			system("CLS");
			printf("\n+-------------------MODIFY-------------------+\n");
			printf("ACTUAL DATA:\n1)NAME: %s\n2)LAST NAME: %s\n3)Fly Price: %.2f\n4)Passenger Type: %d\n"
					"5)FlyCode: %s\n6)FlyStatus: %d\n7)Return to menu.",(*(list+index)).name,(*(list+index)).lastName,(*(list+index)).price,
					(*(list+index)).passengerType,(*(list+index)).flyCode,(*(list+index)).statusFlight);

			printf("\n+--------------------------------------------+");
			if(utn_pedirInt(&opcion,"","\nERROR, TRY AGAIN:",1,7,3)==0)
			{
				switch(opcion)
				{
				case 1:
					if(utn_getStr((*(list+index)).name,"\nNew name: ","\nERROR",51,3)==0)
					{
						printf("\nNEW NAME OK!\n");
						Pause();
					}
					break;
				case 2:
					if(utn_getStr((*(list+index)).lastName,"\nNew LAST Name: ","\nERROR",51,3)==0)
					{
						printf("\nNEW LAST NAME OK!\n");
						Pause();
					}
					break;
				case 3:
					if(utn_pedirFloat(&(*(list+index)).price,"\nNew Price: ","\nERROR.",1,1000000,3)==0)
					{
						printf("\nNEW PRICE OK!\n");
						Pause();
					}
					break;
				case 4:
					if(utn_pedirInt(&(*(list+index)).passengerType,"\nNew PassengerType:\n1)Minor.\n2)Student.\n3)Regular.\n4)Retired.","\nERROR",1,4,3)==0)
					{
						printf("\nPASSENGER TYPE UPDATED!\n");
						Pause();
					}
					break;
				case 5:
					if(utn_myGets(bufFlyCode,"\nNew Flycode: ",10)==0)
					{
						strcpy((*(list+index)).flyCode,bufFlyCode);
						printf("\nFLY CODE UPDATED!\n");
						Pause();
					}
					break;
				case 6:
					if(utn_pedirInt(&(*(list+index)).statusFlight,"\nFlight status:\n0)CANCELLED.\n1)ACTIVE. ","\nERROR!",0,1,3)==0)
					{
						printf("\nFLY STATUS UPDATED!\n");
						Pause();
					}
					break;
				case 7:
					control = 0;
					break;
				}
			}
		}while(control == 1);

	}

	return ret;
}

int priceCalc(ePassenger*list, int len,float*pTotal,float*pAverage,int*pExceed)
{
	int ret = -1;
	int counter = 0;
	float totalPrice=0;
	float averagePrice = 0;
	int exceed = 0;

	if(list != NULL && pTotal!=NULL && pAverage!=NULL && len>0)
	{
		for(int i=0;i<len;i++)//Recorro el array y sumo el precio a un contador total y tambien al contador individual.
		{
			if((*(list+i)).isEmpty==0)
			{
				totalPrice+=(*(list+i)).price;
				counter ++;
			}
		}

		averagePrice = totalPrice/counter;

		for(int i=0;i<len;i++) //Recorre el array y si en x indice el campo precio es mayor al precio promedio
		{						//incrementa el contador simple de pasajeros que exceden ese precio
			if((*(list+i)).price>averagePrice && (*(list+i)).isEmpty==0)
			{
				exceed++;
			}
		}

		*pTotal = totalPrice;
		*pAverage = averagePrice;
		*pExceed = exceed;

		ret = 0;
	}
	return ret;
}


int Pause(void)
{
	printf("\n");
	printf("PRESS ANY KEY TO CONTINUE");
	getchar();
	return 0;
}
