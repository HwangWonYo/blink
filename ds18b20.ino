// ESP8266 DS18B20 ArduinoIDE Thingspeak IoT Example code
// http://vaasa.hacklab.fi
//
// https://github.com/milesburton/Arduino-Temperature-Control-Library
// https://gist.github.com/jeje/57091acf138a92c4176a


#include <OneWire.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DallasTemperature.h>
#include <ESP8266WiFiMulti.h>
#include "configure.h"

#define ONE_WIRE_BUS D4

ESP8266WiFiMulti wifiMulti;
const char* host = "api.thingspeak.com"; // Your domain  
String ApiKey = SECRET_API_KEY;
//const char* WIFI_HOST1 = HOST1;
//const char* WIFI_HOST2 = HOST2;
//const char* WIFI_SECRET_1 = SECRET_KEY_1;
//const char* WIFI_SECRET_2 = SECRET_KEY_2;
String Hosts[] = HOSTS;
String Secrets[] = SECRETS;


String path = "/update?key=" + ApiKey + "&field1=";  


OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature DS18B20(&oneWire);

char temperatureString[6];

void WIFI_Connect(){
//  wifiMulti.addAP("AndroidHotspot9899", "sss44477");
//  wifiMulti.addAP("SWAN", "swanlim3288");
//  wifiMulti.addAP(WIFI_HOST1, WIFI_SECRET_1);
//  wifiMulti.addAP(WIFI_HOST2, WIFI_SECRET_2);
  for(int i = 0; i < Hosts.size(); i++){
    wifiMulti.addAP(Hosts[i], Secrets[i]);
  }


  Serial.println("Connecting ...");
  int i = 0;
  while (wifiMulti.run() != WL_CONNECTED) { // Wait for the Wi-Fi to connect: scan for Wi-Fi networks, and connect to the strongest of the networks above
    delay(1000);
    Serial.print('.');
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(WiFi.SSID());
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}


void setup(void){
  Serial.begin(115200);
  Serial.println("");
  WIFI_Connect();
  DS18B20.begin();
}


float getTemperature() {
  float temp;
  do {
    DS18B20.requestTemperatures(); 
    temp = DS18B20.getTempCByIndex(0);
    delay(100);
  } while (temp == 85.0 || temp == (-127.0));
  return temp;
}

void sendDataToThinkSpeak(float temperature){
  dtostrf(temperature, 2, 2, temperatureString);
  // send temperature to the serial console
  Serial.println(temperatureString);

  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }

  client.print(String("GET ") + path + temperatureString + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: keep-alive\r\n\r\n");
}


void loop() {
  float temperature = getTemperature();
  if (WiFi.status() != WL_CONNECTED)
    {
      WIFI_Connect();
    } else {
      sendDataToThinkSpeak(temperature);
      delay(60000);
    }
}
