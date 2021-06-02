#include <PCD8544.h>
#include<FMTX.h>

PCD8544 lcd;

// Default FM frequency.
float fm_freq = 90;

float channel=0;

// Read from potentiometers
int pot_read = 0;
float pot_read_dec = 0;

// Set frequency range
int freq_max = 108;
int freq_min = 87;

// Set decimals range
int dec_min = 0;
int dec_max = 10;

// Mapped values of the analog readings
int mapping_reading=000;
float mapping_reading_dec=00;

int current_reading=000;
int current_reading_dec=00;

// Read any tunning change
void tunning_read(){
   channel=mapping_reading + mapping_reading_dec / 10;
   current_reading = mapping_reading;
   current_reading_dec = mapping_reading_dec;
   fmtx_set_freq(channel);
   Serial.print(channel);
}

// Change frequency shown on lcd
void lcd_freq(float value){
  lcd.setCursor(0, 2);
  lcd.print("Frequency: ");
  lcd.setCursor(0,3);
  lcd.print(value, 2);
  lcd.print(" MHz");
}

void setup() {
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);

  Serial.begin(9600);
  lcd.begin(84, 48);

  lcd.setCursor(0, 0);
  lcd.print("   WELCOME!  ");
  fmtx_init(fm_freq, EUROPE);
  delay(5000);
  lcd.clear();
}

void loop() {
  // Read and map main frequency
  pot_read=analogRead(A0);   
  mapping_reading=map(pot_read,0,1023,freq_min,freq_max);
  mapping_reading=constrain(mapping_reading,freq_min,freq_max);

  // Read and map decimals
  pot_read_dec=analogRead(A1);   
  mapping_reading_dec=map(pot_read_dec,0,1023,dec_min,dec_max);
  mapping_reading_dec=constrain(mapping_reading_dec,dec_min,dec_max);

  if( mapping_reading!= current_reading ||
    mapping_reading_dec != current_reading_dec){
    lcd.clear();
    tunning_read();
    lcd_freq(channel);
    delay(100);
  }
 }
 
