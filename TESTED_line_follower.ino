int M1_PWM = 5;
int M2_PWM = 6;
int M1_CW = 8; int M1_CCW = 7; int M1_enabler = A0; int M1_CS = A2;
int M2_CW = 9; int M2_CCW = 4; int M2_enabler = A1; int M2_CS = A3;
int IRSL = 2; // InfraRed Sensor Left
int IRSM = A4; // ______________ Mid
int IRSR = A5; // ______________ Right
int m1c = 10 ;
int m1cc = 11;
int m2c = 12 ;
int enable =13 ;
int m2cc = 3;
int i = 0 ;
int boxescarried = 0 ;
bool o=true ;

void setup() {
  pinMode(M1_PWM, OUTPUT);  pinMode(M1_CW, OUTPUT);
  pinMode(M1_CCW, OUTPUT);  pinMode(M1_CS, OUTPUT);
  pinMode(M1_enabler, OUTPUT);
  pinMode(M2_PWM, OUTPUT);  pinMode(M2_CW, OUTPUT);
  pinMode(M2_CCW, OUTPUT);  pinMode(M2_CS, OUTPUT);
  pinMode(M2_enabler, OUTPUT);
pinMode(IRSL, INPUT);   pinMode(IRSM, INPUT);   pinMode(IRSR, INPUT);
  digitalWrite(M1_enabler, HIGH);
  digitalWrite(M2_enabler, HIGH);
  pinMode(m1c , OUTPUT);
  pinMode(m1cc , OUTPUT);
  pinMode(m2c , OUTPUT);
  pinMode(m2cc , OUTPUT);
  pinMode(enable,OUTPUT);
}

void loop() {
  

 
  if (!(digitalRead(IRSL))&&digitalRead(IRSM)&&!(digitalRead(IRSR)))
  {
    Forward(180); // Both motors forward @speed: 110
  
  }

  else if (!(digitalRead(IRSL))&&!(digitalRead(IRSM))&&digitalRead(IRSR)){
 
  L(180);
  
 
  } else if (!(digitalRead(IRSL))&&digitalRead(IRSM)&&digitalRead(IRSR)){
   
 L(180);
 
  }
  else if (digitalRead(IRSL)&&!(digitalRead(IRSM))&&!(digitalRead(IRSR))){
   
 R(180);
 
  }else if (digitalRead(IRSL)&&digitalRead(IRSM)&&!(digitalRead(IRSR))){
  
  R(180);

 
  }
  
  else if (digitalRead(IRSL)&&digitalRead(IRSM)&&digitalRead(IRSR))
  {
  Stop();
  pickdrop();
  if(i==1){
    i=0;
    }
    else if(i==0){
      i=1;
      }
  
  }
 

 
  

}

void Forward(int speed) {
  digitalWrite(M1_CW, LOW); digitalWrite(M1_CCW, HIGH);
  digitalWrite(M2_CW, LOW); digitalWrite(M2_CCW, HIGH);
  analogWrite(M1_PWM, speed); analogWrite(M2_PWM, speed);
}
void R (int speed){
   digitalWrite(M1_CW, HIGH); digitalWrite(M1_CCW, LOW);
  digitalWrite(M2_CW, LOW); digitalWrite(M2_CCW, HIGH);
  analogWrite(M1_PWM, speed); analogWrite(M2_PWM, speed);
}
void L (int speed){
digitalWrite(M1_CW, LOW); digitalWrite(M1_CCW, HIGH);
  digitalWrite(M2_CW, HIGH); digitalWrite(M2_CCW, LOW);
  analogWrite(M1_PWM, speed); analogWrite(M2_PWM, speed);
}

void Stop() {
  analogWrite(M1_PWM, 0); analogWrite(M2_PWM, 0);
  digitalWrite(M1_CW, LOW); digitalWrite(M1_CCW, LOW);
  digitalWrite(M2_CW, LOW); digitalWrite(M2_CCW, LOW);
}
void pickdrop(){
  if (i==0){
    
     delay (1000);
   analogWrite(enable,130);
  digitalWrite (m1c, LOW);
  digitalWrite(m1cc ,HIGH);
  // pick
 
  delay(160);
  digitalWrite (m1c, LOW);
  digitalWrite(m1cc ,LOW);
   delay (1000);
  analogWrite(enable,130);
  digitalWrite (m2c, HIGH);
  digitalWrite(m2cc ,LOW);
  // up
 
  delay(140);
  digitalWrite (m2c, LOW);
  digitalWrite(m2cc ,LOW);
  delay (1000);
  while (!((!digitalRead(IRSL))&&!(digitalRead(IRSM))&&!(digitalRead(IRSR)))){
    L(125);
    }
 
    }else if(i==1){
      delay(1000);
     
      analogWrite(enable,130);
  digitalWrite (m2c, LOW);
  digitalWrite(m2cc ,HIGH);
  // down
 
  delay(140);
  digitalWrite (m2c, LOW);
  digitalWrite(m2cc ,LOW);
  delay (1000);
  analogWrite(enable,130);
  digitalWrite (m1c, HIGH);
  digitalWrite(m1cc ,LOW);
  // drop
 
  delay(160);
  digitalWrite (m1c, LOW);
  digitalWrite(m1cc ,LOW);
   delay (1000);
  
  
  while (!(!(digitalRead(IRSL))&&digitalRead(IRSM)&&!(digitalRead(IRSR)))){
     L (125);
    
    }
  
      }
  
  }
