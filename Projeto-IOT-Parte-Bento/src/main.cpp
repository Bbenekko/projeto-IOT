#include <Arduino.h>
#include <Adafruit_BME680.h>
#include <Adafruit_CCS811.h>

Adafruit_BME680 sensorBME;
Adafruit_CCS811 sensorCCS;

/*


TODO: o sensor particular (DSM 501A) não possui biblioteca, então terá que ser usado de maneira "crua"


*/

void setup() 
{
  Serial.begin(115200); delay(500);
  Serial.println("Projeto IOT - Parte Bento");

  if (!sensorBME.begin()) 
  { 
    Serial.println("Erro no sensor BME"); 
    while (true); 
  } 

  if (!sensorCCS.begin()) 
  { 
    Serial.println("Erro no sensor CCS"); 
    while (true); 
  } 

  // Calibrando BME
  // aumenta amostragem dos sensores (1X, 2X, 4X, 8X, 16X ou NONE) 
  sensorBME.setTemperatureOversampling(BME680_OS_8X); 
  sensorBME.setHumidityOversampling(BME680_OS_2X); 

  // Calibrando CCS
  float temp = sensorCCS.calculateTemperature();
  sensorCCS.setTempOffset(temp - 25.0);

}

void loop() 
{
  sensorBME.performReading();
  
  if (sensorCCS.available())
  {
    float eCO2 = sensorCCS.geteCO2();
    float TVOC = sensorCCS.getTVOC();
  }

  float temperatura = sensorBME.temperature; 
  float umidade = sensorBME.humidity;
}
