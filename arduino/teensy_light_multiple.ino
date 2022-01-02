// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        7 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 17 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_RGB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels



void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pinMode(3, INPUT_PULLUP); 
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.show();

  Serial.begin(38400); 
}

int start = 0;
int white[] = {255, 255, 255}; //0
int red[] = {242, 92, 120};  //1
int pink[] = {255, 22, 148}; //2
int purple[] = {150, 130,205};  //3
int orange[] = {242, 135,5}; //4

int colors[][3] = {{255, 255, 255}, {242, 92, 120}, {255, 22, 148}, {150, 130,205}, {242, 135,5}}; 

int num_events = 76;
int col[][17] = {{5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}, {6, 5, 5, 5, 5, 5, 5, 5, 4, 5, 5, 5, 2, 5, 2, 5, 3}, {6, 4, 5, 5, 5, 5, 5, 5, 5, 5, 4, 5, 5, 2, 4, 5, 5}, {6, 5, 5, 5, 5, 5, 5, 5, 4, 5, 5, 5, 2, 5, 2, 5, 3}, {4, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {6, 5, 5, 4, 5, 5, 5, 5, 5, 4, 5, 5, 3, 5, 5, 4, 5}, {5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {6, 5, 3, 5, 5, 5, 5, 5, 5, 5, 2, 5, 5, 4, 5, 2, 5}, {2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {6, 3, 5, 5, 5, 5, 4, 5, 4, 5, 5, 5, 5, 5, 2, 5, 5}, {4, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {5, 4, 5, 5, 5, 5, 5, 5, 5, 5, 4, 5, 5, 2, 4, 5, 5}, {1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {2, 3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 2, 3, 5, 3, 5, 5}, {5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {4, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {6, 5, 5, 2, 5, 5, 3, 4, 5, 5, 5, 5, 5, 4, 5, 5, 5}, {5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {6, 5, 5, 5, 5, 5, 5, 5, 4, 5, 5, 5, 2, 5, 2, 5, 3}, {5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {6, 4, 5, 5, 5, 5, 5, 5, 5, 5, 4, 5, 5, 2, 4, 5, 5}, {1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {6, 3, 5, 5, 5, 5, 4, 5, 4, 5, 5, 5, 5, 5, 2, 5, 5}, {5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {2, 5, 5, 4, 5, 5, 5, 5, 5, 4, 5, 5, 3, 5, 5, 4, 5}, {5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {6, 3, 5, 5, 5, 5, 4, 5, 5, 5, 5, 5, 2, 5, 5, 4, 5}, {1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {6, 5, 5, 4, 5, 5, 5, 5, 5, 4, 5, 5, 3, 5, 5, 4, 5}, {2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {5, 4, 3, 5, 5, 5, 5, 5, 5, 5, 5, 4, 5, 4, 5, 5, 5}, {3, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {6, 3, 5, 5, 5, 5, 4, 5, 4, 5, 5, 5, 5, 5, 2, 5, 5}, {5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {6, 2, 5, 5, 2, 5, 5, 2, 5, 5, 5, 5, 5, 5, 5, 5, 2}, {2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {0, 5, 5, 5, 5, 5, 5, 5, 4, 5, 5, 5, 2, 5, 2, 5, 3}, {6, 3, 5, 5, 5, 5, 4, 5, 4, 5, 5, 5, 5, 5, 2, 5, 5}, {5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {6, 5, 5, 5, 5, 4, 5, 5, 5, 3, 5, 5, 2, 5, 5, 4, 5}, {5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {4, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {6, 5, 5, 5, 5, 5, 5, 5, 4, 5, 5, 5, 2, 5, 2, 5, 3}, {5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {6, 3, 5, 5, 5, 5, 4, 5, 4, 5, 5, 5, 5, 5, 2, 5, 5}, {5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {6, 5, 5, 5, 5, 5, 5, 5, 4, 5, 5, 5, 2, 5, 2, 5, 3}, {2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {6, 3, 5, 5, 5, 5, 4, 5, 4, 5, 5, 5, 5, 5, 2, 5, 5}, {1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {6, 3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 2, 3, 5, 3, 5, 5}, {5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {6, 5, 5, 5, 5, 5, 5, 5, 4, 5, 5, 5, 2, 5, 2, 5, 3}, {2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {6, 5, 5, 2, 3, 5, 5, 5, 3, 5, 5, 5, 5, 5, 5, 5, 5}, {5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {6, 3, 5, 5, 5, 5, 4, 5, 4, 5, 5, 5, 5, 5, 2, 5, 5}, {6, 2, 5, 5, 4, 3, 5, 5, 5, 5, 5, 3, 5, 5, 5, 5, 5}, {6, 5, 5, 5, 5, 5, 5, 5, 4, 5, 5, 5, 2, 5, 2, 5, 3}, {6, 5, 5, 4, 5, 5, 5, 5, 5, 4, 5, 5, 3, 5, 5, 4, 5}, {6, 5, 5, 5, 5, 5, 5, 5, 4, 5, 5, 5, 2, 5, 2, 5, 3}, {6, 5, 5, 2, 3, 5, 5, 5, 3, 5, 5, 5, 5, 5, 5, 5, 5}, {6, 5, 5, 5, 5, 5, 5, 5, 4, 5, 5, 5, 2, 5, 2, 5, 3}, {6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}};
float durations[] = {16150.0, 2550.0, 4250.0, 1700.0, 850.0, 2125.0, 425.0, 425.0, 2550.0, 425.0, 425.0, 2125.0, 850.0, 2550.0, 850.0, 2125.0, 850.0, 1275.0, 850.0, 850.0, 850.0, 2125.0, 425.0, 425.0, 1275.0, 850.0, 1700.0, 1700.0, 850.0, 2125.0, 425.0, 425.0, 2125.0, 425.0, 2125.0, 850.0, 2125.0, 850.0, 425.0, 2125.0, 425.0, 425.0, 2125.0, 850.0, 2550.0, 850.0, 850.0, 850.0, 1275.0, 850.0, 1275.0, 1275.0, 850.0, 425.0, 2125.0, 425.0, 425.0, 2125.0, 425.0, 2125.0, 850.0, 850.0, 2125.0, 425.0, 425.0, 2125.0, 425.0, 2975.0, 2550.0, 3400.0, 2550.0, 2550.0, 2550.0, 3400.0, 2550.0};
void loop() {
  if(digitalRead(3) == LOW){
    Serial.println("1"); 
    start = 1; 
  }
  else{
    Serial.println("0");
  }
  if (start == 0){
    delay(10);
  }
  else{
    for (int i = 0; i < num_events; i++){ //loop over all events
      int event_dur = durations[i];
      for (int j = 0; j < 17; j ++){ //loop over each LED
        int color_ind = col[i][j];
        if (color_ind == 6){ //if 6, do nothing to that LED
          ;
        }
        else if (color_ind == 5){ //if 5, turn LED off
          pixels.setPixelColor(j, pixels.Color(0, 0, 0)); 
        }
        else{
          if (j == 0){
            pixels.setPixelColor(j, pixels.Color(colors[color_ind][0], colors[color_ind][1], colors[color_ind][2]));
          }
          else{
            pixels.setPixelColor(j, pixels.Color(colors[color_ind][1], colors[color_ind][0], colors[color_ind][2]));
          }
        }
      }
      pixels.show();
      delay(event_dur); 
    }

  }
  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  //for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
   // pixels.setPixelColor(i, pixels.Color(242, 234,223)); //white
   //pixels.setPixelColor(i, pixels.Color(242, 92,120)); //pinkish red
   //pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    //pixels.setPixelColor(i, pixels.Color(166, 65,102)); //pinkish red
    //pixels.setPixelColor(i, pixels.Color(90, 39,82)); //purple
    //pixels.setPixelColor(i, pixels.Color(242,135, 5)); //orange
    //pixels.show();   // Send the updated pixel colors to the hardware.

   // delay(DELAYVAL); // Pause before next pass through loop
  start = 0; 
}
