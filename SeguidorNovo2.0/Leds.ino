/*#include <Arduino.h>
#include <FastLED.h>
#define PINSAIDA A6
#define NUM_LEDS 5
#define BRILHO 150
#define LED_TYPE WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100
byte comecou = false;
int temporizador;

CRGBPalette16 currentPalette;
TBlendType currentBlending;
extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePallete_p PROGMEM;


/**
 * Função que acende os leds de acordo com as cores da manopla
 * tempo por padrão: 1000 ms.
 
void acendeLed(int tempo)
{
  int T0, T1, b;
  T0 = 0;
  T1 = 0;
  b = 0;
  while (b <= 4)
  {
    T0 = millis();
    if (T0 - T1 >= tempo && b <= 5)
    {
      if (b == 0)
        leds[0].setRGB(0, 128, 0);
      if (b == 1)
        leds[1].setRGB(255, 20, 147);
      if (b == 2)
        leds[2].setRGB(0, 0, 139);
      if (b == 3)
        leds[3].setRGB(255, 0, 0);
      if (b == 4)
        leds[4].setRGB(255, 255, 0);
      FastLED.show();
      b++;
      T1 = T0;
    }
  }
}
/**
 * função que calsa o efeito de pulsar de acordo com um brilho e um delay mínimo.
 
void pulsarComDelay(int brilho, int tempoDelay){
      FastLED.setBrightness(brilho);
      delay(tempoDelay);
      FastLED.show();

}
/**
 * Função que altera o brilho do led para ficar com efeito de 'pulsar'
void alteraBrilho()
{
  int iterador = 1;
  int brilho = 20;
  while (1)
  {
    if( (iterador < 0 && brilho < 20) || 
    (iterador > 0 && brilho >= 150))
      iterador *= -1;
    brilho += iterador;
    pulsarComDelay(brilho, 5);
  }
}

void geraLuzesAleatorias(){
    for (int i = 0; i < NUM_LEDS; i++) {
    leds[i].setRGB(random(0, 255), random(0, 255), random(0, 255));
    FastLED.show();
    delay(100);
  }
}


void loop()
{
  //geraLuzesAleatorias();
  
}
*/
