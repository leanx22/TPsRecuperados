/*
 * ArrayPassenger.h
 *
 *  Created on: 10 may. 2022
 *      Author: Leandro
 */

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	int passengerType;
	int statusFlight;
	int isEmpty;
}ePassenger;

typedef struct
{
	int passengerType;
	char desc[21];
}eTypes;

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#endif /* ARRAYPASSENGER_H_ */

/// @brief this function put the flag isEmpty to TRUE in avery Array position.
/// @param list Pointer to array of passenger.
/// @param len Array length.
/// @return	(-1) if error, (0) if ok.
int initPassengers(ePassenger* list, int len);

/// @brief Searches for the first empty position in the list, and then if it has
/// an available space the values received as parameters will be added.
/// @param list passenger*
/// @param len int
/// @param id int
/// @param name[] char
/// @param lastName[] char
/// @param price float
/// @param passengerType int
/// @param flycode[] char
/// @return int return (-1) if Error or without free space - (0) if ok.
int addPassenger(ePassenger* list, int len, int id, char name[],
char lastName[], float price, int passengerType, char flycode[],int status ,int index);

/// @brief Find a passenger by Id and returns (by pointer) the index position in array.
///
/// @param list
/// @param len
/// @param id The id to search.
/// @param pindex pointer to int where the index will be stored.
/// @return returns 0(OK) or -1(NULL or CANT FIND ID).
int findPassengerById(ePassenger*list,int len,int id,int*pindex);

/// @brief Remove a passenger by Id (change isEmpty flag to 1).
/// @param list Passenger*
/// @param len int
/// @param id int
/// @return Returns (-1) if Error(incorrect lenght/NULL/or cant find passenger) - (0) if OK.
int removePassenger(ePassenger*list,int len, int id);

/// @brief Sort the elements in the array, the arg order indicate UP or DOWN order
///Its used to order alphabetically (by last name) every passenger and if two of them are EQUALS
/// THEN orders by passengerType.
/// @param list
/// @param len
/// @param order 1(a to Z) or 0(Z to a).
/// @return returns -1(invalid lenght or NULL) if error or 0 if OK
int sortPassengers(ePassenger*list,int len, int order);

/// @brief Print the content of passengers array with table/list style.
///
/// @param list passenger list array
/// @param tList passenger types array.
/// @param len lenght of passengers array.
/// @param typesLen lenght of passengersType array
/// @return (0) if OK or (-1) if NULL or invalid lenghts
int printPassengers(ePassenger*list,eTypes* tList,int len,int typesLen);

/// @brief Sort the elements in the array of passengers, the argument order indicates
/// UP or DOWN order.
/// @param list
/// @param len
/// @param  Order 1(Sort by flightCode alphabetically numbers->a->Z).
/// 		Order 0(Sort by flightCode alphabetically Z->a->numbers).
/// 		IF EQUALS then sort by status(always prioritizing ACTIVE flights).
/// @return Returns 0(if OK) or (-1)if NULL pointer or invalid lenght.
int sortPassengersByCode(ePassenger*list, int len, int order);


/// @brief work as a controller, it ask for all the data and validate it
/// if its all OK then increment the id ant calls addPassenger.
/// @param list
/// @param len
/// @param idCounter pointer to IDcontroller.
/// @return Returns 0(if OK) or -1(NULL pointers or invalid lenght)
int newPassenger(ePassenger*list,int len, int*idCounter);

/// @brief Allows to modify any data of the passenger in that index
/// with a subMenu.
/// @param list
/// @param index
/// @return -1(if NULL or incorrect INDEX) or 0(if OK).
int modifyPassenger(ePassenger*list,int index);

/// @brief
///
/// @param list
/// @param len
/// @param pTotal Pointer where the total of all prices will be saved.
/// @param pAverage  Pointer where average price will be savbed.
/// @param pExceed	 Pointer where the amount of passengers who exceed the average price will be saved.
/// @return returns 0(if OK) or -1(if NULL pointers or invalid lenght)
int priceCalc(ePassenger*list, int len,float*pTotal,float*pAverage,int*pExceed);

/// @brief A little function to avoid use system("PAUSE").
/// it have the same utility.
/// @return always 0.
int Pause(void);
