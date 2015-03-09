
#define R 0xFF0000 //Red
#define G 0x00FF00 //Green
#define B 0x0000FF //Blue
#define Y 0xFFFF00 //Yellow  uint32_t yellow = strip.Color(255,255,0);
#define L 0x0A0A0A //low power
#define OFF 0x000000
#include <Adafruit_NeoPixel.h>


#define GAMMA_MAX 255
#define PIXEL_PIN    3    // Digital IO pin connected to the NeoPixels.
#define PIXEL_COUNT 64

// Parameter 1 = number of pixels in strip,  neopixel stick has 8
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_RGB     Pixels are wired for RGB bitstream
//   NEO_GRB     Pixels are wired for GRB bitstream, correct for neopixel stick
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip), correct for neopixel stick

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

bool oldState = HIGH;
int showType = 0;

uint32_t DDlogoArray[64]={
	R,R,R,L,L,B,B,B,
	R,L,L,R,R,L,L,B,
	R,L,B,L,L,R,L,B,
	R,L,B,L,L,R,L,B,
	R,L,B,L,L,R,L,B,
	R,L,B,L,L,R,L,B,
	R,L,L,B,B,L,L,B,
	R,R,R,L,L,B,B,B
};

void setup() {

  //while(!Serial); //for leonardo boards only
  strip.begin();
  for(int i=0;i<64;i++) strip.setPixelColor(i,DDlogoArray[i]);
  strip.show(); // Initialize all pixels with the DDlogo

}

unsigned int gamma=GAMMA_MAX;
boolean dir=false;

void loop() {

for(gamma=GAMMA_MAX;gamma>0;gamma--) //dims the light
	{
		strip.setBrightness(gamma);
		strip.show();
		delay(1);
	}

for(gamma=1;gamma<GAMMA_MAX;gamma++) //brightens the light
	{
		strip.setBrightness(gamma);
		strip.show();
		delay(1);
	}
}