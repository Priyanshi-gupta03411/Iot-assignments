#include <Wire.h>          // Required for I2C communication
#include <Adafruit_GFX.h>  // Core graphics library
#include <Adafruit_SSD1306.h> // Hardware-specific driver for SSD1306

// Define the display dimensions
#define SCREEN_WIDTH 128    // OLED display width, in pixels (change for 128x32)
#define SCREEN_HEIGHT 64   // OLED display height, in pixels (change for 128x32)

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// Reset pin # (or -1 if sharing Arduino reset pin)
#define OLED_RESET    -1 
// The I2C address for the display (usually 0x3C or 0x3D)
#define SCREEN_ADDRESS 0x3C 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);
  
  // Initialize the OLED display
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  
  // Clear the display buffer
  display.clearDisplay(); 

  // Set up text properties
  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(WHITE); // Draw white text
  display.setCursor(0, 10);    // Start at top-left corner, shifted down 10 pixels

  // Print text to the buffer
  display.println("Hello, World!");
  
  // Show the display buffer contents on the screen
  display.display();
  delay(2000);
}

void loop() {
  // You can clear the screen, update text/graphics, and call display.display() here
}