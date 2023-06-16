/*
 * Este sketch incluye las rutinas a ejecutar si se selecciona la entrada 3
 */

void funcion20(){ // PULSADOR + y - - BUZZER
  digitalWrite(ledEnt1,LOW);
  digitalWrite(ledEnt2,LOW);
  digitalWrite(ledEnt3,HIGH);
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
      if(digitalRead(entPUL_MAS) == LOW){
        // ANTIREBOTE POR SOFTWARE
   if (millis() - startTime > timeThreshold){
      startTime = millis();
   }
   while(digitalRead(interrupSal) == LOW){}  
//   
        analogWrite(salBuzzer,sonido);
        sonido = sonido + 10;
        if(sonido > 250){
          sonido = 250;
          }
        }// fin if
      if(digitalRead(entPUL_MENOS) == LOW){
        // ANTIREBOTE POR SOFTWARE
   if (millis() - startTime > timeThreshold){
      startTime = millis();
   }
    while(digitalRead(interrupSal) == LOW){}  
//
        analogWrite(salBuzzer,sonido);
        sonido = sonido - 10;
        if(sonido <= 10){
          sonido = 10;
          }        
        }// fin if
}// fin funcion20()
//
void funcion21(){// PULSADOR + y - - LCD
  digitalWrite(ledEnt1,LOW);
  digitalWrite(ledEnt2,LOW);
  digitalWrite(ledEnt3,HIGH);
  digitalWrite(ledEnt4,LOW);
  digitalWrite(ledSal1,LOW);
  digitalWrite(ledSal2,HIGH);
  digitalWrite(ledSal3,LOW);
  digitalWrite(ledSal4,LOW);
//  
// limpio salidas
  analogWrite(salBuzzer,0);   
//  lcd.noBacklight();  //apaga pantalla
  lcd.clear();  //limpia pantalla
  analogWrite(salLED, 0);
  myservo.write(0);
//
      if(digitalRead(entPUL_MAS) == LOW){
      // ANTIREBOTE POR SOFTWARE
   if (millis() - startTime > timeThreshold){
      startTime = millis();
   }
   while(digitalRead(interrupSal) == LOW){}  
//
          lcd.backlight();  //prende pantalla
          lcd.clear();  //limpia pantalla
          lcd.setCursor(0, 0);
          lcd.print("Boton +");
          delay(100);
        }// fin if
//
      if(digitalRead(entPUL_MENOS) == LOW){
// ANTIREBOTE POR SOFTWARE
   if (millis() - startTime > timeThreshold){
      startTime = millis();
   }
   while(digitalRead(interrupSal) == LOW){}  
//   
          lcd.backlight();  //prende pantalla
          lcd.clear();  //limpia pantalla          
          lcd.setCursor(0, 0);
          lcd.print("Boton -");
          delay(100);
        }// fin if    
}// fin funcion21()
//
void funcion22(){// PULSADOR + y - - LED
  digitalWrite(ledEnt1,LOW);
  digitalWrite(ledEnt2,LOW);
  digitalWrite(ledEnt3,HIGH);
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
      
      if(digitalRead(entPUL_MAS) == LOW){
        // ANTIREBOTE POR SOFTWARE
   if (millis() - startTime > timeThreshold){
      startTime = millis();
   }
   while(digitalRead(interrupSal) == LOW){}  
//   
        analogWrite(salLED,luz);
        luz = luz + 10;
        if(luz > 250){
          luz = 250;
          }
        }// fin if
      if(digitalRead(entPUL_MENOS) == LOW){
    // ANTIREBOTE POR SOFTWARE
   if (millis() - startTime > timeThreshold){
      startTime = millis();
   }
   while(digitalRead(interrupSal) == LOW){}  
//   
        analogWrite(salLED,luz);
        luz = luz - 10;
        if(luz <= 10){
          luz = 10;
          }        
        }// fin if
}// fin funcion22()
//
void funcion23(){// PULSADOR + y - SERVOMOTOR
  digitalWrite(ledEnt1,LOW);
  digitalWrite(ledEnt2,LOW);
  digitalWrite(ledEnt3,HIGH);
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
      if(digitalRead(entPUL_MAS) == LOW){
  // ANTIREBOTE POR SOFTWARE
   if (millis() - startTime > timeThreshold){
      startTime = millis();
   }
   while(digitalRead(interrupSal) == LOW){}  
//   
         myservo.write(ang);
         delay(100);           
        ang = ang + 10;
        if(ang > 170){
          ang = 180;
          }
        }// fin if
      if(digitalRead(entPUL_MENOS) == LOW){
    // ANTIREBOTE POR SOFTWARE
   if (millis() - startTime > timeThreshold){
      startTime = millis();
   }
   while(digitalRead(interrupSal) == LOW){}  
//   
         myservo.write(ang);
         delay(100);           
        ang = ang - 10;
        if(ang <= 10){
          ang = 10;
          }        
        }// fin if    
}// fin funcion23()
