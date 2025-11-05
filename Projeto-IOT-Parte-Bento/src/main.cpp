#include <Arduino.h>
#include <Adafruit_BME680.h>

Adafruit_BME680 sensorBME;

void setup() 
{
  Serial.begin(115200); delay(500);
  Serial.println("Projeto IOT - Parte Bento");

  if (!sensorBME.begin()) 
  { 
    Serial.println("Erro no sensor BME"); 
    while (true); 
  } 

  // aumenta amostragem dos sensores (1X, 2X, 4X, 8X, 16X ou NONE) 
  sensorBME.setTemperatureOversampling(BME680_OS_8X); 
  sensorBME.setHumidityOversampling(BME680_OS_2X); 

}

void loop() 
{
  sensorBME.performReading();

  float temperatura = sensorBME.temperature; 
  float umidade = sensorBME.humidity;
}
