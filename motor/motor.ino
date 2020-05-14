#define LM1 13//left motor positive
#define LM2 12//left motor negative
#define RM1 11//right motor positive
#define RM2 10//right motor negative




void setup() {
  // put your setup code here, to run once:
  pinMode(LM1, OUTPUT);
  pinMode(RM1, OUTPUT);
    pinMode(LM2, OUTPUT);
  pinMode(RM2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(LM1, HIGH); 
    digitalWrite(LM2, LOW); 
    digitalWrite(RM1, HIGH); 
    digitalWrite(RM2, LOW); 
}
