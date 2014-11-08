#include "SparkButton/SparkButton.h"
#include "math.h"

/* Did you know that the SparkButton can detect if it's moving? It's true! 
Specifically it can read when it's being accelerated. Recall that gravity 
is a constant acceleration and this becomes very useful- you know the orientation!*/ 
    

SparkButton b = SparkButton();

void setup() {
    // Tell b to get everything ready to go
    b.begin();
}

void loop(){
    
    // How much are you moving in the x direction? (look at the white text on the board)
    int xValue = b.readX();
    
    // How about in the y direction?
    int yValue = b.readY();

    // If we're close to level, light all LEDs green
    if(abs(xValue)<2 and abs(yValue)<2) {
        b.allLedsOn(0,255,0);
        delay(100);
        return;
    }
    
    // Now we'll do some trig to figure out which LED that direction maps to
    float rads = atan2(yValue,xValue);
    int ledPos = (int)(12 - (rads/(M_PI/6) - 3)) % 12;
    
    // Turn all LEDs off before turning one on
    b.allLedsOff();
    // Now turn that LED on
    b.ledOn(ledPos, 0, 30, 30);
    
    // Wait a mo'
    delay(100);
}
