#include "SparkButton/SparkButton.h"
#include "math.h"

/*Did you know that the SparkButton can detect if it's moving? It's true! 
Specifically it can read when it's being accelerated. Recall that gravity 
is a constant acceleration and this becomes very useful- you know the orientation!*/ 
    

SparkButton b = SparkButton();

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
    //The abs() part takes the absolute value, because negatives don't work well
    b.allLedsOn(abs(xValue), abs(yValue), abs(zValue));
    
    //Wait a mo'
    delay(50);
}