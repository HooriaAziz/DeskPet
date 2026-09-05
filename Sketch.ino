#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "ConfusedFra.h"
#include "AngryFra.h"
#include "HappyFra.h"

enum moods {confused, angry, happy}; //only for simulation I will be adding 3 emotion states. The actual version will have more than thsi

float getDistance();
void emotions();

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

  if(distance < 5)
  {
    Serial.println("Stopped");
    emotions(angry);
  }

  else if (distance < 20.0)
  {
    Serial.println("Object in front");
    emotions(confused);

    int turn = random(0, 2);
    if( turn == 0) {
      Serial.println("Turn right");
      //turn left =false;
    }

    else{
      Serial.println("Turn left");
      //turn right = false;
    }
  }

   else
   {
    emotions(happy);
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

void emotions(moods mood)
{
  display.clearDisplay();

  switch (mood) {
    case confused:
      display.drawBitmap(32, 0, Confusedframes[frame], ConfuFRAME_WIDTH, ConfuFRAME_HEIGHT, 1);
      frame = (frame + 1) % ConfuFRAME_COUNT;
      
      break;
      case angry:
      display.drawBitmap(40, 8, Angryframes[frame], AngFRAME_WIDTH, AngFRAME_HEIGHT, 
      1);
      frame = (frame + 1) % AngFRAME_COUNT;

      break; 
      case happy:
        display.drawBitmap(40, 8, Happyframes[frame], HapFRAME_WIDTH, HapFRAME_HEIGHT, 1);
        frame = (frame + 1) % HapFRAME_COUNT;

      break;

      default:
      Serial.println("HOW DID YOU GET HERE?");
      break;      
  
  }
   display.display();
   delay(FRAME_DELAY);
    
  }
  
