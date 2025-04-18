int Finger1_1 = 2;
int Finger1_2 = 3;
int Finger1_3 = 4;
int Finger1_4 = 5;
int Finger2_1 = 6;
int Finger2_2 = 7;
int Finger2_3 = 8;
int Finger2_4 = 9;
int Finger3_1 = 10;
int Finger3_2 = 11;
int Finger3_3 = 12;
int Finger3_4 = 44;
int TimeA = 2000;
int Active = 80;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(Finger1_1, OUTPUT);
pinMode(Finger1_2, OUTPUT);
pinMode(Finger1_3, OUTPUT);
pinMode(Finger1_4, OUTPUT);
pinMode(Finger2_1, OUTPUT);
pinMode(Finger2_2, OUTPUT);
pinMode(Finger2_3, OUTPUT);
pinMode(Finger2_4, OUTPUT);
pinMode(Finger3_1, OUTPUT);
pinMode(Finger3_2, OUTPUT);
pinMode(Finger3_3, OUTPUT);
pinMode(Finger3_4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available()>0){
int command = Serial.read();
Serial.println(command); 
if (command == 50){
  Serial.println("You sent 2");
  Serial.println("Finger Direction 1");
  analogWrite(Finger3_1, Active);
  Serial.println("Start");
  delay(TimeA);
  Serial.println("Stop");
  analogWrite(Finger3_1, 0);
}
else if (command == 51){
  Serial.println("You sent 3");
  Serial.println("Finger Direction 2");
  analogWrite(Finger3_2, Active);
  delay(TimeA);
  analogWrite(Finger3_2, 0);
}
else if (command == 52){
  Serial.println("You sent 4");
  Serial.println("Finger Direction 3");
  analogWrite(Finger3_3, Active);
  delay(TimeA);
  analogWrite(Finger3_3, 0);
}
else if (command == 53){
  Serial.println("You sent 5");
  Serial.println("Finger Direction 4");
  analogWrite(Finger3_4, Active);
  delay(TimeA);
  analogWrite(Finger3_4, 0);
}
// else if (command == 54){
//  Serial.println("You sent 6");
//  Serial.println("Move Long Brac Up");
//  analogWrite(LBracU, dutyBL);
// delay(TimeA);
//  analogWrite(LBracU, 0);
//}
//else if (command == 55){
//  Serial.println("You sent 7");
//  Serial.println("Move Long Brac Down");
//  analogWrite(LBracD, dutyBL);
//  delay(TimeA);
//  analogWrite(LBracD, 0);
//}
else{
  Serial.println("None");
  analogWrite(Finger3_1, 0);
  analogWrite(Finger3_2, 0);
  analogWrite(Finger3_3, 0);
  analogWrite(Finger3_4, 0);
}
}
}
