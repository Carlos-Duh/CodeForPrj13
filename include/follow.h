#ifndef _FOLLOW_H_
#define _FOLLOW_H_

#include "main.h"
#include "chassis.h"

int distanceToObject;
Ultrasonic leftSonar;
Ultrasonic rightSonar
leftSonar = ultrasonicInit(1, 2); 
rightSonar = ultrasonicInit(3,4); //two for when there is an imbalance it will be able to turn
void followSet()
{
    int power, turn;
    while (1) 
    {
        distanceToObjectLeft = ultrasonicGet(leftSonar);
        distanceToObjectRight = ultrasonicGet(rightSonar);
        printf("the distance to object is %d", distanceToObjectLeft);
        printf("the distnace to object is %d", distnaceToObjectRight);
        motorSet(3, power + turn); //makes left wheels go forward
        motorSet(4, power + turn); //makes left wheels go forward
        motorSet(5, power - turn); //makes right wheels go forward
        motorSet(6, power - turn); //makes right wheels go forward
        if (10 < leftSonar < 20 || 10 < rightSonar < 20) { //move towards
            power = 20;
        }
        else if (10 > leftSonar || 10 > rightSonar) { //back away
            power = -20;
        }
        if (distanceToObjectLeft < distanceToObjectRight) { //turn right
            power = 20
            motorSet(2, power);
        }
        else if (distanceToObjectLeft > distanceToObjectRight) { //turn left
            motorSet(2, power);
            power = -20
        }
        
    }
    delay(50);
}