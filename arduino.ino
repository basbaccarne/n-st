/*
  NEST Demo using Protopie and Arduino Nano
  This script takes in the values of a rotary angle sensor and sends it to the serial port
  The rotary angle sensor is a grove Rotary Angle Sensor(P) connected to the A0 port of a Grove-Base Shield.
  The serial data is read by the protopie connect interface
  (make sure nothing else is reading the serial port, e.g. serial monitor)

  modified 26 Nov 2022
  by Bas Baccarne
*/

// define global variables
#define ROTARY_ANGLE_SENSOR A0  // set pin connection of pot meter to A0
#define ADC_REF 5               // set reference to 5v
#define GROVE_VCC 5             // the VCC of the grove interface is normally 5v
#define FULL_ANGLE 300          // the grove Rotary Angle Sensor(P) can turn 300 degrees

// set inputs and outputs
void setup() {
  Serial.begin(9600);

  pinMode(ROTARY_ANGLE_SENSOR, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

// shaping the loop
void loop() {
  // reading the Rotary Angle Sensor
  float voltage;                                       // variable to calculate the incoming voltage
  int sensor_value = analogRead(ROTARY_ANGLE_SENSOR);  // read the value of the potmeter
  voltage = (float)sensor_value * ADC_REF / 1023;      // calculate the voltage (0 to 5v)
  float degrees = (voltage * FULL_ANGLE) / GROVE_VCC;  // calculate the angle in degrees (°)
  
  //construct a string that can be interpreted by protopie connect (variable_name || value)
  Serial.print("angle||");
  Serial.println(degrees);

  // mapping temperature
  float temperature = map(degrees, 0, 300, 15, 27);
  Serial.print("temp||");
  Serial.println(temperature);

  // mapping circular coordinates for the tracker
  float coordinate = map(degrees, 0, 300, -120, 120);
  Serial.print("coordinate||");
  Serial.println(coordinate);

  // mapping red color values
  float red = map(degrees, 0, 300, 134, 255);
  Serial.print("red||");
  Serial.println(red);

    // mapping blue color values
  float blue = map(degrees, 0, 300, 255, 0);
  Serial.print("blue||");
  Serial.println(blue);

  delay(100);

  // [for testing purposes only]
  // adopting the flicker of the built in LED based on the angle of the sensor
  // digitalWrite(LED_BUILTIN, HIGH);                    // turn the built in LED on
  // delay(degrees*2);                                   // delay based in pot meter angle
  // digitalWrite(LED_BUILTIN, LOW);                     // turn the built in LED off
  // delay(degrees*2);                                   // delay based in pot meter angle
}