//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
 * Panel DEMOSTRATIVO de ENTRADAS y SALIDAS EN ARDUINO
 * 
 * ENTRADAS:
 * Boton selector - D2 conectada a una resistencia de PULL UP
 * Potenciometro - A0
 * US - D10 (Pin ECHO y TRIG deben estar unidas)
 * Pulsador + - D1
 * Pulsador - - D0
 * Sensor Luz - A1
 * 
 * SALIDAS:
 * Boton selector + D3 conectada a una resistencia de PULL UP
 * Buzzer - D6
 * LCD - A4 (SDA) y A5 (SCL)
 * LED - D5
 * Servomotor - D7
 * 
 * TIRAS LED entradas: D8, D9, D4, D11
 * TIRAS LED salidas: D12, D13, A2, A3
 */
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// librerias
//
#include <NewPing.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <TonePlayer.h>
//
// interrupciones
//
volatile int IndiceEnt = 0;  //determina que entrada esta activa
volatile int IndiceSal = 0;  //determina que salida esta activa
const int interrupEnt = 2;
const int interrupSal = 3;
//
// entradas
// seteo potenciometro
int entPot = A0 ;
int valPot;
int posPot;
// seteo US
const int UltrasonicPin = 10;
const int MaxDistance = 200;
NewPing sonar(UltrasonicPin, UltrasonicPin, MaxDistance);
int disUS;
int valUS;
//
int entPUL_MAS = 0;
int entPUL_MENOS = 1;
int cont = 0;
int entSenLuz = A1;
int valSenLuz = 0;
int valSenLuzConv = 0;
int sonido = 0;   // se usa en los botones + y -
int luz= 0;   // se usa en los botones + y -
int ang = 0; // se usa en los botones + y -
//
// salidas
// seteo BUZZER
int salBuzzer = 6;
TonePlayer tone1(TCCR1A, TCCR1B, OCR1AH, OCR1AL, TCNT1H, TCNT1L);
//const int tonos[12] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494};
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Inicia el LCD en la dirección 0x27, con 16 caracteres y 2 líneas
int salLED = 5;
Servo myservo;  // crea el objeto servo 
int posServo = 0;    // posicion del servo
int salServomotor = 7;
//
// indicadores de seleccion
int ledEnt1 = 8;
int ledEnt2 = 9;
int ledEnt3 = 4;
int ledEnt4 = 11;
int ledSal1 = 12;
int ledSal2 = 13;
int ledSal3 = A2;
int ledSal4 = A3;
//
const int timeThreshold = 400;
long startTime = 0;
//
void setup() {
  Serial.begin(9600);
// seteo de interrupciones
//attachInterrupt(digitalPinToInterrupt(2), eligeEnt, FALLING);
//attachInterrupt(digitalPinToInterrupt(3), eligeSal, FALLING);
// seteo de entradas y salidas
pinMode(interrupEnt,INPUT);
pinMode(interrupSal,INPUT);
pinMode(entPot,INPUT);
pinMode(entPUL_MAS,INPUT);
pinMode(entPUL_MENOS,INPUT);
pinMode(entSenLuz,INPUT);
pinMode(salBuzzer,OUTPUT);
lcd.begin();                      
pinMode(salLED,OUTPUT);
pinMode(ledEnt1,OUTPUT);
pinMode(ledEnt2,OUTPUT);
pinMode(ledEnt3,OUTPUT);
pinMode(ledEnt4,OUTPUT);
pinMode(ledSal1,OUTPUT);
pinMode(ledSal2,OUTPUT);
pinMode(ledSal3,OUTPUT);
pinMode(ledSal4,OUTPUT);
myservo.attach(salServomotor);  // vincula el servo al pin digital salServomotor
}

void loop() {
if(digitalRead(interrupEnt) == LOW){
// ANTIREBOTE POR SOFTWARE
   if (millis() - startTime > timeThreshold){
      startTime = millis();
   }
  IndiceEnt++;
  if(IndiceEnt>= 4){IndiceEnt = 0;}
  while(digitalRead(interrupEnt) == LOW){}
  }
//  
if(digitalRead(interrupSal) == LOW){
// ANTIREBOTE POR SOFTWARE
   if (millis() - startTime > timeThreshold){
      startTime = millis();
   }
  IndiceSal++;
  if(IndiceSal>= 4){IndiceSal = 0;}
  while(digitalRead(interrupSal) == LOW){}  
  }
//
if((IndiceEnt == 0)&&(IndiceSal == 0)){funcion00();}
if((IndiceEnt == 0)&&(IndiceSal == 1)){funcion01();}
if((IndiceEnt == 0)&&(IndiceSal == 2)){funcion02();}
if((IndiceEnt == 0)&&(IndiceSal == 3)){funcion03();}
//
if((IndiceEnt == 1)&&(IndiceSal == 0)){funcion10();}
if((IndiceEnt == 1)&&(IndiceSal == 1)){funcion11();}
if((IndiceEnt == 1)&&(IndiceSal == 2)){funcion12();}
if((IndiceEnt == 1)&&(IndiceSal == 3)){funcion13();}
//
if((IndiceEnt == 2)&&(IndiceSal == 0)){funcion20();}
if((IndiceEnt == 2)&&(IndiceSal == 1)){funcion21();}
if((IndiceEnt == 2)&&(IndiceSal == 2)){funcion22();}
if((IndiceEnt == 2)&&(IndiceSal == 3)){funcion23();}
//
if((IndiceEnt == 3)&&(IndiceSal == 0)){funcion30();}
if((IndiceEnt == 3)&&(IndiceSal == 1)){funcion31();}
if((IndiceEnt == 3)&&(IndiceSal == 2)){funcion32();}
if((IndiceEnt == 3)&&(IndiceSal == 3)){funcion33();}
}
//
void eligeEnt(){
// ANTIREBOTE POR SOFTWARE
   if (millis() - startTime > timeThreshold){
      startTime = millis();
   }
//   
    IndiceEnt++;
    if(IndiceEnt >= 4){IndiceEnt = 0;}      
/*
    Serial.print("Ent ");
    Serial.println(IndiceEnt);
    while(digitalRead(2) == LOW){}
    delay(200);
*/
  }
//  
void eligeSal(){
// apago todas las salidas antes de que se seleccione una
/*
  lcd.clear();                      // limpia pantalla
  lcd.noBacklight();                // apaga pantalla
  digitalWrite(salBuzzer, LOW);     // apaga buzzer
  digitalWrite(salServomotor, LOW); // apaga servomotor
  digitalWrite(salLED, LOW);        // apaga led
*/
//  
// ANTIREBOTE POR SOFTWARE
   if (millis() - startTime > timeThreshold){
      startTime = millis();
   }
//   
    IndiceSal++;
    if(IndiceSal >= 4){IndiceSal = 0;}        
/*    Serial.print("Sal ");
    Serial.println(IndiceSal);
    while(digitalRead(3) == LOW){}
    delay(200);
*/
  }  
