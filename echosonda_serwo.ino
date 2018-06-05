//dokonuje pomiar i zwraca odległość w centymetrach
int dystans(){
    // impuls 10 us wyzwalający pomiar odległości na pinie TRIG
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  // pomiar czasu trwania impulsu na pinie ECHO [us]
  duration = pulseIn(EchoPin, HIGH);
 
  // obliczenie odległości w cm
  //distance = duration/58;
  distance= duration*0.034/2;
  //if(distance > 221)return 0;
  return distance;
}

//zwraca sądę w odpowiednim kierunku i robi pomiar
byte pomiar(){
  serwomechanizm.write(90);
  delay(300);
  prosto = dystans();
  serwomechanizm.write(0);
  delay(300);
  prawo = dystans();
  serwomechanizm.write(179);
  delay(300);
  lewo = dystans();
  if(prosto > prawo & prosto > lewo)kierunek = 1;
  else if(prawo > lewo & prawo > prosto) kierunek = 2;
  else if(lewo > prawo & lewo > prosto) kierunek = 3;
  return kierunek;
}
byte pomiar12(){
  prosto = 0;
  prawo = 0;
  lewo = 0;
  zawroc = 0;
  
  serwomechanizm.write(90);
  delay(300);
  if(dystans()<10)prosto+=random(0), zawroc+=random(1, 2);
  if(dystans()<30 & dystans()>10)prosto+=random(3, 5), zawroc+=random(1, 2);
  if(dystans()> 30) prosto+=random(5, 10), zawroc+=random(1, 2);
  
  serwomechanizm.write(0);
  delay(300);
  if(dystans()<10)prawo+=random(0), zawroc+=random(1, 2);
  if(dystans()<30 & dystans()>10)prawo+=random(3, 5), zawroc+=random(1, 2);
  if(dystans()> 30) prawo+=random(5, 10), zawroc+=random(1, 2);
  
  serwomechanizm.write(179);
  delay(300);
  if(dystans()<10)lewo+=random(0), zawroc+=random(1, 2);
  if(dystans()<30 & dystans()>10)lewo+=random(3, 5), zawroc+=random(1, 2);
  if(dystans()> 30) lewo+=random(5, 10), zawroc+=random(1, 2);
  
  if(prosto > prawo & prosto > lewo & prosto > zawroc)kierunek = 1;
  else if(prawo > lewo & prawo > prosto & prawo > zawroc) kierunek = 2;
  else if(lewo > prawo & lewo > prosto & lewo > zawroc) kierunek = 3;
  else if(zawroc > prawo & zawroc > prosto & zawroc > lewo) kierunek = 4;
  return kierunek;
}

//robi wiele pomiarów i wysyła je do tabdystans[]
byte pomiar2(){
  int dystanss;  //zmienna pomocnicza do której zapisujemy dystans echosondy
    serwomechanizm.write(0);
    delay(500);
    for(byte i = 0;i<180;i++){
      if(i < 181 ) serwomechanizm.write(i);
      delay(30);
      dystanss = dystans();
      tabdystans[i] = dystanss;
      Serial.print(i);
      Serial.print(",");
      Serial.print(dystanss);
      Serial.print(".");    
    }
 // delay(10000);

    for(byte i = 180;i>0;i--){
      if(i < 181 ) serwomechanizm.write(i);
      delay(30);
      dystanss = dystans();
     // tabdystans[i] = dystanss;
      Serial.print(i);
      Serial.print(",");
      Serial.print(dystanss);
      Serial.print(".");
      
    }
   // delay(10000);
}

byte pomiar3(){
  int dystanss;  //zmienna pomocnicza do której zapisujemy dystans echosondy
    serwomechanizm.write(0);
    delay(500);
    for(byte i = 0;i<180;i++){
      if(i < 181 ) serwomechanizm.write(i);
      delay(30);
      dystanss = dystans();
      tabdystans[i] = dystanss;
      Serial.print(i);
      Serial.print(",");
      Serial.print(dystanss);
      Serial.print(".");    
    }
}

byte interpretacja(){
  for(int i; i<181; i++){
    /// 10 cm ////////////////////////////////////////////////////
    if(i>45 & i<135 & tabdystans[i]< 10) zawroc=random(5, 10);
    if(i>0 & i<90 & tabdystans[i]< 10) lewo=random(5, 10);
    if(i>90 & i<180 & tabdystans[i]< 10) prawo=random(5, 10);
    else prosto = random(0, 5);
    /// 20 cm ////////////////////////////////////////////////////
    if(i>45 & i<135 & tabdystans[i]< 20) zawroc=random(3, 5);
    if(i>0 & i<90 & tabdystans[i]< 20) lewo=random(2, 5);
    if(i>90 & i<180 & tabdystans[i]< 20) prawo=random(2, 5);
    else prosto = random(0, 5);
    // 40 cm ////////////////////////////////////////////////////
    if(i>45 & i<135 & tabdystans[i]< 40) zawroc=random(3, 5);
    if(i>0 & i<90 & tabdystans[i]< 40) lewo=random(2, 5);
    if(i>90 & i<180 & tabdystans[i]< 40) prawo=random(2, 5);
    else prosto = random(3, 7);
  }
  //////////////wybór kierunku
  if(prosto > prawo & prosto > lewo & prosto > zawroc)kierunek = 1;
  else if(prawo > lewo & prawo > prosto & prawo > zawroc) kierunek = 2;
  else if(lewo > prawo & lewo > prosto & lewo > zawroc) kierunek = 3;
  else if(zawroc > prawo & zawroc > prosto & zawroc > lewo) kierunek = 4;
  return kierunek;
}
