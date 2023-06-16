/*
 * Este sketch incluye las rutinas a ejecutar si se selecciona la entrada 1
 */
void funcion00(){   // POTE - BUZZER
  digitalWrite(ledEnt1,HIGH);
  digitalWrite(ledEnt2,LOW);
  digitalWrite(ledEnt3,LOW);
  digitalWrite(ledEnt4,LOW);
  digitalWrite(ledSal1,HIGH);
  digitalWrite(ledSal2,LOW);
  digitalWrite(ledSal3,LOW);
  digitalWrite(ledSal4,LOW);
//
  while((IndiceEnt == 0)&&(IndiceSal == 0)){
        valPot = analogRead(entPot);
        posPot = map(valPot, 0, 1023, 0, 255);  // de 0-1023 a 0-255
        analogWrite(salBuzzer,posPot);
        delay(100); 
  } //fin while
//  
}// fin funcion00
//  
void funcion01(){   // POTE - LCD
  digitalWrite(ledEnt1,HIGH);
  digitalWrite(ledEnt2,LOW);
  digitalWrite(ledEnt3,LOW);
  digitalWrite(ledEnt4,LOW);
  digitalWrite(ledSal1,LOW);
  digitalWrite(ledSal2,HIGH);
  digitalWrite(ledSal3,LOW);
  digitalWrite(ledSal4,LOW);      
//
  while((IndiceEnt == 0)&&(IndiceSal == 1)){
//
          valPot = analogRead(entPot);
          posPot = map(valPot, 0, 1023, 0, 100);  // convertir a porcentaje
          lcd.clear();
//
          lcd.backlight();  //prende pantalla
          lcd.setCursor(2, 0);
          lcd.print("Porcentaje");
          lcd.setCursor(0, 6);
          lcd.println(posPot);
          lcd.println(" %");          
          delay(100);
    }//fin while  
}//fin funcion01()
//
void funcion02(){       // POTE - LED
  digitalWrite(ledEnt1,HIGH);
  digitalWrite(ledEnt2,LOW);
  digitalWrite(ledEnt3,LOW);
  digitalWrite(ledEnt4,LOW);
  digitalWrite(ledSal1,LOW);
  digitalWrite(ledSal2,LOW);
  digitalWrite(ledSal3,HIGH);
  digitalWrite(ledSal4,LOW);      
  while((IndiceEnt == 0)&&(IndiceSal == 2)){
    //
         valPot = analogRead(entPot);
         posPot = map(valPot, 0, 1023, 0, 255);  // convertir a intesidad de luz para PWM
         analogWrite(salLED, posPot);
         delay(100);                  
    }// fin while
  }//fin funcion02()
//
void funcion03(){       // POTE - SERVOMOTOR
  digitalWrite(ledEnt1,HIGH);
  digitalWrite(ledEnt2,LOW);
  digitalWrite(ledEnt3,LOW);
  digitalWrite(ledEnt4,LOW);
  digitalWrite(ledSal1,LOW);
  digitalWrite(ledSal2,LOW);
  digitalWrite(ledSal3,LOW);
  digitalWrite(ledSal4,HIGH);      
  while((IndiceEnt == 0)&&(IndiceSal == 3)){
//
         valPot = analogRead(entPot);
         posPot = map(valPot, 0, 1023, 0, 180);  // convertir a angulo del servomotor
         myservo.write(posPot);
         delay(100);                         
    }// fin while
  }//fin funcion03()
