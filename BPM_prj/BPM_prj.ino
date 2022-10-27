/*
******************************************************************************
* @file: Index Code.html
* @author: tungvtt1609
* @version: V1.0.0
* @date: 25-02-2022
* @brief: This file is the main file of the project
******************************************************************************
*/

//===================================================================================Heart Rate Sensor Station Mode

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include "SSD1306.h"
//----------------------------------------

#include "Index.h" //--> Our HTML webpage contents with javascripts

#define ON_Board_LED 2 //--> Defining an On Board LED (GPIO2 = D4), used for indicators when the process of connecting to a wifi router and when there is a client request.
//----------------------------------------SSID and Password of your WiFi router
const char *ssid = "chilinh";          //--> Your wifi name
const char *password = "77777777"; //--> Your wifi password
//----------------------------------------

SSD1306 display(0x3C,4,5);

// bitmap icon]
static const unsigned char PROGMEM logo2_bmp[] =
{ 0x03, 0xC0, 0xF0, 0x06, 0x71, 0x8C, 0x0C, 0x1B, 0x06, 0x18, 0x0E, 0x02, 0x10, 0x0C, 0x03, 0x10,              //Logo2 and Logo3 are two bmp pictures that display on the OLED if called
0x04, 0x01, 0x10, 0x04, 0x01, 0x10, 0x40, 0x01, 0x10, 0x40, 0x01, 0x10, 0xC0, 0x03, 0x08, 0x88,
0x02, 0x08, 0xB8, 0x04, 0xFF, 0x37, 0x08, 0x01, 0x30, 0x18, 0x01, 0x90, 0x30, 0x00, 0xC0, 0x60,
0x00, 0x60, 0xC0, 0x00, 0x31, 0x80, 0x00, 0x1B, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x04, 0x00,  };

static const unsigned char PROGMEM logo3_bmp[] =
{ 0x01, 0xF0, 0x0F, 0x80, 0x06, 0x1C, 0x38, 0x60, 0x18, 0x06, 0x60, 0x18, 0x10, 0x01, 0x80, 0x08,
0x20, 0x01, 0x80, 0x04, 0x40, 0x00, 0x00, 0x02, 0x40, 0x00, 0x00, 0x02, 0xC0, 0x00, 0x08, 0x03,
0x80, 0x00, 0x08, 0x01, 0x80, 0x00, 0x18, 0x01, 0x80, 0x00, 0x1C, 0x01, 0x80, 0x00, 0x14, 0x00,
0x80, 0x00, 0x14, 0x00, 0x80, 0x00, 0x14, 0x00, 0x40, 0x10, 0x12, 0x00, 0x40, 0x10, 0x12, 0x00,
0x7E, 0x1F, 0x23, 0xFE, 0x03, 0x31, 0xA0, 0x04, 0x01, 0xA0, 0xA0, 0x0C, 0x00, 0xA0, 0xA0, 0x08,
0x00, 0x60, 0xE0, 0x10, 0x00, 0x20, 0x60, 0x20, 0x06, 0x00, 0x40, 0x60, 0x03, 0x00, 0x40, 0xC0,
0x01, 0x80, 0x01, 0x80, 0x00, 0xC0, 0x03, 0x00, 0x00, 0x60, 0x06, 0x00, 0x00, 0x30, 0x0C, 0x00,
0x00, 0x08, 0x10, 0x00, 0x00, 0x06, 0x60, 0x00, 0x00, 0x03, 0xC0, 0x00, 0x00, 0x01, 0x80, 0x00  };
//---------------

ESP8266WebServer server(80); //--> Server on port 80

unsigned long previousMillisGetHR = 0;
unsigned long previousMillisHR = 0;

const long intervalGetHR = 10;
const long intervalHR = 10000;

const int PulseSensorHRWire = A0;
const int LED_D1 = D5;
int Threshold = 600;

int cntHB = 0;
boolean ThresholdStat = true;
int BPMval = 0;
int buzzer = D0;
int SYSval = 0;
int DIAval = 0;

void handleRoot()
{
    String s = MAIN_page;             //--> Read HTML contents
    server.send(200, "text/html", s); //--> Send web page
}
//--------------------------------------------------------------------------------
void handleHeartRate()
{
    digitalWrite(ON_Board_LED, LOW);
    String BPMvalSend = String(BPMval);
    server.send(200, "text/plane", BPMvalSend);
    digitalWrite(ON_Board_LED, HIGH);
}

