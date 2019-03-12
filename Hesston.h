#ifndef Hesston_h
#define Hesston_h

#include "Arduino.h"

//inizializzazione pin led
const int ledr = 6, ledv = 7;

const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8; //inizializzaione pin lcd 13->giallo, 12->blu, 11->verde, 10->blu 9->viola, 8->grigio
                         

void letturaIngressiDigitali(int* ingressi, int* stato_prec); //funzione che legge gli ingressi digitali 

void letturaMode(int *evento, int *modo); //funzione che cambia il modo operando

void setupIngressi(); //funzione per il setup degli ingressi




#endif