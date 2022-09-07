/* Sweep--try the servo motor coding
 *  Modified 05Sept2021
 *  Whitney Blackburn-Lynch
 */

 #include <Servo.h>

 Servo servomicro; //servo that is 180 degrees
 Servo servocont; //servo that is continuous
 int SwitchState = 0; //variable to keep track of if the button has been pushed


 int posmicro = 0; //starting microservo position
 int poscont = 0; //starting continuous servo position

void setup() {
  //pinMode(5, OUTPUT); // This is telling the Arduino to send information to whatever is connected to pin 5
  //pinMode(9, OUTPUT)
  //pinMode(10, OUTPUT)
  pinMode(2, INPUT); // This is telling the Arduino to look for input information from the circuit
  servomicro.attach(9);  //control microservo with pin 9
  servocont.attach(10); //control coninuous servo with pin 10

}

void loop() {
  SwitchState = digitalRead(2); // Tells the Arduino to pay attention to the input for pin 2

  if(SwitchState == LOW){ //this is a logic statement, It pays attention to if the switch is pushed or not
    //If the button is not pressed, the servos will be off
    servocont.write(90);
    servomicro.write(90);
                        }//This closes the if statement
  else{ //this is a logic statement if the button is pushed, then it turns the LED on
    //digitalWrite(9,10, HIGH);
    servocont.write(180); //rotate clockwise
 
     for (posmicro = 0; posmicro <=180; posmicro +=10) {//goes from 0 degrees to 180 desgree in 10 degree steps
         servomicro.write(posmicro); //tell servo to move
         delay (1000);}
  }
}
