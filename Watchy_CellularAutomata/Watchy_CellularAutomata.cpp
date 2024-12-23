#include "Watchy_CellularAutomata.h"
// #include "transformation_rules.h"
#include <random>

// Global variables for dynamic memory management
bool** grid = nullptr;
const int cellSize = 2;  // Scale the pattern up or down
const int width = 200 / cellSize;
const int height = 200 / cellSize;
int rule = -1;

void allocateGrid() {
  if (grid == nullptr) {
    grid = new bool*[height];
    for (int i = 0; i < height; ++i) {
      grid[i] = new bool[width]{ 0 };
    }
  }
}

void freeGrid() {
  if (grid != nullptr) {
    for (int i = 0; i < height; ++i) {
      delete[] grid[i];
    }
    delete[] grid;
    grid = nullptr;
  }
}

// void WatchyCellularAutomata::showBuzz() {
//   display.setFullWindow();
//   display.fillScreen(GxEPD_BLACK);
//   display.setFont(&FreeMonoBold9pt7b);
//   display.setTextColor(GxEPD_WHITE);
//   display.setCursor(0, 80);
//   display.display(false); // full refresh

//   int rule = (currentTime.Hour * 60 + currentTime.Minute) % 256;
//   int minRule = rule;
//   bool conj = true;
//   bool refl = true;

//   display.println("rule " + String(rule) + " recipe");
//   display.print("-------------");
//   if (rule > 9) display.print("-");
//   if (rule > 99) display.print("-");

//   display.println("rule " + minRule);
//   if (conj) display.println("  +conjugated");
//   if (refl) display.println("  +reflected");

//   display.printf("table vals: %d %d% d% d% d% %d\n", myTable[0],myTable[1],myTable[2],myTable[3],myTable[4],myTable[5]);


//   // sensor.getCounter();
//   // getWeatherData()
//   // getBatteryVoltage / 4.2
//   // get wifi status

//   // showWatchFace();
// }

void WatchyCellularAutomata::showCAinfo() {
  display.fillScreen(GxEPD_WHITE);  // Clear the display
  display.setTextColor(GxEPD_BLACK);
  display.setFont(&Px437_IBM_BIOS5pt7b);
  display.setCursor(85, 100);
  display.printf("Rule: %d", rule);
  delay(3000);
  return;
}

