/*
  Reading the one and two axis flex sensors from Bend Labs
  By: Nathan Seidle @ SparkFun Electronics
  Date: March 2nd, 2019
  License: This code is public domain but you buy me a beer if you use this 
  and we meet someday (Beerware license).

  This example reads the flex values of the single or 
  dual axis angular bend sensor (ADS)

  SparkFun labored with love to create this code. Feel like supporting open
  source? Buy a sensor from SparkFun!
  https://www.sparkfun.com/products/15245 (2-axis sensor)
  https://www.sparkfun.com/products/15244 (1-axis sensor)

  Hardware Connections:
  Use the SparkFun Qwiic Breadboard Jumper (https://www.sparkfun.com/products/14425)
  to connect to the RedBoard Qwiic and the following pins on the ADS:
  SCL: Yellow wire on Qwiic cable
  SDA: Blue
  VCC: Red
  GND: Black

  Single axis pinout: https://cdn.sparkfun.com/assets/9/f/8/2/d/Bendlabs_Single_Axis_Flex_Sensor_Pinout.png
  Dual axis pintout: https://cdn.sparkfun.com/assets/f/f/9/e/6/Bendlabs_Dual_Axis_Flex_Sensor_Pinout.png
  
  Open the serial monitor at 115200 baud to see the output
*/

#include <Wire.h>
#include "SparkFun_Displacement_Sensor_Arduino_Library.h" // Click here to get the library: http://librarymanager/All#SparkFun_Displacement_Sensor

ADS myFlexSensor; //Create instance of the Angular Displacement Sensor (ADS) class
int OpenClaw = 2;
int CloseClaw = 3;
int ClawOff = 4;
int ActTime = 1000;
int ETime = 1000;
float command = -100;

void setup()
{
pinMode(OpenClaw,OUTPUT);
pinMode(CloseClaw,OUTPUT);
pinMode(ClawOff,OUTPUT);


  Serial.begin(115200);
  while (!Serial)
    ;
  Serial.println("SparkFun Displacement Sensor Example");

  Wire.begin();

  if (myFlexSensor.begin() == false)
  {
    Serial.println(F("No sensor detected. Check wiring. Freezing..."));
    while (1)
      ;
  }
}

void loop()
{
  if (myFlexSensor.available() == true)
  {
    Serial.print(myFlexSensor.getX());
    Serial.println();
    command = myFlexSensor.getX();
  }
  delay(10);
  
if (command >= 100 and command <= 200)
{
  Serial.println("Soft Claw Close");
  Serial.println(command);
  //digitalWrite(CloseClaw,HIGH);
  //digitalWrite(OpenClaw,LOW);
  //digitalWrite(ClawOff,LOW);
  delay(ActTime);
  Serial.println("Complete");
  //digitalWrite(CloseClaw,LOW);
  //digitalWrite(OpenClaw,LOW);
  //digitalWrite(ClawOff,LOW);
  }
else if(command < 50 and command >= -50){
  Serial.println("Soft Claw Open");
  Serial.println(command);
  //digitalWrite(CloseClaw,LOW);
  //digitalWrite(OpenClaw,HIGH);
  //digitalWrite(ClawOff,LOW);
  delay(ActTime);
  Serial.println("Complete");
  //digitalWrite(CloseClaw,LOW);
  //digitalWrite(OpenClaw,HIGH);
  //digitalWrite(ClawOff,LOW);
}
else if(command >= 50 and command < 100){
  Serial.println("Soft Claw Natural Off");
  Serial.println(command);
  //digitalWrite(CloseClaw,LOW);
  //digitalWrite(OpenClaw,LOW);
  //digitalWrite(ClawOff,HIGH);
  delay(ActTime);
  Serial.println("Complete");
  //digitalWrite(CloseClaw,LOW);
  //digitalWrite(OpenClaw,LOW);
  //digitalWrite(ClawOff,LOW);
}
else if(command > 200){
  Serial.println("Safety");
  Serial.println(command);
  //digitalWrite(CloseClaw,LOW);
  //digitalWrite(OpenClaw,LOW);
  //digitalWrite(ClawOff,LOW);
  delay(ETime);
  Serial.println("Complete");
  //digitalWrite(CloseClaw,LOW);
  //digitalWrite(OpenClaw,LOW);
  //digitalWrite(ClawOff,LOW);
}
else{
  Serial.println("Soft Claw Default");
  Serial.println(command);
  //digitalWrite(CloseClaw,LOW);
  //digitalWrite(OpenClaw,LOW);
  //digitalWrite(ClawOff,LOW);
  delay(ETime);
}
}
