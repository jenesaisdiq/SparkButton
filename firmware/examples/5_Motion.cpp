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
    
    //And the z!
    int zValue = b.readZ();

    //This will make the color of the Button change with what direction you shake it
    allLedsOn(xValue, yValue, zValue);
    
    //Wait a mo'
    delay(100);
    
    //Turn the LEDs off so they don't all end up on
    b.allLedsOff();
}