/* I Shawn Barrow, 000332631 certify that this material is my original work and none
other person's work has been used without due acknowledgement. 2022-09-19 **/
#include <Arduino.h>
void setup() {
 // configure the USB serial monitor
 Serial.begin(115200);
 
}
float scaleIt(float x, float min1, float max1, float min2, float max2)
{
 return (x - min1) * (max2 - min2) / (max1 - min1) + min2;
}

void loop() {
 int iVal;
 float mapVal;
 // read digitized value from the D1 Mini's A/D convertor
 iVal = analogRead(A0);
 mapVal = scaleIt(iVal,0,1023,0,50);
 int intVal = int(mapVal);
 String weather;
 switch (intVal) {
  case 0 ... 9:
    weather = "Cold!";
    break;
  case 10 ... 15:
    weather = "Cool.";
    break;
  case 16 ... 25:
    weather = "Perfect.";
    break;
  case 26 ... 30:
    weather = "Warm.";
    break;
  case 31 ... 35:
    weather = "Hot.";
    break;
  case 36 ... 51:
    weather = "Too Hot!";
    break;
  
 }
 // print value to the USB port
 Serial.println("Digitized Value of " + String(iVal) + " is equivalent to a temperature input of "+ String(mapVal) + " degrees C, Which is "+ weather);
 // wait 0.5 seconds (500 ms)
 delay(2000);
}