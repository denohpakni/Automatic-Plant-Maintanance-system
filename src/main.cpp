/*

*/
#include <Arduino.h>
#include <dht_nonblocking.h>
// #include <Blynk.h>

const int dry = 479;
const int wet = 189;

#define my_DHT_SENSOR_TYPE DHT_TYPE_11  //define the sensor type from the library
static const int DHT_SENSOR_PIN = 6;  // where the input pin is connected to.
DHT_nonblocking the_thing_dht_sensor( DHT_SENSOR_PIN, my_DHT_SENSOR_TYPE );
int IN1 = 3;        // define 1 control port to control one of the 4 channel relays
int Pin1 = A0;      // Analog ports to read the moisture readings

float moistSensorVal = 0;   // variable to store the value detected by the moisture sensor 

int trigPin = 12; // Arduino pin tied to trigger pin on the ultrasonic sensor.
int echoPin = 11;  // Arduino pin tied to echo pin on the ultrasonic sensor.

float duration;
float distance;

void setup() {
  Serial.begin(9600);
  Serial.println("MOISTURE,Temp, & Humidity LEVEL SENSOR 1: ");
  pinMode(IN1, OUTPUT);
  pinMode(Pin1, INPUT);
  digitalWrite(IN1, HIGH);  

  // Water level sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
float temperature;
float humidity;
int moistSensorVal = analogRead(Pin1);
int percentageHumidity = map(moistSensorVal,wet,dry,100,0); 

if(the_thing_dht_sensor.measure(&temperature, &humidity)){
  Serial.print( "T = " );
  Serial.print( temperature, 1 );
  Serial.print( " deg. C, H = " );
  Serial.print( humidity, 1 );
  Serial.print( "%, " );   
  Serial.print("SoilMoisture is ");
  Serial.print(percentageHumidity);
  Serial.println(" %"); 
  delay(1000);

  if(percentageHumidity<35){
      digitalWrite(IN1, LOW);
  }else{
    digitalWrite(IN1, HIGH);
    } 

  // ########## Water level sensor - ultraSonic ############## 

  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);  // wait 2ms to make sure trigPin is LOW

  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10); // emit the ultrasonic sound for 10 secs
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin,HIGH); // requests how long echoPin has been HIGH
  distance = (duration * 0.0343)/2; // calc distance based on the speed of sound, then divide by 2 since the sound travelled the distance twice
  Serial.print("Distance: ");
  Serial.println(distance);

  delay(100);

  }
  
}
