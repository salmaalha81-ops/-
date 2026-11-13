#include <SPI.h>
#include <GxEPD2_3C.h>

// توصيلات الشاشة مع ESP32-S3
#define EPD_CS    10
#define EPD_DC     4
#define EPD_RST    5
#define EPD_BUSY   6
#define EPD_SCK   12
#define EPD_MOSI  11

// تعريف تجريبي لشاشة 2.9 بوصة ثلاثية الألوان
GxEPD2_3C<GxEPD2_290_C90c, GxEPD2_290_C90c::HEIGHT> display(
    GxEPD2_290_C90c(EPD_CS, EPD_DC, EPD_RST, EPD_BUSY)
);

void setup() {
  Serial.begin(115200);

 SPI.begin(EPD_SCK, -1, EPD_MOSI, -1);
  Serial.println("SPI started successfully");
Serial.println("Starting E-Paper...");
  display.init(115200, true, 2, false);
  Serial.print("BUSY pin = ");
Serial.println(digitalRead(EPD_BUSY));
  display.setRotation(1);
  display.setFullWindow();

  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);

    display.setTextColor(GxEPD_BLACK);
    display.setTextSize(1);
    display.setCursor(10, 15);
    display.print("Fahad");
    display.setCursor(10, 30);
display.print("Age: 24");
display.setCursor(10, 45);
display.print("ID: 0000000000");

    display.setTextColor(GxEPD_RED);
    display.setCursor(10, 60);
    display.print("Blood Type: O+");
    display.setCursor(10, 75);
display.print("Allergy: Penicillin");
display.setCursor(10, 90);
display.print("DM2, Heart Disease");
display.setCursor(10, 105);
display.print("Emergency: 0500000000");
display.fillCircle(245, 18, 10, GxEPD_BLACK);
display.fillRoundRect(232, 32, 26, 43, 8, GxEPD_BLACK);
display.drawLine(237, 38, 220, 68, GxEPD_BLACK);
display.drawLine(253, 38, 270, 68, GxEPD_BLACK);
display.drawLine(239, 74, 230, 105, GxEPD_BLACK);
display.drawLine(251, 74, 260, 105, GxEPD_BLACK);
display.fillCircle(242, 45, 4, GxEPD_RED);
display.fillCircle(249, 45, 4, GxEPD_RED);
display.fillTriangle(238, 47, 253, 47, 245, 58, GxEPD_RED);
  } while (display.nextPage());
}

void loop() {
}