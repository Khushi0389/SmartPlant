#include <ESP8266WiFi.h>
#include <Wire.h>

 
 
String apiKey = "xxxx xxxx xxxx xxxx "; // Enter the Write API key from ThingSpeak
const char *ssid = "your_mobile_model_name";     // wifi ssid and wpa2 key
const char *pass = "your_wifi_password";
 
//const int sensor_pin = A0;  // Connect Soil moisture analog sensor pin to A0 of NodeMCU 
 
WiFiClient client;
 const char* host = "api.thingspeak.com";

 
void setup() {
  Serial.begin(115200);

  delay(10);
  Wire.begin();
  Serial.println("Connecting to ");
  Serial.println(ssid);
  

  WiFi.begin(ssid, pass);
 
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
    Serial.println("");
    Serial.println("WiFi connected");
    // printWifiStatus();

    delay(4000);
}
 int value=0;
 int lastKnown=0;
void loop() 
{
    delay(5000);
    value = analogRead(A0);
    if(value==1024){
      value=lastKnown;
    }else{
      lastKnown=value;
    }
    Serial.print("connecting to ");
    Serial.println(host);
 
    // Use WiFiClient class to create TCP connections
    WiFiClient client;
    const int httpPort = 80;
    if (!client.connect(host, httpPort)) {
        Serial.println("connection failed");
        return;
    }
 
    // We now create a URI for the request
    String url = "/update";
    url += "?api_key=";
    url += apiKey;
    url += "&field1=";
    url += value;
 
    Serial.print("Requesting URL: ");
    Serial.println(url);
 
    // This will send the request to the server
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n\r\n");
    unsigned long timeout = millis();
    while (client.available() == 0) {
        if (millis() - timeout > 5000) {
            Serial.println(">>> Client Timeout !");
            client.stop();
            return;
        }
    }
 
    // Read all the lines of the reply from server and print them to Serial
    while(client.available()) {
        String line = client.readStringUntil('\r');
        Serial.print(line);
    }
 
    Serial.println();
    Serial.println("closing connection");

  
    Serial.println("Waiting...");
 
    delay(2000);  
        // thingspeak needs minimum 15 sec delay between updates.
}

void printWifiStatus() {

  // print the SSID of the network you're attached to:

  Serial.print("SSID: ");

  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:

  IPAddress ip = WiFi.localIP();

  Serial.print("IP Address: ");

  Serial.println(ip);

  // print the received signal strength:

  long rssi = WiFi.RSSI();

  Serial.print("signal strength (RSSI):");

  Serial.print(rssi);

  Serial.println(" dBm");
}
