#include <Hesston.h>
#include <menuSeriale.h>
#include <LiquidCrystal.h>

//crea oggetto per lcd
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 


//inizializzaione variabili lettura ingressi digitali

int mem1[4] = {0,0,0,0}; //vettore memoria stato ingressi precedenti usato nella funzione lettura
int ingressi[4] = {0,0,0,0}; //vettore contenente lo stato degli ingressi, da resettare dopo l'uso 
int stato = 0;
int mode = 0; //0->manual mode , 1->auto mode


//inizializzazioni variabili per funzione menuSeriale
bool dato = false;  //set inziale
bool *datoIndirizzo = &dato;
bool datoPmin = false; //set iniziale
bool *datoPminIndirizzo = &datoPmin;
bool datoPmax = false;  //set iniziale
bool *datoPmaxIndirizzo = &datoPmax;
bool sensori = false;
bool *sensorIndirizzo = &sensori;
//const int indMemPmin = 1; //indirizzo memoria pmin 2 byte
//const int indMemPmax = 3; //indirizzo memora pmax 2 byte



void setup() //SETUP GENEREALE LIVELLO HARDWARE
{

  setupIngressi(); //setup ingressi
  
  lcd.begin(16, 2);// set up the LCD's number of columns and rows
  lcd.print("HESSTON 4700");

  digitalWrite(ledv,HIGH);
  digitalWrite(ledr,HIGH);

  //caricare dati da memoria EEPROM

  delay(2000);
  
}


void loop() //loop principale arduino
{
  
 if(mode ==0) //MODO MANUALE 
 {
    // SETUP DEL MODO MANUALE

    *datoIndirizzo = false;  //set inzio comunicazione
    *datoPminIndirizzo = false; //set inizio comunicazione
    *datoPmaxIndirizzo = false;  //set inizio comunicazione
    *sensorIndirizzo = false;   //set inizio comunicazione
    Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Manual mode");
    digitalWrite(ledr,LOW);
    digitalWrite(ledv,HIGH);

    //LOOP DEL MODO MANUALE
    while(mode == 0)
    {
       letturaIngressiDigitali(ingressi,mem1); //legge tutti gli ingressi digitali e aggiorna il vett ingressi
       letturaMode(&ingressi[0],&mode); //controlla se deve cambiare modo 
       menuSeriale(datoIndirizzo,datoPminIndirizzo,datoPmaxIndirizzo,sensorIndirizzo,lcd); //menu per comunicazione seriale
   

      
    }
 }

 
 if(mode == 1) //MODO AUTOMATICO
 {
  //SETUP DEL MODO AUTOMATICO
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Auto mode");
  Serial.end(); //chiude comunicazione seriale
  digitalWrite(ledv,LOW);
  digitalWrite(ledr,HIGH);

  //LOOP DEL MODO AUTOMATICO
  while(mode == 1)
  {
       letturaIngressiDigitali(ingressi,mem1); //legge tutti gli ingressi digitali e aggiorna il vett ingressi
       letturaMode(&ingressi[0],&mode); // controlla se deve cambiare modo
       ///programma controllo pressione !
  }
 }

 
}
