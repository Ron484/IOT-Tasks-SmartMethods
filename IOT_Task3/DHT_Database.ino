#include <WiFi.h>
#include <HTTPClient.h>
#include "DHT.h"


#define DHTPIN 12  //what pin we're connected to
#define DHTTYPE DHT11

//Note that you should change the values by your network credentials.
const char* ssid = "yourNetworkName";
const char* password =  "yourPassword";


DHT dht(DHTPIN, DHTTYPE);

void setup() {
  

  Serial.begin(115200);

  dht.begin();

  delay(4000);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  Serial.println("Connected to the WiFi network");

}

String HOST_NAME = "http://192.168.8.181"; // change to your PC's IP address
String file_NAME = "IOT_Task3/sendValue.php?"; //change with your file path


 




void loop() {


  float humidity = dht.readHumidity();

  float temperature = dht.readTemperature();



  String temp = String(temperature);
  String hum = String(humidity);

  if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status

    HTTPClient http;

    http.begin("http://" + HOST_NAME + file_NAME + "temperature=" +temp+"&humidity="+hum ); //Specify the URL


    int httpCode = http.GET(); //Make the request

    if (httpCode > 0) { //Check for the returning code

      String payload = http.getString();
      Serial.println(httpCode);
      Serial.println(payload);
    }

    else {
      Serial.println("Error on HTTP request");
    }

    http.end(); //Free the resources
  }

  delay(10000);

}