Code for Transmitter module
int LDRSensor = A0;
// Declare your Green and Red LED pin connected Arduino pin “D5 and D4”
#include "DHT.h"
DHT dht(3, DHT22);
#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
#define REPORTING_PERIOD_MS 1000
PulseOximeter pox;
uint32_t tsLastReport = 0;
#include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 3; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
{'1', '2', '3'},
{'4', '5', '6'},
{'7', '8', '9'},
{'*', '0', '#'}

20

};
byte rowPins[ROWS] = {40, 42, 44, 46}; //connect to the row pinouts of the
keypad
byte colPins[COLS] = {48, 50, 52}; //connect to the column pinouts of the
keypad
//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins,
colPins, ROWS, COLS);
void setup()
{
dht.begin();
pox.begin();
Serial.begin(9600);
pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
}
void loop()
{
delay(100);
float T = dht.readTemperature();
/*pox.update();
int hb = pox.getHeartRate();
int spo2 = pox.getSpo2();*/

21
char customKey = customKeypad.getKey();
if (customKey) {
Serial.println(customKey);
}
if ((analogRead(A0) < 260) || (analogRead(A0) > 340) || (analogRead(A1) <
260) || (analogRead(A1) > 340))
{
Serial.println('a');
}
if (T > 37)
{
Serial.println('b');
}
/* if(hb<40)
{
Serial.println('c');
}
if(spo2<93)
{
Serial.println('d');
}*/
}


