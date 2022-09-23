#include <string.h>

// pin settings

int pwnPin = 6;    //b
int dirPin = 8;    //b



void setup() {
    Serial.begin(115200);
    
    // set pins to output
    pinMode(dirPin,OUTPUT); //sdfdsbfdsiubfdsufbui
 pinMode(pwnPin,OUTPUT);
  Serial.begin(115200);
     Serial.begin(115200);
     Serial.begin(115200);
    
    // set pins to output
    pinMode(dirPin,OUTPUT); //sdfdsbfdsiubfdsufbui
 pinMode(pwnPin,OUTPUT);
    // set pins to output
    pinMode(dirPin,OUTPUT); //sdfdsbfdsiubfdsufbui
 pinMode(pwnPin,OUTPUT);
    // set pins to output
    pinMode(dirPin,OUTPUT); //sdfdsbfdsiubfdsufbui
 pinMode(pwnPin,OUTPUT);

}


// function to control motor
// speed is how fast the motor rotates
// Please set pwmPin, InaPin and INbPin for the motor you want to drive
void control_motor(int speed, int pwmPin,int dirPin){
    if(speed > 0){
        analogWrite(pwmPin, speed);
        digitalWrite(dirPin, HIGH);
    }
    else if(speed < 0){
        analogWrite(pwmPin, -speed);
        digitalWrite(dirPin, LOW);
    }
    else{
        digitalWrite(pwmPin, 0);
    }
}

// In time loop, receive from serial and control 6 motors
void loop() {
    static int speed[6];
    static char buff[30];
    int counter = 0;

    // read command from raspberry pi
    while(Serial.available()){
        buff[counter] = Serial.read();
        if (counter > 30 || buff[counter] == '*') {
            buff[counter] = '\0';
            speed[0]=atoi(strtok(buff,","));
            speed[1]=atoi(strtok(NULL,","));
            
        }
        else{
            counter++;
        }
    }

    // control motors
    control_motor(speed[0], pwnPin, dirPin);
    

    
    delay(100);
}
