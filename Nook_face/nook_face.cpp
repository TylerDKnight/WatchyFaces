#include "nook_face.h"

const unsigned char* authors[10] = {
    Bronte_Sisters,
    Edgar_Allan_Poe,
    Gertrude_Stein,
    Homer,
    Joseph_Conrad,
    Jules_Verne,
    Kurt_Vonnegut,
    Oscar_Wilde,
    Virginia_Woolf,
    Walt_Whitman
};

const char* author_names[10] = {
    "Bronte Sisters",
    "Edgar Allan Poe",
    "Gertrude Stein",
    "Homer",
    "Joseph Conrad",
    "Jules Verne",
    "Kurt Vonnegut",
    "Oscar Wilde",
    "Virginia Woolf",
    "Walt Whitman"
};

void WatchyNookFace::drawWatchFace() {
    char time[6];
    char hourStr[3], minuteStr[3];

    int hour12 = currentTime.Hour % 12;
    hour12 = hour12 ? hour12 : 12;

    // Components for block display
    snprintf(hourStr, sizeof(hourStr), "%02d", hour12); // Swap hour12 with currentTime.Hour for 24h format
    snprintf(minuteStr, sizeof(minuteStr), "%02d", currentTime.Minute);

    int authorIndex = currentTime.Hour % 10; // Ensure the index loops every 10 hours

    display.fillScreen(GxEPD_WHITE);  // Clear the display

    display.drawBitmap(0, 5, authors[authorIndex], 150, 200, GxEPD_BLACK); // Should display a different author bitmap every hour

    // Draw a low battery icon below the time if needs to be charged
    float VBAT = getBatteryVoltage();
    if (VBAT < 3.9) display.drawBitmap(162, 138, low_batt, 26, 26, GxEPD_BLACK);
    // display.drawBitmap(162, 148, low_batt, 26, 26, GxEPD_BLACK); // No conditional for debugging purposes

    display.setTextColor(GxEPD_BLACK);
    display.setFont(&FreeSerifBoldItalic24pt7b);
    display.setTextWrap(false);

    // Draw the time in one vertical column
    // snprintf(time, sizeof(time), "%s:%s", hourStr, minuteStr); // Formats a string for the column display
    // int startX = 160; // Start X position
    // int startY = 50; // Start Y position
    // int lineHeight = 35; // Line height
    // for (int i = 0; i < strlen(time); i++) {
    //     // display.setCursor(startX - (15 * ((i % 3)==true)), startY + (i * lineHeight)); // Stagger the digits
    //     display.setCursor(startX, startY + (i * lineHeight));
    //     display.print(time[i]);
    // }

    // Draw in a square
    int gap = 8;
    int padding = 2;
    int startX = 150 + padding;
    int startY = (200 / 2); // Center the Y
    int16_t x1, y1;
    uint16_t w, h;

    // Hours
    display.getTextBounds(hourStr, 0, 0, &x1, &y1, &w, &h);
    display.setCursor(startX, startY - gap);
    display.print(hourStr);

    // Separator
    display.drawFastHLine(startX, startY, 200 - startX - padding, GxEPD_BLACK);

    // Minutes
    display.getTextBounds(minuteStr, 0, 0, &x1, &y1, &w, &h);
    display.setCursor(startX, startY + h + (gap / 2)); // idk why its / 2
    display.print(minuteStr);

    padding = 2;
    display.setFont(&Colour_Me_Purple_2_9pt7b);
    display.setCursor(padding, 200 - padding);
    display.getTextBounds(author_names[authorIndex], padding, 200 - padding, &x1, &y1, &w, &h);
    display.fillRect(x1 - padding, y1 - padding, w + padding, h + padding, GxEPD_BLACK);
    display.setTextColor(GxEPD_WHITE);
    display.print(author_names[authorIndex]);

    // Full refresh on the hour
    (currentTime.Minute == 0) ? display.display(false) : display.display(true);
}