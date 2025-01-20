#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define sWidht 128
#define sHeight 64
#define buzzer 17
#define RLed 19
#define YLed 18
#define GLed 5
#define button 35

Adafruit_SSD1306 display(sWidht, sHeight, &Wire, -1);


void setup() {
  Serial.begin(115200);
  pinMode(buzzer, OUTPUT);
  pinMode(RLed, OUTPUT);
  pinMode(YLed, OUTPUT);
  pinMode(GLed, OUTPUT);
  pinMode(button, INPUT_PULLUP);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(("SSD1306 allocation failed"));
    for(;;);
  }

  delay(500);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(22, 32);
  display.println("Giri");
  display.display();
  delay(500);
}

void loop(){
  display.setCursor(25, 20);
  display.display();
  tone(buzzer, 1000);
  delay(1000);
  noTone(buzzer);
  tone(buzzer, 500);
  delay(1000);
  noTone(buzzer);
  delay(500);

  digitalWrite(RLed, HIGH);
  digitalWrite(YLed, HIGH);
  delay(1000);
  digitalWrite(RLed, LOW);
  digitalWrite(YLed, LOW);
  
  
  digitalWrite(GLed, HIGH);
}
