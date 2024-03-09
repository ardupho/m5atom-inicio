#include <Arduino.h>
#include <M5Atom.h>
#include <Adafruit_NeoPixel.h>

#define PIN       27  
#define NUMPIXELS 25 

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(
    NUMPIXELS, PIN,
    NEO_GRB + NEO_KHZ800);  // establecer el número de LED, número de pin, tipo de LED.
                        
uint32_t Wheel(byte WheelPos);
void rainbow(uint8_t wait);

void setup() {
    M5.begin();      // inicializa M5Atom.
    pixels.begin();  // inicializa la libreria NeoPixel.
    pixels.setBrightness(50); // Establezca BRILLO en aproximadamente 1/5 (máx. = 255)  
}

void loop() {
    rainbow(25);
}

void rainbow(uint8_t wait) {
    uint16_t i, j;

    for (j = 0; j < 256; j++) {
        for (i = 0; i < pixels.numPixels(); i++) {
            pixels.setPixelColor(i, Wheel((i + j) & 255));
            while (M5.Btn.read() == 1);
        }
        pixels.show();
        delay(wait);
    }
}

// Ingrese un valor de 0 a 255 para obtener un valor de color.
// Los colores son una transición r - g - b - de regreso a r..
uint32_t Wheel(byte WheelPos) {
    WheelPos = 255 - WheelPos;
    if (WheelPos < 85) {
        return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
    }
    if (WheelPos < 170) {
        WheelPos -= 85;
        return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
    }
    WheelPos -= 170;
    return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}