#include "SparkButton/SparkButton.h"

/* Let me show you how easy it is to put the Button on the internet.
Useful info, like how to access the data from your browser, can be
found here: http://docs.spark.io/firmware/#spark-variable */ 

SparkButton b = SparkButton();
int xValue = 0;

void setup() {
    // Tell b to get everything ready to go
    b.begin();

    // This makes any integer stored in xValue available online! Done!
    Spark.variable("xValue", &xValue, INT);
}

void loop(){
    // How much are you moving in the x direction?
    xValue = b.readX();
    
    // You could also push those values out exactly when you want using Publish
    // Watch out, though- no more than one publish per second or you'll be rate limited!
    // http://docs.spark.io/firmware/#spark-publish
    // Spark.publish("xValue", String(xValue));

    // Wait a mo'
    delay(100);
}