#include "WatchyCommodoreMaze.h"

const char* getRandWall() {
  return (rand() % 2) ? "/" : "\\";
}

void WatchyCommodoreMaze::drawWatchFace() {
  display.display(true);
  display.fillScreen(GxEPD_BLACK);
  display.setTextColor(GxEPD_WHITE);
  display.setFont(&C64_Pro_STYLE9pt7b);
  display.setCursor(0, 0);
  display.setTextWrap(false);
  srand(makeTime(currentTime));
  // int16_t x1, y1;
  // uint16_t w, h;
  for (int i=0; i < 12; i+=1) {
    for (int j=0; j < 10; j++) {
      display.print(getRandWall());
    }
    display.println();
  }
}