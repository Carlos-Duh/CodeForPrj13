#ifndef _FOLLOW_H_
#define _FOLLOW_H_

#include "main.h"
#include "chassis.h"

int distanceToObjectLeft;
int distanceToObjectRight;
int distnaceToObjectMid;
Ultrasonic leftSonar;
Ultrasonic rightSonar;
Ultrasonic midSonar;
leftSonar = ultrasonicInit(3, 4); 
rightSonar = ultrasonicInit(1, 2); //two for when there is an imbalance it will be able to turn
midSonar = ultraSonicInit(5, 6);
distanceToObjectLeft = (0, cm);
distanceToObjectRight = (0, cm);
distanceToObjectMid = (0, cm);
void followSet()
{
    int power, turn;
    while (1) 
    {
        power = 0;
        turn = 0;
        distanceToObjectLeft = (ultrasonicGet(leftSonar),cm);
        distanceToObjectRight = (ultrasonicGet(rightSonar),cm);
        distanceToObjectMid = (ultraSonicGet(midSonar),cm);
        printf("the distance to object is %d", distanceToObjectLeft);
        printf("the distnace to object is %d", distanceToObjectRight);
        printf("the distnace to object is %d", distanceToObjectMid);
        if (10 < midSonar < 20) { //move towards
            power = 20;
            motorSet(3, power + turn); //makes left wheels go forward
            motorSet(4, power + turn); //makes left wheels go forward
            motorSet(5, power - turn); //makes right wheels go forward
            motorSet(6, power - turn); //makes right wheels go forward
        }
        else if (10 > midSonar) { //back away
            power = -20;
            motorSet(3, power + turn);
            motorSet(4, power + turn);
            motorSet(5, power - turn);
            motorSet(6, power - turn);
        }
        if (distanceToObjectLeft < distanceToObjectRight) { //turn right
            power = 20
            motorSet(2, power);
            motorSet(3, power + turn);
            motorSet(4, power + turn);
        }
        else if (distanceToObjectLeft > distanceToObjectRight) { //turn left
            power = -20
            motorSet(2, power);
            motorSet(5, power - turn);
            motorSet(6, power - turn);
        }
        wait(50);
    }
    delay(50);
}