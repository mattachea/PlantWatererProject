#include "OLEDDisplayer.h"

OLEDDisplayer::OLEDDisplayer() {}

OLEDDisplayer::OLEDDisplayer(int OLEDPin) {
  // Set the proper pin
  this->OLEDPin = OLEDPin;

  // Check Dimensions of OLED in Library, if incorrect edit file
  #if (SSD1306_LCDHEIGHT != 64)
  #error("Height incorrect; edit the screen height in Adafruit_SSD1306.h file");
  #endif

  // initialize display and set proper settings
  this->display = new Adafruit_SSD1306(OLEDPin);  
  display->begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display->clearDisplay(); 
  display->setTextSize(1);
  display->setTextColor(WHITE);
}

void OLEDDisplayer::displayData(Plant p[], int count) {
  // Clear the what was previously on the Display
  display->clearDisplay();
  display->setCursor(0,0);

  // If there are no plants, display an error and exit
  if (count < 1) {
    display->println("Error");
    display->display();
    return;
  }

  // Display Light value and Temperature value only once
  display->print("Light:        ");
  display->print(p[0].getLightSensorValue());
  display->println("%");
  display->print("Degrees F:    ");
  display->println(p[0].getTempSensorValue());

  // For each Plant, display the soil value 
  for (int i=0; i < count; i++) {
    display->print("Soil  ");
    display->print(p[i].getPlantNum());
    display->print(":      ");
    display->println(p[i].getSoilSensorValue());
    display->print("Hours ");
    display->print(p[i].getPlantNum());
    display->print(":      ");
    display->println(p[i].getHoursSinceWater());
  }
  
  // Push to the screen
  display->display();
}






/*
void OLEDDisplayer::clearScreen() {
  display->clearDisplay();
  display->setCursor(0,0);
}
*/



/*
void OLEDDisplayer::displayData(Plant p) {
  displayData(p.getPlantNum(), p.getSoilSensorValue(), p.getLightSensorValue(), p.getTempSensorValue(), p.getHoursSinceWater());
}
*/

/*
void OLEDDisplayer::displayData(int plantNumber, int soilMoistureReading, int lightReading, int tempReading, int hoursPassed) {
  //Shouldn't be here
  //display->clearDisplay();
  //display->setCursor(0,0);
  display->print("Plant: ");
  display->println(plantNumber);
  display->print("Moisture: ");
  display->println(soilMoistureReading);
  display->print("Light Percent: ");
  display->print(lightReading);
  display->println("%");
  display->print("Degrees F: ");
  display->println(tempReading);
  display->print("Hours Passed: ");
  display->println(hoursPassed);
  //display->display();
}
*/

/*
void OLEDDisplayer::displayData(Plant p[], int count) {
  //Serial.print("display_data");
  display->clearDisplay();
  display->setCursor(0,0);
  display->print("display_data");
  display->display();
  for (int i=0; i < count; i++) {
    Serial.print("i:");
    Serial.println(i);
    displayData(p[i].getPlantNum(), p[i].getSoilSensorValue(), p[i].getLightSensorValue(), p[i].getTempSensorValue(), p[i].getHoursSinceWater());
  }
  display->display();
}
*/
