#include <SoftwareSerial.h>
const int dir1PinA = 13;
const int dir2PinA = 12;
const int speedPinA = 10;

const int dir1PinB = 8;
const int dir2PinB = 11;
const int speedPinB = 9;

const int RX = 0;//triger
const int TX = 1;
char a;

void setSpeed(int brzinaL, int brzinaD)
{
  analogWrite (speedPinA, brzinaD);
  analogWrite (speedPinB, brzinaL);
}

void forward()
{
  digitalWrite (dir1PinA, LOW);
  digitalWrite (dir2PinA, HIGH);
  
  digitalWrite (dir1PinB, LOW);
  digitalWrite (dir2PinB, HIGH);
}


void backward()
{
  digitalWrite (dir1PinA, HIGH);
  digitalWrite (dir2PinA, LOW);
  
  digitalWrite (dir1PinB, HIGH);
  digitalWrite (dir2PinB, LOW);
}

void left()
{
  digitalWrite (dir1PinA, HIGH);
  digitalWrite (dir2PinA, LOW);
  
  digitalWrite (dir1PinB, LOW);
  digitalWrite (dir2PinB, HIGH);
}

void right()
{
  digitalWrite (dir1PinA , LOW);
  digitalWrite (dir2PinA, HIGH);
  
  digitalWrite (dir1PinB, HIGH);
  digitalWrite (dir2PinB, LOW);
}

void stop()
{
  digitalWrite (dir1PinA , LOW);
  digitalWrite (dir2PinA, LOW);
  
  digitalWrite (dir1PinB, LOW);
  digitalWrite (dir2PinB, LOW);
}

void setup ()
{
  pinMode (dir1PinA, OUTPUT);
  pinMode (dir2PinA, OUTPUT);
  pinMode (speedPinA, OUTPUT);

  pinMode (dir1PinB, OUTPUT);
  pinMode (dir2PinB, OUTPUT);
  pinMode (speedPinB, OUTPUT);
  pinMode (TX, OUTPUT);
  pinMode (RX, INPUT);    
  Serial.begin(9600);
}

void loop() {
  
  const int lSen = digitalRead(2);
  const int sSen = digitalRead(4);
  const int dSen = digitalRead(7);
  if(Serial.available() > 0){
  a = Serial.read();
  }
  setSpeed(255, 255);
  
  switch(a){
      case '1':
        forward();
        Serial.println("Forward");
        break;
      case '2':
        right();
        Serial.println("Right");
        break;
      case '3':
        backward();
        Serial.println("Backward");
        break;
      case '4':
        left();
        Serial.println("Left");
        break;
      case '5':
        stop();
        Serial.println(a);
        break;
      case '6':
      setSpeed(255, 255);
  if ( sSen == 1 ) {
    if ((lSen == 0) && (dSen == 0)) {
  setSpeed(255, 255);
       forward();
       Serial.println("Forward");
    } else if ((lSen == 1) && (dSen == 0)) {
  setSpeed(220, 255);
       left();
       Serial.println("Left");
    } else if ((lSen == 0) && (dSen == 1)) {
  setSpeed(255, 220);
       right();
       Serial.println("Right");
    }
  } else if (sSen == 0) {
    if ((lSen == 1) && (dSen == 0)) {
  setSpeed(190, 255);
       left();
       Serial.println("Left");
    } else if ((lSen == 0) && (dSen == 1)) {
  setSpeed(255, 190);
       right();
       Serial.println("Right");
    } 
  }
  break;
    }
  }

