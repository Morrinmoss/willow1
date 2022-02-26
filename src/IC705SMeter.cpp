// Copyright (c) F4HWN Armel. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <IC705SMeter.h>
#include "functions.h"

// Setup
void setup()
{
  uint8_t loop = 0;

  // Debug
  Serial.begin(115200);

  // Init M5
  M5.begin(true, false, false, false);

  // Preferences
  preferences.begin(NAME);
  mode = preferences.getUInt("mode", 2);

  // Bin Loader
  binLoader();

  // Wifi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED && loop <= 10)
  {
    delay(250);
    loop += 1;
  }

  // Start server (for Web site Screen Capture)
  httpServer.begin();     

  // Let's go
  #if BOARD == CORE2
  M5.Axp.SetLed(0);
  #endif

  M5.Lcd.setBrightness(64);
  M5.Lcd.setRotation(1);
  M5.Lcd.fillScreen(TFT_BACK);

  M5.Lcd.drawJpg(smeterTop, sizeof(smeterTop), 0, 0, 320, 160);
  M5.Lcd.drawJpg(smeterBottom, sizeof(smeterBottom), 0, 160, 320, 80);

  /*
  M5.Lcd.setTextDatum(CC_DATUM);
  M5.Lcd.setFreeFont(0);
  M5.Lcd.setTextPadding(0);
  M5.Lcd.setTextColor(TFT_BLACK);
  M5.Lcd.drawString(String(NAME) + " V" + String(VERSION) + " by " + String(AUTHOR), 160, 145);

  if(WiFi.status() == WL_CONNECTED) {
    M5.Lcd.drawString(String(WiFi.localIP().toString().c_str()), 160, 155);
  }
  */

  CAT.register_callback(callbackBT);
 
  if(!CAT.begin(NAME)){
    Serial.println("An error occurred initializing Bluetooth");
  }else{
    Serial.println("Bluetooth initialized");
  }
}

// Main loop
void loop()
{
  uint8_t btnA;
  uint8_t btnB; 
  uint8_t btnC;

  if (btConnected == false) {
    value("NEED PAIRING");
  }

  M5.update();

  btnA = M5.BtnA.read();
  btnB = M5.BtnB.read();
  btnC = M5.BtnC.read();

  if(btnA == 1 || buttonLeftPressed == 1) {
    mode = 0;
    reset = true;
    buttonLeftPressed = 0;
  }
  else if(btnB == 1 || buttonCenterPressed == 1) {
    mode = 1;
    reset = true;
    buttonCenterPressed = 0;
  }
  else if(btnC == 1 || buttonRightPressed == 1) {
    mode = 2;
    reset = true;
    buttonRightPressed = 0;
  }

  preferences.putUInt("mode", mode);

  if (btConnected == true) {
    getFrequency();

    delay(25);

    switch (mode)
    {
    case 0:
      getPower();
      break;
    
    case 1:
      getSmeter();
      break;
    
    case 2:
      getSWR();
      break;
    }
  }

  viewOption();

  if (WiFi.status() == WL_CONNECTED)
  {
    getScreenshot();
  }

  delay(25);
}