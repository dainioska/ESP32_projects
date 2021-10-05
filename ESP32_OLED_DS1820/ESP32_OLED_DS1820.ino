//ESP32_OLED_DS18B20 test OK
//2021-09-30
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 13

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSerif9pt7b.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

float T = 0.0;

void setup(void)
{
Serial.begin(9600);     
sensors.begin();  
display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
display.clearDisplay();     
delay(500);
display.setFont(&FreeSerif9pt7b);
display.clearDisplay();
display.setTextSize(1);             
display.setTextColor(WHITE);        
display.setCursor(0,30);             
display.println("Temperatura test");
display.print("    DS18B20");
display.display();
delay(3000); 
display.clearDisplay();
}

void loop(void){ 
float T = sensors.getTempCByIndex(0);
sensors.requestTemperatures(); 
Serial.print("Celsius temperature: ");  
Serial.println(T);  
 
display.setTextSize(1);
display.setTextColor(WHITE); display.setCursor(20,30);
display.println("Temperatura: ");  
display.print(T);
display.print(" ");
display.cp437(true);      // code page 437
display.write(167);       // character 167 is degree
display.println("C");
display.display();    
delay(1000);
display.clearDisplay();
}
