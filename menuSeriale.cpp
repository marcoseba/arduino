
//questa funzione realizza un menù seriale con diversi comandi e la 
//possibilità di memorizzare dati in memoria eeprom

#include "menuSeriale.h"
#include "Arduino.h"
#include "Hesston.h"
#include <EEPROM.h>
#include <LiquidCrystal.h>


void menuSeriale(bool *dataAdress,bool *dataPminAdress,bool *dataPmaxAdress,LiquidCrystal lcd){


  int pmax = 0; //varibili interne 
  int pmin = 0;
  String a;
  
  
  while(Serial.available())  //entro nel ciclo se è arrivato un dato da seriale
  {

    a = Serial.readStringUntil('\n');// striga letta da seriale


    //CARICAMENTO DATI IN MEMORIA
    if((*dataAdress == true) && a != NULL )
    {
      *dataAdress = false; //Reset
    
      if(*dataPmaxAdress == true)  //elabrazione pmax
      {
        *dataPmaxAdress = false;  //Reset 
      
        pmax = a.toInt();
        if( pmax > defpmin && pmax < defpmax ) //controllo sul range
        {
          EEPROMWriteInt(indMemPmax,pmax);  //scrivi in memoria
          Serial.println(pmax);            //visualizza
          lcd.setCursor(0,2);
          lcd.print(pmax);
        }
        else
        {  
          Serial.println("errore valore");
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("err valore");
        }
      }
      if(*dataPminAdress == true)    //elaborazione pmin
      {
        *dataPminAdress = false;   //reset
        pmin = a.toInt();
        if( pmin > defpmin && pmin < defpmax ) //controllo che il range sia corretto 
        {
          EEPROMWriteInt(indMemPmin,pmin);  //scrivi in memoria 
          Serial.println(pmin);
          lcd.setCursor(0,2);
          lcd.print(pmin);
        }
        else
        {  
          Serial.println("errore valore");
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("err valore");
        }
      }
      break;
    }


    //MENU SERIALE 
    if(a.equals("pmin")&&(*dataAdress==false))
    {
      Serial.println("inserire pressione minima"); 
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Imp pres min");
    
      *dataAdress = true; //sto aspettando un dato 
      *dataPminAdress = true;
    
    }else if(a.equals("pmax")&&(*dataAdress==false))
    {
      Serial.println("inserire pressione massima");  
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Imp pres max");
    
      *dataAdress = true; //sto aspettando un dato 
      *dataPmaxAdress = true;
    
    }else if(a.equals("help")&&(*dataAdress==false))
    {
      Serial.println("comandi:\n -pmin \n -pmax");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Help");
  
    }else //tutti gli altri casi
    {
      pmin = EEPROMReadInt(indMemPmin);
      pmax = EEPROMReadInt(indMemPmax);
      Serial.println("invalid input!"); 
      Serial.println("-pmin impostato  ");
      Serial.print(pmin);
      Serial.println("\n-pmax impostato  ");
      Serial.print(pmax);
      Serial.print('\n');
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("pres min ");
      lcd.setCursor(10,0);
      lcd.print(pmin);
      lcd.setCursor(0,1);
      lcd.print("pres max");
      lcd.setCursor(10,1);
      lcd.print(pmax);
    }

  }
  
}