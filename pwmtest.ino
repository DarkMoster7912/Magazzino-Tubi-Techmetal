#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver pwm2 = Adafruit_PWMServoDriver(0x41);

char r = 0; int c = 0;
byte a[2];
//bool COMM;
int i=0;

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(1600);  // This is the maximum PWM frequency
  pwm.setOscillatorFrequency(27000000);
  pwm2.begin();
  pwm2.setPWMFreq(1600);  // This is the maximum PWM frequency
  //while(Serial.available()); //Init SPI with HMD
  //c = Serial.read();
  //Serial.write(c);
}

void loop(){
      /*while (Serial.available());
      c = Serial.read();
      if (c == 'o'){
            COMM = true; //COMM open
      }
      while(COMM){*/
      if(Serial.available()){
            Serial.readBytes(a, 2);
            /*do{
                  Serial.println(char(a[0]));Serial.println(a[1]);
                  delay(10000);
            }
            while(i<10);//{Serial.println(char(a[0]));Serial.println(a[1]);}*/
            r = a[0];
            c = a[1];
      //}
      
      switch (r){
            case '0': //Turn off all lights
                  for (int i=0; i<16; i++){
                        pwm.setPWM(i, 0, 0);
                  }
                  for (int i = 0; i<16; i++){
                        pwm2.setPWM(i, 0, 0);
                  }
                  break;
            case 'c': //Turn off all lights and COMM closed
                  for (int i=0; i<16; i++){
                        pwm.setPWM(i, 0, 0);
                  }
                  for (int i = 0; i<16; i++){
                        pwm2.setPWM(i, 0, 0);
                  }
                  //COMM = false;
                  break;
            case 'A': //Turn on row1
                  pwm.setPWM(int(r)-65, 0, 4095);
                  break;
            case 'B': //Turn on row2
                  pwm.setPWM(int(r)-65, 0, 4095);
                  break;
            case 'C': //Turn on row3
                  pwm.setPWM(int(r)-65, 0, 4095);
                  break;
            case 'D': //Turn on row4
                  pwm.setPWM(int(r)-65, 0, 4095);
                  break;
            case 'E': //Turn on row5
                  pwm.setPWM(int(r)-65, 0, 4095);
                  break;
            case 'F': //Turn on row6
                  pwm.setPWM(int(r)-65, 0, 4095);
                  break;
            case 'G': //Turn on row7
                  pwm.setPWM(int(r)-65, 0, 4095);
                  break;
            case 'H': //Turn on row8
                  pwm.setPWM(int(r)-65, 0, 4095);
                  break;
            
            }
            switch(c){
                  case 1:  //Turn on column1
                        pwm.setPWM(c+7, 0, 4095);
                        break;
                  case 2:  //Turn on column2
                        pwm.setPWM(c+7, 0, 4095);
                        break;
                  case 3:  //Turn on column3
                        pwm.setPWM(c+7, 0, 4095);
                        break;
                  case 4:  //Turn on column4
                        pwm.setPWM(c+7, 0, 4095);
                        break;
                  case 5:  //Turn on column5
                        pwm.setPWM(c+7, 0, 4095);
                        break;
                  case 6:  //Turn on column6
                        pwm.setPWM(c+7, 0, 4095);
                        break;
                  case 7:  //Turn on column7
                        pwm.setPWM(c+7, 0, 4095);
                        break;
                  case 8:  //Turn on column8
                        pwm.setPWM(c+7, 0, 4095);
                        break;
                  case 9:  //Turn on column9
                        pwm2.setPWM(c-9, 0, 4095);
                        break;
                  case 10:  //Turn on column10
                        pwm2.setPWM(c-9, 0, 4095);
                        break;
                  case 11:  //Turn on column11
                        pwm2.setPWM(c-9, 0, 4095);
                        break;
                  case 12:  //Turn on column12
                        pwm2.setPWM(c-9, 0, 4095);
                        break;
                  case 13:  //Turn on column13
                        pwm2.setPWM(c-9, 0, 4095);
                        break;
                  case 14:  //Turn on column14
                        pwm2.setPWM(c-9, 0, 4095);
                        break;
                  case 15:  //Turn on column15
                        pwm2.setPWM(c-9, 0, 4095);
                        break;
                  case 16:  //Turn on column16
                        pwm2.setPWM(c-9, 0, 4095);
                        break;
                  case 17:  //Turn on column17
                        pwm2.setPWM(c-9, 0, 4095);
                        break;
            }
            c = 0;
            r = '0';
      }
}