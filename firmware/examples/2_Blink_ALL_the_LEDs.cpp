#include "SparkButton/SparkButton.h"

/* This SparkButton library has some useful functions. 
Here we blink ALL the LEDs instead of just one.*/

SparkButton b = SparkButton();

void setup() {
    // Tell b to get everything ready to go
    b.begin();
}

void loop(){
    b.allLedsOn(0,20,20);
    delay(1000);
    b.allLedsOff();
    delay(1000);
    
    // Notice that I made them much dimmer, so it's a bit less painful
}