#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "OledAn.h"

float getDistance();

//OLED
#define SCREEN_I2C_ADDR 0x3C // or 0x3C
#define SCREEN_WIDTH 128     // OLED display width, in pixels
#define SCREEN_HEIGHT 64     // OLED display height, in pixels
#define OLED_RST_PIN -1      // Reset pin (-1 if not available)

Adafruit_SSD1306 display(128, 64, &Wire, OLED_RST_PIN);

//sensor pinout
int ECHO = 18; 
int TRIG = 5;
int frame =0;

//SCL 22
//SDA 21


void setup() {
  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
  Serial.begin(115200);


  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_I2C_ADDR);
   
}

void loop() {
  float distance = getDistance();
     
  display.clearDisplay();
  display.drawBitmap(32, 0, frames[frame], FRAME_WIDTH, FRAME_HEIGHT, 1);
  display.display();
  frame = (frame + 1) % FRAME_COUNT;
  delay(FRAME_DELAY);

  if (distance < 20.0)
  {
    Serial.println("Object in front");

    int turn = random(0, 2);
    if( turn == 0)
    {
      Serial.println("Turn right");
      //turn left =false;
    }
    else
    {
      Serial.println("Turn left");
      //turn right = false;
    }
  }
}

//function to get the distance
float getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG, LOW);

  int duration = pulseIn(ECHO, HIGH, 30000);
  float distance = duration * 0.034 / 2;

  Serial.print("Distance ");
  Serial.println(distance);

  return distance;
}
