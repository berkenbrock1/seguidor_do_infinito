#include <QTRSensors.h>
#include "Defines.h"

QTRSensors qtr;

const uint8_t SensorCount = 15;
uint16_t sensorValues[SensorCount];
const uint8_t ValorBase = 500*(SensorCount - 1);

void setup()
{
  // configure the sensors
  qtr.setTypeRC();
  /*qtr.setSensorPins((const uint8_t[]) {PB12, PA12, PB13, PA15, PB14, PB3, PB15, PB4, PA8, PB6, PA9, PB7, PA10, PB8, PA11}, SensorCount);*/
  qtr.setSensorPins((const uint8_t[]) {PB12, PB13, PB14, PB15, PA8, PA9, PA10, PA11}, 8);
  qtr.setTimeout (1000);

  delay(500);
  pinMode(PC13, OUTPUT);
  pinMode(ME1, OUTPUT);
  pinMode(ME2, OUTPUT);
  pinMode(MD1, OUTPUT);
  pinMode(MD2, OUTPUT);
  pinMode(MEsinal, OUTPUT);
  pinMode(MDsinal, OUTPUT);
  digitalWrite(PC13, LOW); // turn on Arduino's LED to indicate we are in calibration mode

  // 2.5 ms RC read timeout (default) * 10 reads per calibrate() call
  // = ~25 ms per calibrate() call.
  // Call calibrate() 400 times to make calibration take about 10 seconds.
  for (uint16_t i = 0; i < 1500; i++)
  {
    qtr.calibrate();
  }
  digitalWrite(PC13, HIGH); // turn off Arduino's LED to indicate we are through with calibration

  // print the calibration minimum values measured when emitters were on
  /*Serial.begin(9600);
    for (uint8_t i = 0; i < SensorCount; i++)
    {
    Serial.print(qtr.calibrationOn.maximum[i]);
    Serial.print(' ');
    }
    Serial.println();
    Serial.println();
    delay(1000);*/

}

void loop()
{
//  delay(10);
  // read calibrated sensor values and obtain a measure of the line position
  // from 0 to 5000 (for a white line, use readLineWhite() instead)
  int16_t position = qtr.readLineBlack(sensorValues);
  int soma = 0;
  for (int i = 0; i < SensorCount; i++)
  {
    soma += sensorValues[i];
  }

//  if (soma / SensorCount < 100)
//    position = ValorBase;
  erro = (ValorBase - position);
  sinal = pid(40, 0, 28000, erro);
  setSpeed(10, sinal);
  confere_chegada();
}
