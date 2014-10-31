#include "SparkButton/SparkButton.h"
#include "math.h"

/*Here's a nice combination of features that I like to use.
Note the use of the allButtons functions.*/ 

Button b = Button();

void setup() {
    //Tell b to get everything ready to go
    b.begin();
}

void loop(){
    
    
    b.ledsOff();
    if(b.allButtonsOn()) {
        b.rainbow(20);
        b.ledsOff();
    }
    else if(b.allButtonsOff()) {
            
    }
    else{
        if(b.buttonOn(1)){
            b.ledOn(12, 255, 0, 0);
        }
        if(b.buttonOn(2)){
            b.ledOn(3, 0, 255, 0);
        }
        if(b.buttonOn(3)){
            b.ledOn(6, 0, 0, 255);
        }
        if(b.buttonOn(4)){
            b.ledOn(9, 255, 255, 255);
        }
    }
    delay(50);
}