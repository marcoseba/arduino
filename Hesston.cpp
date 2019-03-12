
#include "Arduino.h"
#include "Hesston.h"

void letturaIngressiDigitali(int* ingressi, int* stato_prec) //funzione che legge gli ingressi digitali 
{
  // ingressi -> puntatore a un vettore di dimensione opportuna (4) di tipo intero
  //             nel quale la funzione memorizza un evento(fronte discesa o salita)
  //             dei pin digitali che si vuol far leggere; 
  //             solitamente resettare l evento una volta letto
  // 
  // stato_prec -> puntatore a un vettore della stessa dimensione del precedente 
  //               serve alla funzione come memoria. (non di interesse per l'uso)

  //set pin digitali lettura
  int in5 = digitalRead(5); //pulsante scheda cambio modo
  int in4 = digitalRead(4); 
  int in3 = digitalRead(3); 
  int in2 = digitalRead(2); 
  
  if((in5 == LOW)&&(stato_prec[0] == HIGH)) //lettura su fronte di discesa
      ingressi[0] = 1; //set
   stato_prec[0] = in5;

  if((in4 == HIGH)&&(stato_prec[1] == LOW)) //lettura su fronte di salita
      ingressi[1] = 1; //set
   stato_prec[1] = in4;

  if((in3 == HIGH)&&(stato_prec[2] == LOW)) //lettura su fronte di salita
      ingressi[2] = 1; //set
   stato_prec[2] = in3;

  if((in2 == HIGH)&&(stato_prec[3] == LOW)) //lettura su fronte di salita
      ingressi[3] = 1; //set
   stato_prec[3] = in2;
    
    delay(2);//ritardo per rimbalzi
  
  
}

void letturaMode(int *evento, int *modo) //funzione che cambia il modo operando
{
    // questa funzione "switch" il contenuto della variabile mode quando si ha un avento
    // evento -> puntatore alla variabile che contiene l'evento che si vuol fare leggere alla funzione 
    // modo -> puntatore alla variabile modo 

    if(*evento == 1)
    {
    *modo = 1 - *modo; // swith modo
    *evento = 0; //reset
    }
}

void setupIngressi()
{
  //porte ingressi digitali
  pinMode(5,INPUT);
  pinMode(4,INPUT);
  pinMode(3,INPUT);
  pinMode(2,INPUT);


  pinMode(ledr,OUTPUT); //led rosso
  pinMode(ledv,OUTPUT); //led verde

}