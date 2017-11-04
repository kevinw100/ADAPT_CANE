//  Noah Stahl EDITED
//  5/25/2011
//  http://arduinomega.blogspot.com
//  Arduino Mega 2560
//This sketch is used to test the Sharp Long Range Infrared Sensor.
//The sensor output is attached to analog pin 15. Once the distance
//is calculated, it is printed out to the serial monitor.

//#define sensorIR A0           //Must be an analog pin
float sensorValue, inches, cm, prev;    //Must be of type float for pow()
int counter = 0;
int reads_per_frame = 1;
//Consider case where it's equal to 0
float readings[4];
int num_dropoffs = 0;
#define sensor_pin A0
bool first = true;

void setup() {
  Serial.begin(9600);
}
//int length(float arr[])
//{
//  return sizeof(arr) / sizeof(float);
//}
//void echo_readings(){
//  int i;
//  for(i = 0; i < length(readings); i++)
//  {
//    Serial.print(readings[i] + ",");
//  }
//}
//void clear_readings()
//{
//   int i;
//   for(i = 0; i < length(readings); i++)
//   {
//      readings[i] = 0;
//   }
//}
void loop() {
  sensorValue = analogRead(sensor_pin);
  inches = 4192.936 * pow(sensorValue,-0.935) - 3.937;
  delay(100);
  //cm = 10650.08 * pow(sensorValue,-0.935) - 10;
  Serial.print("Inches: ");
  Serial.println(inches);
}


//Original code
//void loop() {
//  int i;
//  sensorValue = analogRead(sensorIR);
//  inches = 4192.936 * pow(sensorValue,-0.935) - 3.937;
//  if(counter == 0){prev = inches;}
// 
//  if(inches - prev > 3)
//  {
//    Serial.print("inches: ");
//    Serial.print(inches);
//    Serial.print(" prev: ");
//    Serial.print(prev);
//    Serial.print("dropoff possible (num dropoffs occured):");
//    num_dropoffs++;
//    Serial.println(num_dropoffs);
////    digitalWrite(motor_pin, HIGH);
////    delay(100);
////    digitalWrite(motor_pin, LOW);
//  }
//      prev = inches;
//      readings[counter] = inches;
//      
//      counter++;
//      if(counter == reads_per_frame)
//      {
//        float avg = 0;
//        for(i = 0; i < reads_per_frame; i++)
//        {
//          avg += (float) readings[i];
//        }
//        avg = avg / ((float) reads_per_frame);
//        counter = 0;
//        Serial.print("Inches: ");
//        echo_readings();
//        clear_readings();
//      }
//    
//  //cm = 10650.08 * pow(sensorValue,-0.935) - 10;
//  delay((100));
//  Serial.print("Inches: ");
//  Serial.println(inches);
//}
