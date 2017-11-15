#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

int pinCS = 10; // Attach CS to this pin, DIN to MOSI and CLK to SCK (cf http://arduino.cc/en/Reference/SPI )
int numberOfHorizontalDisplays = 8;
int numberOfVerticalDisplays = 1;

/*arduino pin connection
 
             UNO R3 pin   MAX PIN
                  10      CS 
                  11      DIN
                  13      CLK 
                  GND     GND
                  5V      VCC
**/


Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);

String tape = "WWW.IoTWEBPLANET.COM ......  Online Store for Makers .";
int wait = 100; // In milliseconds

int spacer = 1;
int width = 5 + spacer; // The font width is 5 pixels
int direction=1;
void setup() {

  matrix.setIntensity(15); // Use a value between 0 and 15 for brightness

matrix.setRotation(0, direction);
matrix.setRotation(1, direction);
matrix.setRotation(2, direction);
matrix.setRotation(3, direction); 
matrix.setRotation(4, direction);
matrix.setRotation(5, direction);
matrix.setRotation(6, direction);
matrix.setRotation(7, direction);
 
}

void loop() {

  for ( int i = 0 ; i < width * tape.length() + matrix.width() - 1 - spacer; i++ ) {

    matrix.fillScreen(LOW);

    int letter = i / width;
    int x = (matrix.width() - 1) - i % width;
    int y = (matrix.height() - 8) / 2; // center the text vertically

    while ( x + width - spacer >= 0 && letter >= 0 ) {
      if ( letter < tape.length() ) {
        matrix.drawChar(x, y, tape[letter], HIGH, LOW, 1);
      }

      letter--;
      x -= width;
    }

    matrix.write(); // Send bitmap to display

    delay(wait);
  }
}

