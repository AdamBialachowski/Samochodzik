#include <Servo.h> //Biblioteka odpowiedzialna za serwa

// Silnik
#define lp 5 //lewy przód
#define lt 6 //lewy tył
#define pp 11//lewy przód
#define pt 3 //lewy tył

//echosonda
#define TrigPin 4
#define EchoPin 7

//zmienne********************************************************************

//zmienne echosondy
int distance;
long duration = 0;
int prosto, prawo, lewo, zawroc;  //pomiary otoczenia
int tabdystans[180];

//zmienne programu
byte kierunek; //zmienna do wybrania kierunku drogi


//funkcje********************************************************************
Servo serwomechanizm;  //Tworzymy obiekt, dzięki któremu możemy odwołać się do serwa 
int pozycja = 90; //Aktualna pozycja serwa 0-180

 void poruszanie(byte pretkosc, byte en_prawy, byte en_lewy);

//funkcje echosondy i serwa
int dystans();
byte pomiar();

//funkcje ruchu
void skretp();
void skretl();
void jedzpro();
byte interpretacja();


//********************************************************************************
void setup() {
//Serwomechanizm podłączony do pinu 9
  serwomechanizm.attach(9);
  
//porty sterowania silnikiem
  pinMode(lp, OUTPUT);
  pinMode(lt, OUTPUT);
  pinMode(pp, OUTPUT);
  pinMode(pt, OUTPUT);

//porty od echosondy
  Serial.begin (9600);      //komunikacja z kompem do testów
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);



//testy**********************



}

void loop() {
  //Serial.print(prawdopodobienstwoSkrentu());
    //pomiar();
    //interpretacja();
    jedzGdzieWiecejMjejsca();
    //pomiar2();
  //void skretp();

}
//funkcje
