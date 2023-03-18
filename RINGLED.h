#ifndef RINGLED_H
#define RINGLED_H

//#include <M5Unified.h>
#include <M5Atom.h>
#include "FastLED.h"
//LED Setting
#define FPS 120

//#define LED_PIN 26 // M5Atom:26
#define LED_PIN 32 //M5Stamp:32

#define NUM_LEDS 32


class RINGLED{
  public:
    RINGLED();
    void setup();
    void flash(int);//color
    void clyon();
    void fire();
    void fire2(int,int);
    void fade();
    void stop();
    void pacifica();
    void setbrightness(int);//brightness

  private:
    bool _isSetuped;
};
#endif