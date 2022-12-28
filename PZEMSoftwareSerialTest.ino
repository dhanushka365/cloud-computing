#include <Arduino.h>
#include <PZEM004Tv30.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

ESP8266WiFiMulti WiFiMulti;

const char* ssid     ="Dialog 4G 694";
const char* password = "9ADe3De1";

//PZEM004Tv30 pzem(D1, D2); // (RX,TX)connect to TX,RX of PZEM
PZEM004Tv30 pzem2(D5, D6);  // (RX,TX) connect to TX,RX of PZEM
//PZEM004Tv30 pzem3(D7, D8);  // (RX,TX) connect to TX,RX of PZEM

void setup() {

  Serial.begin(115200);
  WiFi.mode(WIFI_OFF);        //Prevents reconnection issue (taking too long to connect)
  delay(1000);
  WiFi.mode(WIFI_STA);        //This line hides the viewing of ESP as wifi hotspot
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");
  Serial.print("Connecting");
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
    delay(250);
  }
  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.println("Connected to Network/SSID");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP

}

void loop() {
  // wait for WiFi connection
  //main energy meter
   float voltage = pzem.voltage();
  float current = pzem.current();
  float power = pzem.power();
  float energy = pzem.energy();
  float frequency = pzem.frequency();
  float pf = pzem.pf(); 
  Serial.print(voltage);
  Serial.print(current);
  Serial.print(power);
  Serial.print(energy);
  Serial.print(frequency);
  Serial.print(pf);
  delay(4000);
}
