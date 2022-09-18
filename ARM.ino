int m1c = 10 ;
int m1cc = 11;
int m2c = 12 ;
int enable =13 ;
int m2cc = 3;
void setup() {
  pinMode(m1c , OUTPUT);
  pinMode(m1cc , OUTPUT);
  pinMode(m2c , OUTPUT);
  pinMode(m2cc , OUTPUT);
  pinMode(enable,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  //delay (500);
  //analogWrite(enable,130);
  //digitalWrite (m1c, HIGH);
  //digitalWrite(m1cc ,LOW);
  // up
 
  //delay(165);
  //digitalWrite (m1c, LOW);
  //digitalWrite(m1cc ,LOW);
//delay(5000);  
delay(1000);  
   analogWrite(enable,130);
  digitalWrite (m1c, LOW);
  digitalWrite(m1cc ,HIGH);
  // down
 
  delay(160);
  digitalWrite (m1c, LOW);
  digitalWrite(m1cc ,LOW);
   delay (1000);
  analogWrite(enable,130);
  digitalWrite (m2c, HIGH);
  digitalWrite(m2cc ,LOW);
  // drop
 
  delay(140);
  digitalWrite (m2c, LOW);
  digitalWrite(m2cc ,LOW);
  delay (5000);
  

  // put your main code here, to run repeatedly:

}
