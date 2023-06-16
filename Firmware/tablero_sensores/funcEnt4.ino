/*
 * Este sketch incluye las rutinas a ejecutar si se selecciona la entrada 4
 */

void funcion30(){ // SENSOR LUZ - BUZZER
  digitalWrite(ledEnt1,LOW);
  digitalWrite(ledEnt2,LOW);
  digitalWrite(ledEnt3,LOW);
  digitalWrite(ledEnt4,HIGH);
  digitalWrite(ledSal1,HIGH);
  digitalWrite(ledSal2,LOW);
  digitalWrite(ledSal3,LOW);
  digitalWrite(ledSal4,LOW);  
//
// limpio salidas
//  analogWrite(salBuzzer,0);   
  lcd.noBacklight();  //apaga pantalla
  analogWrite(salLED, 0);
  myservo.write(0);
//  
//  while((IndiceEnt == 3)&&(IndiceSal == 0)){
        valSenLuz = analogRead(entSenLuz);
        valSenLuzConv = map(valSenLuz, 0, 1023, 0, 255);  // de 0-1023 a 0-255
        analogWrite(salBuzzer,valSenLuzConv);
        delay(100); 
//    }//fin while
  }//fin funcion30()
//  
void funcion31(){ // SENSOR LUZ - LCD
  digitalWrite(ledEnt1,LOW);
  digitalWrite(ledEnt2,LOW);
  digitalWrite(ledEnt3,LOW);
  digitalWrite(ledEnt4,HIGH);
  digitalWrite(ledSal1,LOW);
  digitalWrite(ledSal2,HIGH);
  digitalWrite(ledSal3,LOW);
  digitalWrite(ledSal4,LOW);
//
// limpio salidas
  analogWrite(salBuzzer,0);   
//  lcd.noBacklight();  //apaga pantalla
  analogWrite(salLED, 0);
  myservo.write(0);
//    
//  while((IndiceEnt == 3)&&(IndiceSal == 1)){
        valSenLuz = analogRead(entSenLuz);
        valSenLuzConv = map(valSenLuz, 0, 1023, 0, 100);  // de 0-1023 a 0-255
//
          lcd.backlight();  //prende pantalla
          lcd.clear();
          lcd.setCursor(2, 0);
          lcd.print("Cant. de luz");
          lcd.setCursor(0, 6);
          lcd.println(valSenLuzConv);
          delay(100);        
//    }//fin while
  }//fin funcion31()
//
void funcion32(){ // SENSOR LUZ - LED
  digitalWrite(ledEnt1,LOW);
  digitalWrite(ledEnt2,LOW);
  digitalWrite(ledEnt3,LOW);
  digitalWrite(ledEnt4,HIGH);
  digitalWrite(ledSal1,LOW);
  digitalWrite(ledSal2,LOW);
  digitalWrite(ledSal3,HIGH);
  digitalWrite(ledSal4,LOW);
//
// limpio salidas
  analogWrite(salBuzzer,0);   
  lcd.noBacklight();  //apaga pantalla
//  analogWrite(salLED, 0);
  myservo.write(0);
//    
//  while((IndiceEnt == 3)&&(IndiceSal == 2)){
        valSenLuz = analogRead(entSenLuz);
        valSenLuzConv = map(valSenLuz, 0, 1023, 0, 255);  // de 0-1023 a 0-255
         analogWrite(salLED, valSenLuzConv);
         delay(100);                 
//    }//fin while
  }//fin funcion32()
//
void funcion33(){ // SENSOR LUZ - SERVOMOTOR
  digitalWrite(ledEnt1,LOW);
  digitalWrite(ledEnt2,LOW);
  digitalWrite(ledEnt3,LOW);
  digitalWrite(ledEnt4,HIGH);
  digitalWrite(ledSal1,LOW);
  digitalWrite(ledSal2,LOW);
  digitalWrite(ledSal3,LOW);
  digitalWrite(ledSal4,HIGH);
//
// limpio salidas
  analogWrite(salBuzzer,0);   
  lcd.noBacklight();  //apaga pantalla
  analogWrite(salLED, 0);
//  myservo.write(0);
//
//  while((IndiceEnt == 3)&&(IndiceSal == 3)){
        valSenLuz = analogRead(entSenLuz);
        valSenLuzConv = map(valSenLuz, 0, 1023, 0, 180);  // de 0-1023 a 0-180
         myservo.write(valSenLuzConv);
         delay(100);           
//    }//fin while
  } //fin funcion33()