void WatchyCellularAutomata::drawWatchFace() {

  allocateGrid();  // Ensure grid is allocated

  // int time_12h = hourFormat12(makeTime(currentTime));

  char time[6];
  // snprintf(time, sizeof(time), "%02d:%02d", time_12h, currentTime.Minute);
  snprintf(time, sizeof(time), "%02d:%02d", currentTime.Hour, currentTime.Minute);

  char date[6];
  snprintf(date, sizeof(date), "%02d/%02d", currentTime.Month, currentTime.Day);

  // Worldwide UTC-0 datetime cipher seed
  // Format "DD + MM + YYYY + W + HH + MM"
  // Ensures all time accurate Watchys always display the same random CA pattern, worldwide
  tmElements_t UTC_tm;
  time_t UTC_0 = makeTime(currentTime) - settings.gmtOffset;
  breakTime(UTC_0, UTC_tm);
  // char cipherSeed[26]; // 25 chars * 8 bits = 200 pixels + null terminator
  // snprintf(cipherSeed, sizeof(cipherSeed), "%02d%02d%04d%02d%02d%d%02d%02d%04d%02d%02d",
  //   UTC_tm.Day, UTC_tm.Month, UTC_tm.Year + 1970, // Adjust UTC_tm.Year if necessary
  //   UTC_tm.Hour, UTC_tm.Minute, UTC_tm.Wday,
  //   UTC_tm.Day, UTC_tm.Month, UTC_tm.Year + 1970, // Repeat for the second half
  //   UTC_tm.Hour, UTC_tm.Minute);

  // bool cipherBitarray[200] = {0};

  // for(int i = 0; i < 25; i++) {
  //   char ch = cipherSeed[i];
  //   for(int bit = 0; bit < 8; bit++) {
  //     int pos = i * 8 + bit;
  //     cipherBitarray[pos] = (ch >> (7 - bit)) & 1;
  //   }
  // }

  // Randomly initialize the first row
  // for (int i = 0; i < width; i++) {
  //     // Just do a whole buncha scramblin
  //     int x = (UTC_tm.Minute << 6) * i + (UTC_tm.Hour << 12) * i;
  //     x ^= UTC_tm.Day * i + (UTC_tm.Month << 5) * i + ((UTC_tm.Year % 100) << 9) * i;
  //     x ^= UTC_tm.Wday << 16 * i;
  //     // Finally seed rand with the synced seed
  //     srand(x);
  //     x += rand();
  //     x ^= 1;
  //     x ^= x << 13;
  //     x ^= x >> 17;
  //     x ^= x << 5;
  //     grid[0][i] = x % 2;
  // }

  // Randomly initialize the first row
  for (int i = 0; i < width; i++) {
    int seed = UTC_tm.Year + UTC_tm.Month + UTC_tm.Day + UTC_tm.Wday + UTC_tm.Hour + UTC_tm.Minute;
    seed = seed * i + i + seed;
    // srand(seed);
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> distrib(0, 1);
    // int x = rand();
    int x = distrib(gen);
    grid[0][i] = x % 2;
  }

  rule = (currentTime.Hour * 60 + currentTime.Minute) % 256;

  for (int y = 1; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int left = (x == 0) ? 0 : grid[y - 1][x - 1];
      int center = grid[y - 1][x];
      int right = (x == width - 1) ? 0 : grid[y - 1][x + 1];
      int pattern = left * 4 + center * 2 + right;

      // Determine new state based on the rule's binary representation
      grid[y][x] = (rule >> pattern) & 1;
    }
  }

  // Display the pattern on the e-paper display
  display.fillScreen(GxEPD_WHITE);  // Clear the display
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      if (grid[y][x]) {
        //display.drawPixel(x, y, GxEPD_BLACK);
        display.fillRect(x * cellSize, y * cellSize, cellSize, cellSize, GxEPD_BLACK);
        //display.fillRoundRect(x * cellSize, y * cellSize, cellSize, cellSize, (x + y) % 100, GxEPD_BLACK);
        //display.fillCircle(x * cellSize, y * cellSize, cellSize, cellSize, GxEPD_BLACK);
      }
    }
  }

  // Draw the rest of the owl

  // Display the time
  display.setTextColor(GxEPD_BLACK);
  int16_t x1, y1;
  uint16_t w, h;

  display.setFont(&abduction200230pt7b);
  display.getTextBounds(time, 0, 0, &x1, &y1, &w, &h);  // Get bounds for centering
  int timeX = (200 - w) / 2;
  int timeY = (200 / 2) - h;  // Adjust for vertical centering
  display.fillRoundRect(timeX - 5, timeY - 5, w + 10, h + 10, 10, GxEPD_WHITE);
  display.drawRoundRect(timeX - 5, timeY - 5, w + 10, h + 10, 10, GxEPD_BLACK);

  if (currentTime.Hour == 3 && currentTime.Minute == 14) {
    display.drawBitmap((200 - 50) / 2, timeY, pi, 50, 50, GxEPD_BLACK);
  } else {

    display.setCursor(timeX, timeY + h);
    display.println(time);
  }

  // Display the date below the time
  display.setFont(&Px437_IBM_BIOS5pt7b);
  display.getTextBounds(date, 0, 0, &x1, &y1, &w, &h);  // Recalculate bounds for the date
  int dateX = (200 - w) / 2;
  int dateY = timeY + h + 53;  // Position below the time display
  display.fillRoundRect(dateX - 5, dateY - 5, w + 10, h + 10, 10, GxEPD_WHITE);
  display.drawRoundRect(dateX - 5, dateY - 5, w + 10, h + 10, 10, GxEPD_BLACK);

  if (currentTime.Month == 3 && currentTime.Day == 14) { //Change to 3/14
    int pi_size = 14;
    dateY = timeY + (pi_size / 2) + 53;
    display.drawBitmap((200 - pi_size) / 2, dateY, pi_small, pi_size, pi_size, GxEPD_BLACK);
  } else {
    display.setCursor(dateX, dateY + h);
    display.println(date);
  }

  // Display the current CA rule in the bottom right corner
  String ruleText = "rule " + String(rule);
  // Calculate the width and height of the text to be displayed
  display.getTextBounds(ruleText, 0, 200, &x1, &y1, &w, &h);
  int textX = 3;            // 3 pixels padding from the left edge
  int textY = 200 - h - 3;  // Adjust for padding from the bottom edge
  display.fillRect(textX - 3, textY - 3, w + 6, h + 6, GxEPD_WHITE);
  display.setCursor(textX, textY + h);  // Adjust cursor to the bottom-left of the text, considering its height
  display.print(ruleText);

  freeGrid();
}