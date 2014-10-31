#include "button.h"
#include "math.h"


Button b = Button();

void setup() {
    b.begin();
    Serial.begin(9600);
}

void loop() {
    b.ledsOff();
    
    tiltOmeter();
    
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
 
void tiltOmeter(){
    int xval = b.readX();
    int yval = b.readY();
    if(xval < 8 && yval < 8){}
    else {
        float rads = atan2(xval,yval);
        int ledPos = abs(rads/(M_PI/12)) + 1;
        if(ledPos == 0 || ledPos > 12){
            ledPos = 12;
        }
        
        Serial.println(ledPos);
        b.ledOn(ledPos, 0, 30, 30);
        
    }
}


