#include "CYD28_TouchscreenR.h"
#include <SPI.h>

#define CYD28_DISPLAY_HOR_RES_MAX 320
#define CYD28_DISPLAY_VER_RES_MAX 240

bool previousTrackStatus = false;
bool nextTrackStatus = false;

CYD28_TouchR ts(CYD28_DISPLAY_HOR_RES_MAX, CYD28_DISPLAY_VER_RES_MAX);

void touchSetup() {
  ts.begin();
  ts.setRotation(1);
}

bool handleTouched() {
  previousTrackStatus = false;
  nextTrackStatus = false;
  if (ts.touched()) {
    CYD28_TS_Point p = ts.getPointScaled();
    Serial.print("Pressure = ");
    Serial.print(p.z);
    Serial.print(", x = ");
    Serial.print(p.x);
    Serial.print(", y = ");
    Serial.print(p.y);
    delay(30);
    Serial.println();
    if (p.x < 120) {
      previousTrackStatus = true;
      return true;
    } else if (p.x > 200) {
      nextTrackStatus = true;
      return true;
    }
  }
  return false;
}
