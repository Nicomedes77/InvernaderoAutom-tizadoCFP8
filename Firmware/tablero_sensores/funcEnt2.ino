/*
 * Este sketch incluye las rutinas a ejecutar si se selecciona la entrada 2
 */

 void funcion10(){  // US - BUZZER
  digitalWrite(ledEnt1,LOW);
  digitalWrite(ledEnt2,HIGH);
  digitalWrite(ledEnt3,LOW);
  digitalWrite(ledEnt4,LOW);
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
    delay(50); 
    disUS = sonar.ping_cm();
    valUS = map(disUS,0,200,255,0);
    analogWrite(salBuzzer,valUS);
    delay(100); 
  }//fin funcion10()
//
 void funcion11(){  // US - LCD
  digitalWrite(ledEnt1,LOW);
  digitalWrite(ledEnt2,HIGH);
  digitalWrite(ledEnt3,LOW);
  digitalWrite(ledEnt4,LOW);
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
            delay(50);
//          disUS = sonar.ping_cm();      
//
          lcd.backlight();  //prende pantalla
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Distancia a MANO");
          lcd.setCursor(0, 1);
          lcd.print(sonar.ping_cm());
          lcd.print(" cm");
          delay(500);
  }//fin funcion11()
//  
 void funcion12(){  // US - LED
  digitalWrite(ledEnt1,LOW);
  digitalWrite(ledEnt2,HIGH);
  digitalWrite(ledEnt3,LOW);
  digitalWrite(ledEnt4,LOW);
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
    disUS = sonar.ping_cm();
    valUS = map(disUS,0,200,0,255);
    analogWrite(salLED,valUS);
    delay(100); 
  }//fin funcion12()
//  
 void funcion13(){  // US - SERVOMOTOR
  digitalWrite(ledEnt1,LOW);
  digitalWrite(ledEnt2,HIGH);
  digitalWrite(ledEnt3,LOW);
  digitalWrite(ledEnt4,LOW);
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
         disUS = sonar.ping_cm();
         valUS = map(disUS,0,200,0,180);
         myservo.write(valUS);
         delay(100);                         
//    }//fin while() 
  }//fin funcion13()
