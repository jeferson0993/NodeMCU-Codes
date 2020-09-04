
#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>

#define FIREBASE_HOST ""  //Change to your Firebase RTDB project ID e.g. Your_Project_ID.firebaseio.com
#define FIREBASE_AUTH "" //Change to your Firebase RTDB secret password
#define WIFI_SSID ""
#define WIFI_PASSWORD ""

//Define Firebase Data objects
FirebaseData firebaseData1;
FirebaseData firebaseData2;

const int ledPin = 4; //GPIO4 or D2 for LED
const int swPin = 5;  //GPIO5 or D1 for Switch
bool swState = false;
String path = "/Nodes";
String nodeID = "Node2";      //This is this node ID to receive control
String otherNodeID = "Node1"; //This is other node ID to control

void setup()
{

    Serial.begin(115200);

    pinMode(ledPin, OUTPUT);
    pinMode(swPin, INPUT);

    Serial.println();
    Serial.println();

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(300);
    }
    Serial.println();
    Serial.print("Connected with IP: ");
    Serial.println(WiFi.localIP());
    Serial.println();

    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    Firebase.reconnectWiFi(true);

    if (!Firebase.beginStream(firebaseData1, path + "/" + nodeID))
    {
        Serial.println("Could not begin stream");
        Serial.println("REASON: " + firebaseData1.errorReason());
        Serial.println();
    }
}

void loop()
{
    if (!Firebase.readStream(firebaseData1))
    {
        Serial.println();
        Serial.println("Can't read stream data");
        Serial.println("REASON: " + firebaseData1.errorReason());
        Serial.println();
    }

    if (firebaseData1.streamTimeout())
    {
        Serial.println();
        Serial.println("Stream timeout, resume streaming...");
        Serial.println();
    }

    if (firebaseData1.streamAvailable())
    {
        if (firebaseData1.dataType() == "boolean")
        {
            if (firebaseData1.boolData())
                Serial.println("Set " + nodeID + " to High");
            else
                Serial.println("Set " + nodeID + " to Low");
            digitalWrite(ledPin, firebaseData1.boolData());
        }
    }

    if (digitalRead(swPin) != swState)
    {

        bool _swState = swState;
        swState = digitalRead(swPin);

        if (Firebase.setBool(firebaseData2, path + "/" + otherNodeID, swState))
        {
            if (swState)
                Serial.println("Set " + otherNodeID + " to High");
            else
                Serial.println("Set " + otherNodeID + " to Low");
        }
        else
        {
            swState = _swState;
            Serial.println("Could not set " + otherNodeID);
        }
    }
}
