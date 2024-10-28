#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include "Updater_Signing.h"

#define OTETHERNET
#include <ArduinoOTA.h>
#include "Ethernet/Ethernet.h"
#include "mac_gen.h"

#ifndef STASSID
#define STASSID "YourSSID"
#define STAPSK "YourPassword"
#endif

const char *ssid = STASSID;
const char *password = STAPSK;

static byte mac[6];
static uint8_t uniqueID[8];

void setup()
{
  Serial.begin(9800);
  //while (!Serial)
  //  ; // Wait for Serial Monitor to be connected
  Serial.println("Booting");

  Ethernet.init(17); // W5100S-EVB-Pico
  delay(1000);       // Needed for the Ethernet to initialize

  get_unique_mac_adress(uniqueID, mac);

  Serial.print("Mac Adress: ");
  for (int i = 0; i < 6; i++)
  {
    Serial.print(mac[i]);
    Serial.print(", ");
  }
  Serial.println("");

  Serial.println("Initialize Ethernet with DHCP:");
  while (Ethernet.begin(mac) == 0)
  {
    Serial.println("Failed to configure Ethernet using DHCP");
    if (Ethernet.hardwareStatus() == EthernetNoHardware)
    {
      Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
    }
    else if (Ethernet.linkStatus() == LinkOFF)
    {
      Serial.println("Ethernet cable is not connected.");
    }
    delay(1000); // Retry every second
  }
  // print your local IP address:
  Serial.print("My IP address: ");
  Serial.println(Ethernet.localIP());

  // Port defaults to 8266
  // ArduinoOTA.setPort(8266);

  // Hostname defaults to esp8266-[ChipID]
  // ArduinoOTA.setHostname("myesp8266");

  // No authentication by default
  // ArduinoOTA.setPassword("admin");

  // Password can be set with it's md5 value as well
  // MD5(admin) = 21232f297a57a5a743894a0e4a801fc3
  // ArduinoOTA.setPasswordHash("21232f297a57a5a743894a0e4a801fc3");

  ArduinoOTA.begin(Ethernet.localIP(), "W5100S-EVB-Pico", "admin", InternalStorage);
  Serial.println("Ready");
}

void loop()
{
  ArduinoOTA.poll();
}
