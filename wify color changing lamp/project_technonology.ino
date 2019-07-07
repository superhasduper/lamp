
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include <Servo.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "13740f4db08845a9a59978498a290b5a";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "wifi";
char pass[] = "passwords";

Servo servo;

BLYNK_WRITE(V3)
{
  servo.write(param.asInt());
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);

  servo.attach(13);
}

void loop()
{
  Blynk.run();
}
