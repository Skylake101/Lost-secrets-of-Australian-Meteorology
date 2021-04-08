//Luke Carlson
//proton AAT

#include "SparkFunMicroOLED.h"  // Include MicroOLED library
#include "math.h"
#include "PietteTech_DHT.h"

#define DHTTYPE  DHT22       // Sensor type DHT11/21/22/AM2301/AM2302
#define DHTPIN   D2         // Digital pin for communications

//////////////////////////////////
// MicroOLED Object Declaration //
//////////////////////////////////
// Declare a MicroOLED object. If no parameters are supplied, default pins are
// used, which will work for the Photon Micro OLED Shield (RST=D7, DC=D6, CS=A2)
MicroOLED oled;
//MicroOLED oled(MODE_I2C, D7, 0);    // Example I2C declaration RST=D7, DC=LOW (0)

//SYSTEM_MODE(MANUAL);

PietteTech_DHT DHT(DHTPIN, DHTTYPE);
int n;      // counter

void printTitle(String, int);
int led1 = D1; //-------------------------------
void setup()
{
  pinMode(led1, OUTPUT);
  Serial.begin(9600);
  oled.begin();    // Initialize the OLED
  oled.clear(ALL); // Clear the display's internal memory
  oled.display();  // Display what's in the buffer (splashscreen)
  delay(1000);     // Delay 1000 ms
  randomSeed(analogRead(A0) + analogRead(A1));
}


void loop()
{

  int result = DHT.acquireAndWait(1000); // wait up to 1 sec (default indefinitely)

  switch (result) {
  case DHTLIB_OK:
    Serial.println("OK");
    break;
  case DHTLIB_ERROR_CHECKSUM:
    Serial.println("Error\n\r\tChecksum error");
    break;
  case DHTLIB_ERROR_ISR_TIMEOUT:
    Serial.println("Error\n\r\tISR time out error");
    break;
  case DHTLIB_ERROR_RESPONSE_TIMEOUT:
    Serial.println("Error\n\r\tResponse time out error");
    break;
  case DHTLIB_ERROR_DATA_TIMEOUT:
    Serial.println("Error\n\r\tData time out error");
    break;
  case DHTLIB_ERROR_ACQUIRING:
    Serial.println("Error\n\r\tAcquiring");
    break;
  case DHTLIB_ERROR_DELTA:
    Serial.println("Error\n\r\tDelta time to small");
    break;
  case DHTLIB_ERROR_NOTSTARTED:
    Serial.println("Error\n\r\tNot started");
    break;
  default:
    Serial.println("Unknown error");
    break;
  }
//==============================================

  printTitle("Hum:" + String(DHT.getHumidity()) + "\nTemp:" + String(DHT.getCelsius()), 0);
  analogWrite(led1, DHT.getHumidity() * 2.55);//----------------


  //AAT = TEMP + 0.33•(HUMID*6.105*exp (17.27*TEMP/(237.7+TEMP) − 0.70•0 − 4.00

      //When switch is Humidity
      printTitle("AAT:" + String(DHT.getCelsius() + 0.33 *(DHT.getHumidity() * 6.105 *exp(17.27 * DHT.getCelsius() /(237.7+ DHT.getCelsius()) - 0.70*0 -4.00))), 0);


//=========================================

  delay(2500);

//==========================TEMPERATURE FEELER
}


void printTitle(String title, int font)
{
  int middleX = oled.getLCDWidth() / 2;
  int middleY = oled.getLCDHeight() / 2;

  oled.clear(PAGE);
  oled.setFontType(font);
  // Try to set the cursor in the middle of the screen
  oled.setCursor(0, 0);
  // Print the title:
  oled.print(title);
  oled.display();
  delay(1500);
  oled.clear(PAGE);
}
