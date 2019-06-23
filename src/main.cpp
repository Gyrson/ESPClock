#include "WiFi.h"
#include <NTPClient.h>
#include <WiFiUdp.h>
#include "cred.h" //Create a File with the following entries: 
                  //const char* ssid = "YourSSID";
                  //const char* password =  "YourPassword";

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);
// Variables to save date and time
String formattedDate;
String dayStamp;
String timeStamp;

void setup(){
  Serial.begin(115200);
  delay(5000);

  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }

  timeClient.begin();
  timeClient.setTimeOffset(7200);
}

void loop() {
  timeClient.update();

  Serial.println(timeClient.getFormattedTime());

  delay(1000);
}