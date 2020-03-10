#include <string.h>

// pin settings
int in1 = 3;  //a
int in2 = 4;  //a
int in3 = 5;    //b
int in4 = 6;    //b

int enA = 10;
int enB = 11;

void setup() {
    Serial.begin(115200);

    // set pins to output
    pinMode(in1,OUTPUT);
 pinMode(in2,OUTPUT);
 pinMode(in3,OUTPUT);
 pinMode(in4,OUTPUT);
 
 pinMode(enA,OUTPUT);
 pinMode(enB,OUTPUT);
}


// function to control motor
// speed is how fast the motor rotates
// Please set pwmPin, InaPin and INbPin for the motor you want to drive
void control_motor(int speed, int pwmPin, int INaPin, int INbPin){
    if(speed > 0){
        analogWrite(pwmPin, speed);
        digitalWrite(INaPin, HIGH);
        digitalWrite(INbPin, LOW);
    }
    else if(speed < 0){
        analogWrite(pwmPin, -speed);
        digitalWrite(INaPin, LOW);
        digitalWrite(INbPin, HIGH);
    }
    else{
        digitalWrite(INaPin, LOW);
        digitalWrite(INbPin, LOW);
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
    control_motor(speed[0], enA, in1, in2);
    control_motor(speed[1], enB, in3, in4);
    

    
    delay(100);
}
