#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>

#define FIREBASE_HOST "" // Firebase RTDB project ID
#define FIREBASE_AUTH ""  // Firebase RTDB secret password
#define WIFI_SSID ""
#define WIFI_PASSWORD ""

FirebaseData firebaseData;

const int ledPin = 0;

String path = "";

void setup() {

    Serial.begin(115200);

    pinMode(ledPin, OUTPUT);

    Serial.println();
    Serial.println();

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(300);
    }
    
    Serial.println();
    Serial.print("Connected with IP: ");
    Serial.println(WiFi.localIP());
    Serial.println();

    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    Firebase.reconnectWiFi(true);

    if (!Firebase.beginStream(firebaseData, path)) {
        Serial.println("Could not begin stream");
        Serial.println("REASON: " + firebaseData.errorReason());
        Serial.println();
    }
    
}

void loop() {
    if (!Firebase.readStream(firebaseData)) {
        Serial.println();
        Serial.println("Can't read stream data");
        Serial.println("REASON: " + firebaseData.errorReason());
        Serial.println();
    }

    if (firebaseData.streamTimeout()) {
        Serial.println();
        Serial.println("Stream timeout, resume streaming...");
        Serial.println();
    }

    if (firebaseData.streamAvailable()) {
        if (firebaseData.dataType() == "boolean")
        {
            if (firebaseData.boolData())
                Serial.println("Set " + nodeID + " to High");
            else
                Serial.println("Set " + nodeID + " to Low");
            digitalWrite(ledPin, firebaseData.boolData());
        }
    }

}
