#include <PCD8544.h>

PCD8544 lcd;
void setup() {
   lcd.begin(84, 48);
}
void loop() {
  lcd.setCursor(0, 0);
  lcd.print("   IT'S ALIVE!  ");
  //delay(300);
 }
