/*
 ============================================================================
 Name        : RecuTP2.c
 Author      : Guia Leandro
 Version     :
 Copyright   :
 Description : ABM
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "ArrayPassenger.h"

#define TAM 2000
#define PASSENGER_TYPES 4

int main(void)
{
	setbuf(stdout, NULL);
	int control = 1;
	int option;

	int id=100;
	int auxIndex;
	int idToSearch;

	float totalPrice=0;
	float averagePrice=0;
	int exceedAverage = 0;

	int flagFirstAdd = -1;

	ePassenger pList[TAM];
	eTypes pTypes[PASSENGER_TYPES]={{1,"Minor"},
									{2,"Student"},
									{3,"Regular"},
									{4,"Retired"}};

	initPassengers(pList,TAM);

	do
	{
		system("CLS");
		if(utn_pedirInt(&option,"MENU:\n1)NEW.\n2)MODIF.\n3)DELETE.\n4)INFORM.\n5)EXIT.","\nERROR, TRY AGAIN:",1,5,3)==0)
		{
			switch(option)
			{
			case 1:
				if(newPassenger(pList,TAM,&id)==0)
				{
					flagFirstAdd=0;
				}

				break;
			case 2:
				if(flagFirstAdd==0)
				{
					if(utn_pedirInt(&idToSearch,"ID of the passenger to modify: ","ERROR",101,2101,3)==0 &&
							findPassengerById(pList,TAM,idToSearch,&auxIndex)==0)
					{
						modifyPassenger(pList,auxIndex);
					}
					else
					{
						printf("\nthere was an error!, maybe cant find the id or NULL pointer...\n");
						Pause();
					}
				}
				else
				{
					printf("\nYou need to ADD at least ONE passenger!");
					Pause();
				}
				break;
			case 3:
				if(flagFirstAdd==0)
				{
					if(utn_pedirInt(&auxIndex,"ID of the passenger to DELETE: ","ERROR",101,2101,3)==0 &&
						removePassenger(pList,TAM,auxIndex)==0)
					{
						printf("\nPassenger deleted OK!\n");
						Pause();
					}
					else
					{
						printf("\nThere was an error, maybe cant find ID, too many retries or NULL pointer\n");
						Pause();
					}
				}else
				{
					printf("\nYou need to ADD at least ONE passenger!");
					Pause();
				}
				break;
			case 4:
				if(flagFirstAdd==0)
				{
					system("CLS");
					if(utn_pedirInt(&option,"1)Sort alphabetical by lastname UP. (if equals then by type)."
							"\n2)Sort alphabetical by lastname DOWN. (if equals then by type)."
							"\n3)Total and average of prices + how many passengers exceed that average."
							"\n4)Sort by code UP(if equals then by STATUS).\n"
							"\n5)Sort by code DOWN(if equals then by STATUS).\n","ERROR",1,5,3)==0)
					{
						switch(option)
						{
							case 1:
								sortPassengers(pList,TAM, 1);
								printPassengers(pList,pTypes,TAM,PASSENGER_TYPES);
								Pause();
								break;

							case 2:
								sortPassengers(pList,TAM, 1);
								printPassengers(pList,pTypes,TAM,PASSENGER_TYPES);
								Pause();
								break;
							case 3:
								priceCalc(pList,TAM,&totalPrice,&averagePrice,&exceedAverage);
								system("CLS");
								printf("\nTotal of prices: %.2f",totalPrice);
								printf("\nAverage of prices: %.2f",averagePrice);
								printf("\nPassengers that exceed average price: %d",exceedAverage);
								Pause();
								break;
							case 4:
								sortPassengersByCode(pList,TAM, 1);
								printPassengers(pList,pTypes,TAM,PASSENGER_TYPES);
								Pause();
								break;
							case 5:
								sortPassengersByCode(pList,TAM, 0);
								printPassengers(pList,pTypes,TAM,PASSENGER_TYPES);
								Pause();
								break;
							default:
								printf("\nERROR: null pointer or too many tries.\n");
								break;
						}

					}
				}
				else
				{
					printf("\nYou need to ADD at least ONE passenger!");
					Pause();
				}
				break;

			case 5:
				control = 0;
				break;
			}

		}
		else
		{
			printf("\nError, too many retries or NULL in function!.");
			control = 0;
		}

	}while(control==1);

	return 0;
}


