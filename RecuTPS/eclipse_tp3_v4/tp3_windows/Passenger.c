/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author:
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn.h"
//#include "parser.h"

Passenger* Passenger_new()
{
	return (Passenger*)malloc(sizeof(Passenger));
}
Passenger* Passenger_newParametros(int id, char*nombre,char*apellido,float precio, char* tipo, char*codigo,char* estado)
{
	Passenger* aux = NULL;
	aux = Passenger_new();
	if(aux != NULL)
	{
		/*aux->id=id;
		strncpy(aux->nombre,nombre,50);
		strncpy(aux->apellido,apellido,50);
		aux->precio = precio;
		strncpy(aux->tipoPasajero,tipo,50);
		strncpy(aux->codigoVuelo,codigo,7);
		strncpy(aux->estadoVuelo,estado,21);*/
		Passenger_setId(aux,id);
		Passenger_setNombre(aux,nombre);
		Passenger_setApellido(aux,apellido);
		Passenger_setPrecio(aux,precio);
		Passenger_setTipoPasajero(aux,tipo);
		Passenger_setCodigoVuelo(aux,codigo);
		Passenger_setEstado(aux,estado);
	}

	return aux;
}


int Passenger_setId(Passenger* this,int id)
{
	int retorno = -1;

	if(this != NULL && id>0)//ojo el tema de ids
	{
		this->id = id;
		retorno = 0;
	}

	return retorno;
}
int Passenger_getId(Passenger* this,int* id)
{
	int retorno =-1;
	int bufId=0;

	if(this != NULL && id!=NULL)
	{
		bufId = this->id;
		*id = bufId;
		retorno = 0;
	}

	return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		if(utn_esNombreOapellido(nombre)==1)
		{
			strncpy(this->nombre,nombre,50);
			retorno = 0;
		}else{
			retorno = -1;
		}
	}

	return retorno;
}
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
		{
			strncpy(nombre,this->nombre,50);
			retorno = 0;
		}

	return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno =-1;

	if(this != NULL && apellido != NULL)
	{
		if(utn_esNombreOapellido(apellido)==1){
			strncpy(this->apellido,apellido,50);
			retorno =0;
		}else{
			retorno=-1;
		}
	}
	return retorno;
}
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno = -1;
	if(this != NULL && apellido != NULL)
	{
		strncpy(apellido,this->apellido,50);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;
	if(this != NULL && codigoVuelo != NULL)
	{
		if(utn_esAlfaNumerico(codigoVuelo)==1){
			strncpy(this->codigoVuelo,codigoVuelo,7);
			retorno = 0;
		}else{
			printf("\nEl codigo no es alfanumerico");
			retorno = -1;
		}
	}
	return retorno;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;
	if(this != NULL && codigoVuelo != NULL)
	{
		strncpy(codigoVuelo,this->codigoVuelo,7);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno = -1;

	if(this != NULL && tipoPasajero != NULL)
	{
		strcpy(this->tipoPasajero,tipoPasajero);
		retorno = 0;
	}
	return retorno;
}
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno = -1;
	if(this != NULL && tipoPasajero != NULL)
	{
		strcpy(tipoPasajero,this->tipoPasajero);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno = -1;
	if(this != NULL && precio>0)
	{
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno = -1;
	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 0;
	}
	return retorno;
}

int Passenger_setEstado(Passenger* this, char* estado)
{
	int retorno = -1;
	if(this != NULL && estado != NULL)
	{
		if(utn_esNombreOapellido(estado)==1){
			strncpy(this->estadoVuelo,estado,21);
			retorno = 0;
		}else{
			printf("\nNo se pudo establecer el estado.");
			retorno = -1;
		}

	}

	return retorno;
}
int Passenger_getEstado(Passenger* this, char* estado)
{
	int retorno = -1;
	if(this != NULL && estado != NULL)
	{
		strncpy(estado,this->estadoVuelo,21);
		retorno = 0;
	}

	return retorno;
}

int Passenger_sortByName(void* this,void* this2)
{
	int retorno=0;
	Passenger* p1;
	Passenger* p2;

	char nombre[50];
	char nombreAComp[50];

	p1 = (Passenger*) this;
	p2 = (Passenger*) this2;

	Passenger_getNombre(p1,nombre);
	Passenger_getNombre(p2,nombreAComp);

	if(this != NULL && this2 != NULL)
	{
		if(strcmp(nombre,nombreAComp)>0)
		{
			retorno = 1;
		}else{
			retorno = -1;
		}
	}

	return retorno;
}

