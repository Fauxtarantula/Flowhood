#include <Servo.h>

//#define enA 9
#define in1 6
#define in2 8
#define button 4
#define button2 3
#define pwmPin 7  
//#define enB 10 
#include <Servo.h>


int rotDirection = 0;
int pos = 0;
int s;
int pressed = false;
int pressed2 = false;
Servo spray;
Servo ventservo;
Servo ventservo2;
/*int u = 0 ;
int y = 0;*/

void setup() {
  //pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(button, INPUT);
  pinMode(button2, INPUT);
  //for spray setup
  spray.attach(2);
  //for vents setup
  ventservo.attach(5);
  ventservo.write(90);
  ventservo2.attach(1);
  ventservo2.write(90);
  //for fan setup
  pinMode( pwmPin, OUTPUT);
  spray.write(10);

  /*digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);*/
}
void loop() {
  //Part A doorsystems
  //digitalWrite(enA, 1); 
 
  // Read button - Debounce
  if (digitalRead(button) == true) {
    pressed = !pressed;
  }  
  while (digitalRead(button) == true);
  delay(20);
  
  // button pressed to start motor
  //will change duration accordingly
  if (pressed == true && rotDirection == 0 ) {
    int i = 0;
    ventservo.write(0);//open vent
    ventservo2.write(0);//open vent
    for(i; i<5; i++){
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      delay(500);
      rotDirection = 1;
    }
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    //rotDirection = 1;
  }
  // button to change rotation  direction
  if (pressed == false && rotDirection == 1) {
    int u =0;
    ventservo.write(0);//close vent
    ventservo2.write(0);
    for(u; u<5; u++){
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      delay(500);
    }
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    rotDirection = 0;
  }


  //part B Spray system
  if (digitalRead(button2) == true) {
    pressed2 = !pressed2;
  }  
  while (digitalRead(button2) == true);
  delay(20);
  
 /* if (pressed2 == true && rotDirection == 0) {
    for (pos = 10; pos => 0; pos--) {
      spray.write(pos);
      delay(30*1000);
    }
    for (pos = 0; pos <= 10; pos++) {
      spray.write(pos);
      delay(5);
    }
    for (pos = 10; pos => 0; pos--) {
  }
  */
  //start spray
  if (pressed2 == true) {  //I set the rotdirection to ensure that when the 2nd button is pressed when door is up, it wont spray.
    
      /*for (pos = 10; pos < 35; pos++) {
        spray.write(pos);
        // wait 15 ms for servo to reach the position
        delay(15);
        }
      if( pos = 35) {
        spray.write(10);
        delay(2*1000);
      }*/
       if(s<3){
    // Wait for 15 millisecond(s)
    spray.write(40);
    delay(200);
    spray.write(10);
    // wait 15 ms for servo to reach the position
    delay(20000); 
    s=s+1;
  }
    }
  //reset the spray again
  if(pressed2 == false) { 
    s=0;
    spray.write(5);
    delay(20);
  }

  //part C fan system
  int potValue = analogRead(A0);
  
  int newpotValue = map(potValue, 0, 1023, 0 , 255);
  
  analogWrite(pwmPin, newpotValue);
  
}
