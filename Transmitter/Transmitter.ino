#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char *SSID = ""; //<--- YOUR WIFI SSID
const char *password = "";  //<--- PASSWORD

IPAddress serverAddr = IPAddress(192,168,178,38); //<---- UDP DESTINATION IP
const int serverPort = 6969;

char message[] = "hodor";
const int messageLen = 5;

WiFiUDP Udp;

void setup() {
  //Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, password);
  while (WiFi.status() != WL_CONNECTED) {
    //Serial.print('.');
    delay(10);
  }
  //Serial.print("Connected! IP address: "); Serial.println(WiFi.localIP());
}

void loop() 
{
    Udp.beginPacket(serverAddr, serverPort);
    Udp.write(message, 5);
    Udp.endPacket();
}
