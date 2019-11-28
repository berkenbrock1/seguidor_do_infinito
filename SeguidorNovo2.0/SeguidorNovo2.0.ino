#include <QTRSensors.h>
#include "Defines.h"

QTRSensors qtr;

const uint8_t SensorCount = 8;
uint16_t sensorValues[SensorCount];

void setup()
{
  // configure the sensors
  qtr.setTypeRC();
  qtr.setSensorPins((const uint8_t[]){7, 6, A5, A4, A3, A2,  A1, A0}, SensorCount);
  qtr.setEmitterPin(2);
  qtr.setTimeout (1000);

  delay(500);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(ME, OUTPUT);
  pinMode(MD, OUTPUT);
  pinMode(MEsinal, OUTPUT);
  pinMode(MDsinal, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH); // turn on Arduino's LED to indicate we are in calibration mode

  // 2.5 ms RC read timeout (default) * 10 reads per calibrate() call
  // = ~25 ms per calibrate() call.
  // Call calibrate() 400 times to make calibration take about 10 seconds.
  for (uint16_t i = 0; i < 400; i++)
  {
    qtr.calibrate();
  }
  digitalWrite(LED_BUILTIN, LOW); // turn off Arduino's LED to indicate we are through with calibration

  // print the calibration minimum values measured when emitters were on
  // Serial.begin(9600);
  /*for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(qtr.calibrationOn.minimum[i]);
    Serial.print(' ');
  }
  Serial.println();*/

  // print the calibration maximum values measured when emitters were on
  /*for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(qtr.calibrationOn.maximum[i]);
    Serial.print(' ');
  }
  Serial.println();
  Serial.println();
  delay(1000);*/
  //FastLED.addLeds<LED_TYPE, PINSAIDA, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  //FastLED.setBrightness(BRILHO);
  //Acende cada led individualmente até acender todos os 5. 
  //acendeLed(1000);
  //Efeito de pulsar os leds
  //alteraBrilho();
}

void loop()
{  
  // read calibrated sensor values and obtain a measure of the line position
  // from 0 to 5000 (for a white line, use readLineWhite() instead)
  int16_t position = qtr.readLineBlack(sensorValues);
  int soma = 0;
  for(int i=0;i<SensorCount;i++)
  {
    soma += sensorValues[i];
  }
  
  if(soma/SensorCount < 100)
    position = 3500;
  erro = (3500 - position) / 125  ;
  sinal = pid(150, 0, 10000, erro);
  setSpeed(120, sinal);
  confere_chegada();
}
