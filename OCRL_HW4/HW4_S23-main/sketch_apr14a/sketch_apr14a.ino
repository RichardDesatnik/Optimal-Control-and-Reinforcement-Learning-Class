int StemL = 3;
int StemR = 5;
int SBracU = 6;
int SBracD = 9;
int LBracU = 11;
int LBracD = 12;
int dutyS = 150;
int dutyBS = 150;
int dutyBL = 150;
int TimeA = 3000;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(StemL, OUTPUT);
pinMode(StemR, OUTPUT);
pinMode(SBracU, OUTPUT);
pinMode(SBracD, OUTPUT);
pinMode(LBracU, OUTPUT);
pinMode(LBracD, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available()>0){
int command = Serial.read();
Serial.println(command); 
if (command == 50){
  Serial.println("You sent 2");
  Serial.println("Move Stem Left");
  analogWrite(StemL, dutyS);
  Serial.println("Start");
  delay(4000);
  Serial.println("Stop");
  analogWrite(StemL, 0);
}
else if (command == 51){
  Serial.println("You sent 3");
  Serial.println("Move Stem Right");
  analogWrite(StemR, dutyS);
  delay(TimeA);
  analogWrite(StemR, 0);
}
else if (command == 52){
  Serial.println("You sent 4");
  Serial.println("Move Short Brac Up");
  analogWrite(SBracU, dutyS);
  delay(TimeA);
  analogWrite(SBracU, 0);
}
else if (command == 53){
  Serial.println("You sent 5");
  Serial.println("Move Short Brac Down");
  analogWrite(SBracD, dutyS);
  delay(TimeA);
  analogWrite(SBracD, 0);
}
else if (command == 54){
  Serial.println("You sent 6");
  Serial.println("Move Long Brac Up");
  analogWrite(LBracU, dutyBL);
  delay(TimeA);
  analogWrite(LBracU, 0);
}
else if (command == 55){
  Serial.println("You sent 7");
  Serial.println("Move Long Brac Down");
  analogWrite(LBracD, dutyBL);
  delay(TimeA);
  analogWrite(LBracD, 0);
}
else{
  Serial.println("None");
  analogWrite(StemR, 0);
  analogWrite(StemL, 0);
  analogWrite(SBracU, 0);
  analogWrite(SBracD, 0);
  analogWrite(LBracU, 0);
  analogWrite(LBracD, 0);
}
}
}