void handleSYSPressure()
{
    String SYSvalSend = String(SYSval);
    server.send(200, "text/plane", SYSvalSend);
}
void handleDIAPressure()
{
    String DIAvalSend = String(DIAval);
    server.send(200, "text/plane", DIAvalSend);
}

void GetHeartRate()
{
    //----------------------------------------Process of reading heart rate.
    unsigned long currentMillisGetHR = millis();

    if (currentMillisGetHR - previousMillisGetHR >= intervalGetHR)
    {
        previousMillisGetHR = currentMillisGetHR;

        int PulseSensorHRVal = analogRead(PulseSensorHRWire);

        if (PulseSensorHRVal > Threshold && ThresholdStat == true)
        {
            cntHB++;
            ThresholdStat = false;
            digitalWrite(LED_D1, HIGH);
        }

        if (PulseSensorHRVal < Threshold)
        {
            ThresholdStat = true;
            digitalWrite(LED_D1, LOW);
        }
    }
    //----------------------------------------The process for getting the BPM value.
    unsigned long currentMillisHR = millis();

    if (currentMillisHR - previousMillisHR >= intervalHR)
    {
        previousMillisHR = currentMillisHR;

        BPMval = cntHB * 6;
        warning(BPMval);
        display.clear();
        display.drawBitmap(0,0, logo2_bmp, 24, 21);
        display.drawString(40,20,"BPM: " + String(BPMval) + " bpm");
        display.display();
        Serial.print("BPM : ");
        Serial.println(BPMval);
        calculateBloodPressure(BPMval);
        cntHB = 0;
    }
}
// This subroutine is for calculating the Blood Pressure.
void calculateBloodPressure(int _HR)
{
    //----------------------------------------The process for calculating the Blood Pressure.
//  SYSval = _HR * 0.6;
//  SYSval = 184 - 1.329*_HR + 0.0848*(600 - 250);
  SYSval = abs(184 - 0.629*_HR + 0.0848*((_HR/60000) - 250));
//  DIAval = _HR * 0.4;
  DIAval = abs(55.96 - 0.02912*_HR + 0.02302*(600 - 250));
  display.drawString(40,30,"SYS: " + String(SYSval) + " mmHg");
  display.drawString(40,40,"DIA: " + String(DIAval) + " mmHg");
  display.display();
  Serial.print("SYS : ");
  Serial.println(SYSval);
  Serial.print("DIA : ");
  Serial.println(DIAval);
}

//--------------------------------------------------------------------------------void setup()
void setup()
{
    // put your setup code here, to run once:
    Serial.begin(115200);
    delay(500);

    display.init();
    display.setFont(ArialMT_Plain_10);
    display.drawString(40,20,"Hey Siri");
    display.display();

    pinMode(buzzer, OUTPUT);
    pinMode(ON_Board_LED, OUTPUT);    //--> On Board LED port Direction output
    digitalWrite(ON_Board_LED, HIGH); //--> Turn off Led On Board

    pinMode(LED_D1, OUTPUT); //--> Set LED_3 PIN as Output.

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password); //--> Connect to your WiFi router
    Serial.println("");

    //----------------------------------------Wait for connection
    Serial.print("Connecting");
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        //----------------------------------------Make the On Board Flashing LED on the process of connecting to the wifi router.
        digitalWrite(ON_Board_LED, LOW);
        delay(250);
        digitalWrite(ON_Board_LED, HIGH);
        delay(250);
        //----------------------------------------
    }
    //----------------------------------------
    digitalWrite(ON_Board_LED, HIGH);
    Serial.println("");
    Serial.print("Successfully connected to : ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    Serial.println();
    //----------------------------------------

    server.on("/", handleRoot);
    server.on("/getHeartRate", handleHeartRate);
    server.on("/getSYSPressure", handleSYSPressure);
    server.on("/getDIAPressure", handleDIAPressure);

    server.begin(); //--> Start server
    Serial.println("HTTP server started");

    Serial.println();
    Serial.println("Please wait 10 seconds to get the BPM Value");
}
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------void loop()
void loop()
{
    // put your main code here, to run repeatedly:
    server.handleClient(); //--> Handle client requests
    GetHeartRate();        //--> Calling the GetHeartRate() subroutine
}
void warning(int _HRval){
  if((_HRval <= 49) || (_HRval >= 130)){
    digitalWrite(buzzer,HIGH);
    delay(2);
  }
  else{
    digitalWrite(buzzer,LOW);
    delay(2);
  }
}
