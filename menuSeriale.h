#ifndef menuSeriale_h
#define menuSerale_h


#include "Arduino.h"
#include <EEPROM.h>
#include "Hesston.h"
#include <LiquidCrystal.h>

const int indMemPmin = 1; //indirizzo memoria pmin 2 byte
const int indMemPmax = 3; //indirizzo memora pmax 2 byte

#define defpmin 5     //valori soglia
#define defpmax 200   //valori soglia
#define sensorePressione A1


void menuSeriale(bool *dataAdress,bool *dataPminAdress,bool *dataPmaxAdress,bool *sensoriAdress,LiquidCrystal lcd);

#endif


/*
	--Per utilizzare la funzione menuSeriale dichiarare:
	
	#include "menuSeriale.h"

	//definizione variabili che serviranno alla funzione 
	bool dato = false;
	bool *datoIndirizzo = &dato;
	bool datoPmin = false;
	bool *datoPminIndirizzo = &datoPmin;
	bool datoPmax = false;
	bool *datoPmaxIndirizzo = &datoPmax;
	bool sensori = false;
    bool *sensorIndirizzo = &sensori;

	LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

	--nel setup 

	*datoIndirizzo = false;  //set inzio comunicazione
    *datoPminIndirizzo = false; //set inizio comunicazione
    *datoPmaxIndirizzo = false;  //set inizio comunicazione
	*sensorIndirizzo = false;   //set inizio comunicazione
	lcd.begin(16, 2);// set up the LCD's number of columns and rows
	Serial.begin(9600); // opens serial port, sets data rate to 9600 bps

	--Invocare nel loop la funzione:

	menuSeriale(datoIndirizzo,datoPminIndirizzo,datoPmaxIndirizzo,lcd);

*/