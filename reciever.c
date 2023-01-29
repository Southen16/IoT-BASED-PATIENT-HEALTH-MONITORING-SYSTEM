// code for Receiver Module
#include <SoftwareSerial.h>
SoftwareSerial serial(16, 17);
#include <LiquidCrystal.h>
LiquidCrystal lcd(14, 27, 26, 25, 33, 32);
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "kXa5P42EHKMZ8STLFuMMQinflcZ5nqAt";
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "MUFA Wireless Fidelity";
char pass[] = "mufatechsolutions";
WidgetLCD blcd(V1);
void setup()
{
pinMode(13, OUTPUT);
digitalWrite(13, LOW);
lcd.begin(16, 2);
Serial.begin(9600);
serial.begin(9600);
Blynk.begin(auth, ssid, pass);
blcd.clear();
blcd.print(0, 0, "WELCOME ");
blcd.print(0, 1, " ");
lcd.setCursor(0, 0);
lcd.print("WELCOME ");
lcd.setCursor(0, 1);
lcd.print(" ");
delay(3000);
lcd.clear();
}
void loop()
{
Blynk.run();
Blynk.virtualWrite(V2, random(60, 80));
Blynk.virtualWrite(V3, random(93, 99));
Blynk.virtualWrite(V4, random(27, 36));
if (serial.available() > 0)
{
char key = serial.read();
if (key == '1')
{
lcd.clear();
digitalWrite(13, HIGH);
delay(200);
digitalWrite(13, LOW);
lcd.setCursor(0, 0);
lcd.print("TAKE ME TO THE ");
lcd.setCursor(0, 1);
lcd.print("HOSPITAL ");
blcd.print(0, 0, "TAKE ME TO THE ");
blcd.print(0, 1, "HOSPITAL ");
}
else if (key == '2')
{
lcd.clear();
digitalWrite(13, HIGH);
delay(200);
digitalWrite(13, LOW);
lcd.setCursor(0, 0);
lcd.print("COME HERE ");
lcd.setCursor(0, 1);
lcd.print("I NEED HELP ");
blcd.print(0, 0, "COME HERE ");
blcd.print(0, 1, "I NEED HELP ");
}
else if (key == '3')
{
lcd.clear();
digitalWrite(13, HIGH);
delay(200);
digitalWrite(13, LOW);
lcd.setCursor(0, 0);
lcd.print("THANK YOU ");
lcd.setCursor(0, 1);
lcd.print(" ");
blcd.print(0, 0, "THANK YOU ");
blcd.print(0, 1, " ");
}
else if (key == '4')
{
lcd.clear();
digitalWrite(13, HIGH);
delay(200);
digitalWrite(13, LOW);
lcd.setCursor(0, 0);
lcd.print("GOOD NIGHT ");
lcd.setCursor(0, 1);
lcd.print(" ");
blcd.print(0, 0, "GOOD NIGHT ");
blcd.print(0, 1, " ");
}
else if (key == '5')
{
lcd.clear();
digitalWrite(13, HIGH);
delay(200);
digitalWrite(13, LOW);
lcd.setCursor(0, 0);
lcd.print("LETS GO OUT ");
lcd.setCursor(0, 1);
lcd.print(" ");
blcd.print(0, 0, "LETS GO OUT ");
blcd.print(0, 1, " ");
}
else if (key == '6')
{
lcd.clear();
digitalWrite(13, HIGH);
delay(200);
digitalWrite(13, LOW);
lcd.setCursor(0, 0);
lcd.print("I NEED TO GO TO ");
lcd.setCursor(0, 1);
lcd.print("TOILET ");
blcd.print(0, 0, "I NEED TO GO TO ");
blcd.print(0, 1, "TOILET ");
}
else if (key == '7')
{
lcd.clear();
digitalWrite(13, HIGH);
delay(200);
digitalWrite(13, LOW);
lcd.setCursor(0, 0);
lcd.print("GOOD MORNING ");
lcd.setCursor(0, 1);
lcd.print(" ");
blcd.print(0, 0, "GOOD MORNING ");
blcd.print(0, 1, " ");
}
else if (key == '8')
{
lcd.clear();
digitalWrite(13, HIGH);
delay(200);
digitalWrite(13, LOW);
lcd.setCursor(0, 0);
lcd.print("I AM HUNGRY ");
lcd.setCursor(0, 1);
lcd.print(" ");
blcd.print(0, 0, "I AM HUNGRY ");
blcd.print(0, 1, " ");
}
else if (key == '9')
{
lcd.clear();
digitalWrite(13, HIGH);
delay(200);
digitalWrite(13, LOW);
lcd.setCursor(0, 0);
lcd.print("I NEED WATER ");
lcd.setCursor(0, 1);
lcd.print(" ");
blcd.print(0, 0, "I NEED WATER ");
blcd.print(0, 1, " ");
}
else if (key == '0')
{
lcd.clear();
digitalWrite(13, HIGH);
delay(200);
digitalWrite(13, LOW);
lcd.setCursor(0, 0);
lcd.print("I NEED A CUP OF ");
lcd.setCursor(0, 1);
lcd.print("TEA ");
blcd.print(0, 0, "I NEED A CUP OF ");
blcd.print(0, 1, "TEA ");
}
else if (key == '*')
{
lcd.clear();
digitalWrite(13, HIGH);
delay(200);
digitalWrite(13, LOW);
lcd.setCursor(0, 0);
lcd.print("I WANT TO SLEEP ");
lcd.setCursor(0, 1);
lcd.print(" ");
blcd.print(0, 0, "I WANT TO SLEEP");
blcd.print(0, 1, " ");
}
else if (key == '#')
{
lcd.clear();
digitalWrite(13, HIGH);
delay(200);
digitalWrite(13, LOW);
lcd.setCursor(0, 0);
lcd.print("THIS PROJECT IS");
lcd.setCursor(0, 1);
lcd.print("VERY HELPFUL ");
blcd.print(0, 0, "THIS PROJECT IS");
blcd.print(0, 1, "VERY HELPFUL ");
}

else if (key == 'a')
{
lcd.clear();
digitalWrite(13, HIGH);
delay(200);
digitalWrite(13, LOW);
lcd.setCursor(0, 0);
lcd.print("PATIENT FALL ");
lcd.setCursor(0, 1);
lcd.print("DETECTED ");
Blynk.notify("Patient fall detected.");
fall();
}
else if (key == 'b')
{
lcd.clear();
digitalWrite(13, HIGH);
delay(200);
digitalWrite(13, LOW);
lcd.setCursor(0, 0);
lcd.print("HIGH FEVER ");
lcd.setCursor(0, 1);
lcd.print("DETECTED ");
Blynk.notify("High fever detected.");
Blynk.virtualWrite(V4, random(38, 40));
fever();
}
else if (key == 'c')
{
lcd.clear();
digitalWrite(13, HIGH);
delay(200);
digitalWrite(13, LOW);
lcd.setCursor(0, 0);
lcd.print("ABNORMAL H.B ");
lcd.setCursor(0, 1);
lcd.print("DETECTED ");
Blynk.notify("Abnormal heartbeat detected.");
Blynk.virtualWrite(V2, random(22, 38));
hb();
}
else if (key == 'd')
{
lcd.clear();
digitalWrite(13, HIGH);
delay(200);
digitalWrite(13, LOW);
lcd.setCursor(0, 0);
lcd.print("LOW SPo2 ");
lcd.setCursor(0, 1);
lcd.print("DETECTED ");
Blynk.notify("low spo2 detected.");
Blynk.virtualWrite(V3, random(60, 80));
spo2();
}
}
}
void fall()
{
Serial.println("AT");
delay(500);
Serial.println("AT+CMGF=1");
delay(500);
Serial.print("AT+CMGS=");
Serial.print('"');
Serial.print("9490442018"); //mobile no. for SMS alert
Serial.println('"');
delay(500);
Serial.print("patient fall detected.");
Serial.write(26);
delay(3000);
}
void fever()
{
Serial.println("AT");
delay(500);
Serial.println("AT+CMGF=1");
delay(500);
Serial.print("AT+CMGS=");
Serial.print('"');
Serial.print("9490442018"); //mobile no. for SMS alert
Serial.println('"');
delay(500);
Serial.print("patient high temperature.");
Serial.write(26);
delay(3000);
}
void hb()
{
Serial.println("AT");
delay(500);
Serial.println("AT+CMGF=1");
delay(500);
Serial.print("AT+CMGS=");
Serial.print('"');
Serial.print("9490442018"); //mobile no. for SMS alert
Serial.println('"');
delay(500);
Serial.print("Abnormal heart beat detected.");
Serial.write(26);
delay(3000);
}
void spo2()
{
Serial.println("AT");
delay(500);
Serial.println("AT+CMGF=1");
delay(500);
Serial.print("AT+CMGS=");
Serial.print('"');
serial.print("9490442018"); //mobile no. for SMS alert
Serial.println('"');
delay(500);
Serial.print("low spo2 detected");
Serial.write(26);
delay(3000);
}