#include "SparkButton/SparkButton.h"
#include "math.h"

/*Did you know that the SparkButton can detect if it's moving? It's true! 
Specifically it can read when it's being accelerated. Recall that gravity 
is a constant acceleration and this becomes very useful- you know the orientation!*/ 
    

Button b = Button();

void setup() {
    //Tell b to get everything ready to go
    b.begin();
}

void loop(){
    
    //How much are you moving in the x direction? (look at the white text on the board)
    int xValue = b.readX();
    
    //How about in the y direction?
    int yValue = b.readY();
    
    //Now we'll do some trig to figure out which LED that direction maps to
    //... ok, it doesn't work well yet. Need to go back to the napkin.
    float rads = atan2(yValue,xValue);
    int ledPos = 12 - abs(rads/(M_PI/6) + 6);
    
    //Now turn that LED on
    b.ledOn(ledPos, 0, 30, 30);
    
    //Wait a mo'
    delay(100);
    
    //Turn the LEDs off so they don't all end up on
    b.allLedsOff();
}