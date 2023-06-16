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
  while((IndiceEnt == 2)&&(IndiceSal == 0)){
      int sonido = 0;
      if(digitalRead(entPUL_MAS)==HIGH){
        analogWrite(salBuzzer,sonido);
        sonido = sonido + 10;
        if(sonido > 250){
          sonido = 250;
          }
        }// fin if
      if(digitalRead(entPUL_MENOS)==HIGH){
        analogWrite(salBuzzer,sonido);
        sonido = sonido - 10;
        if(sonido <= 10){
          sonido = 10;
          }        
        }// fin if
    }// fin while()
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
  while((IndiceEnt == 2)&&(IndiceSal == 1)){
      if(digitalRead(entPUL_MAS)==HIGH){
          lcd.backlight();  //prende pantalla
          lcd.setCursor(2, 0);
          lcd.print("Presionaste Boton");
          lcd.setCursor(0, 6);
          lcd.println(posPot);
          lcd.println("+");          
          delay(100);
        }// fin if
//
      if(digitalRead(entPUL_MENOS)==HIGH){
          lcd.backlight();  //prende pantalla
          lcd.setCursor(2, 0);
          lcd.print("Presionaste Boton");
          lcd.setCursor(0, 6);
          lcd.println(posPot);
          lcd.println("-");          
          delay(100);
        }// fin if    
    }// fin while()
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
  while((IndiceEnt == 2)&&(IndiceSal == 2)){
      int sonido2 = 0;
      if(digitalRead(entPUL_MAS)==HIGH){
        analogWrite(salLED,sonido2);
        sonido2 = sonido2 + 10;
        if(sonido2 > 250){
          sonido2 = 250;
          }
        }// fin if
      if(digitalRead(entPUL_MENOS)==HIGH){
        analogWrite(salLED,sonido2);
        sonido2 = sonido2 - 10;
        if(sonido2 <= 10){
          sonido2 = 10;
          }        
        }// fin if
    }// fin while()
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
  while((IndiceEnt == 2)&&(IndiceSal == 3)){
      int ang = 0;
      if(digitalRead(entPUL_MAS)==HIGH){
         myservo.write(ang);
         delay(100);           
        ang = ang + 10;
        if(ang > 170){
          ang = 180;
          }
        }// fin if
      if(digitalRead(entPUL_MENOS)==HIGH){
         myservo.write(ang);
         delay(100);           
        ang = ang - 10;
        if(ang <= 10){
          ang = 10;
          }        
        }// fin if    
    }// fin while()
}// fin funcion23()
