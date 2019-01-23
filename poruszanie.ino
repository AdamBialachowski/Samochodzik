
//********************************************************************************
void skretp(int predkosc, int spowolnienie, int czasJazdy){//skręca w prawo. 1 parametr od 20-255 - prędkość
   for(int i = 20; i < predkosc; i++) {     //                2 parametr spowolnienie. sugierowane 0-20
      analogWrite(pp, i);                                   //3 parametr długość jazdu                         
      analogWrite(lt, i);
      delay(spowolnienie);
    }
    delay(czasJazdy);
    digitalWrite(pp, LOW);
    digitalWrite(lt, LOW);
}
//********************************************************************************
void skretl(int predkosc, int spowolnienie, int czasJazdy){//skręca w lewo
     for(int i = 20; i < predkosc; i++) {     
      analogWrite(pt, i);
      analogWrite(lp, i);
      delay(spowolnienie);
    }
    delay(czasJazdy);
    digitalWrite(pt, LOW);
    digitalWrite(lp, LOW);
}
//********************************************************************************
void jedzpro(int predkosc, int spowolnienie, int czasJazdy)//jedzie prosto
{
     for(int i = 20; i < predkosc; i++) {     
      analogWrite(pp, i);
      analogWrite(lp, i+(3));//korekta do jazdy prosto
      delay(spowolnienie);
    }
    delay(czasJazdy);
    digitalWrite(pp, LOW);
    digitalWrite(lp, LOW);
}

//********************************************************************************
void jedzProsto(int predkosc, int spowolnienie)//jedzie prosto
{
     for(int i = 20; i < predkosc; i++) {     
      analogWrite(pp, i);
      analogWrite(lp, i+(3));//korekta do jazdy prosto
      delay(spowolnienie);
    }
}
void hamuj(){
    digitalWrite(pp, LOW);
    digitalWrite(lp, LOW);
}

//********************************************************************************
void jedzGdzieWiecejMjejsca(){
      //delay(1000);
    pomiar();
    if(kierunek == 1)jedzpro(100, 3, 400);
    if(kierunek == 2)skretp(100, 3, 100);
    if(kierunek == 3)skretl(100, 3, 100);
}
void jedzGdzieWiecejMjejsca2(){
      delay(1000);
    //pomiar();
    if(kierunek == 1)jedzpro(100, 3, 400);
    if(kierunek == 2)skretp(100, 3, 100);
    if(kierunek == 3)skretl(100, 3, 100);
    if(kierunek == 4)skretl(100, 5, 180);
}
int prawdopodobienstwoSkrentu(){
  zawroc=random(3, 5);
  return zawroc;
}
//********************************************************************************
void jedzProstoJakMozesz(){
  while(dystans()>20)jedzProsto(70,0);
  hamuj();    
}
void skrecGdziewiecejMjejsca(){
  serwomechanizm.write(0);
  delay(300);
  prawo = dystans();
  serwomechanizm.write(179);
  delay(300);
  lewo = dystans();
  if(prawo>lewo)skretp(100, 3, 100);
  else skretl(100, 3, 100);
  serwomechanizm.write(89);
  delay(300);
}
