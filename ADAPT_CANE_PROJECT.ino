//  Noah Stahl EDITED
//  5/25/2011
//  http://arduinomega.blogspot.com
//  Arduino Mega 2560
//This sketch is used to test the Sharp Long Range Infrared Sensor.
//The sensor output is attached to analog pin 15. Once the distance
//is calculated, it is printed out to the serial monitor.

#define sensorIR A0           //Must be an analog pin
float sensorValue, inches, cm, prev;    //Must be of type float for pow()
int counter = 0;
int reads_per_frame = 4;
//Consider case where it's equal to 0
float readings[4];
int num_dropoffs = 0;
int motor_pin = 7;

void setup() {
  pinMode(motor_pin, OUTPUT);
  Serial.begin(9600);
}
int length(float arr[])
{
  return sizeof(arr) / sizeof(float);
}
void echo_readings(){
  int i;
  Serial.print("[");
  for(i = 0; i < length(readings); i++)
  {
    Serial.print((int)readings[i] + ",");
  }
  Serial.print("]");
}
void clear_readings()
{
   int i;
   for(i = 0; i < length(readings); i++)
   {
      readings[i] = 0;
   }
}
//void loop() {
//  int i;
//  float avg = 0;
//  for(i = 0; i < reads_per_frame; i++)
//  {
//    sensorValue = analogRead(sensorIR);
//    inches = 4192.936 * pow(sensorValue,-0.935) - 3.937;
//    delay(50);
//    avg += inches;
//  }
//  avg = avg / (float) reads_per_frame;
//  clear_readings();
//  echo_readings();
//  //cm = 10650.08 * pow(sensorValue,-0.935) - 10;
////  delay((100));
//  Serial.print("Inches: ");
//  Serial.println(avg);
//}


//Original code
void loop() {
  int i;
  sensorValue = analogRead(sensorIR);
  inches = 4192.936 * pow(sensorValue,-0.935) - 3.937;
  if(counter == 0){prev = inches;}
 
  if(inches - prev > 3)
  {
    Serial.print("inches: ");
    Serial.print(inches);
    Serial.print(" prev: ");
    Serial.print(prev);
    Serial.print("dropoff possible (num dropoffs occured):");
    num_dropoffs++;
    Serial.println(num_dropoffs);
//    digitalWrite(motor_pin, HIGH);
//    delay(100);
//    digitalWrite(motor_pin, LOW);
  }
      prev = inches;
      readings[counter] = inches;
      counter++;
      if(counter == reads_per_frame)
      {
        float avg = 0;
        for(i = 0; i < reads_per_frame; i++)
        {
          avg += (float) readings[i];
        }
        avg = avg / ((float) reads_per_frame);
        counter = 0;
        Serial.print("Inches: ");
        echo_readings();
        clear_readings();
      }
    
  //cm = 10650.08 * pow(sensorValue,-0.935) - 10;
  delay((100));
  Serial.print("Inches: ");
  Serial.println(inches);
}
