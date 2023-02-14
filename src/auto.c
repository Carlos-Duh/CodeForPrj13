/** @file auto.c
 * @brief File for autonomous code
 *
 * This file should contain the user autonomous() function and any functions related to it.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"

/*
 * Runs the user autonomous code. This function will be started in its own task with the default
 * priority and stack size whenever the robot is enabled via the Field Management System or the
 * VEX Competition Switch in the autonomous mode. If the robot is disabled or communications is
 * lost, the autonomous task will be stopped by the kernel. Re-enabling the robot will restart
 * the task, not re-start it from where it left off.
 *
 * Code running in the autonomous task cannot access information from the VEX Joystick. However,
 * the autonomous function can be invoked from another task if a VEX Competition Switch is not
 * available, and it can access joystick information if called in this way.
 *
 * The autonomous task may exit, unlike operatorControl() which should never exit. If it does
 * so, the robot will await a switch to another mode or disable/enable cycle.
 */
    double distanceToObjectLeft;
    double distanceToObjectRight;
    double distnaceToObjectMid;
    Ultrasonic leftSonar;
    Ultrasonic rightSonar;
    Ultrasonic midSonar;
    leftSonar = ultrasonicInit(3, 4); 
    rightSonar = ultrasonicInit(1, 2); //two for when there is an imbalance it will be able to turn
    midSonar = ultraSonicInit(5, 6);
    distanceToObjectLeft = (leftSonar);
    distanceToObjectRight = (rightSonar);
    distanceToObjectMid = (midSonar);
    void autonomous() {
    int power, turn;
    while (1) 
    {
        power = 0;
        turn = 0;
        distanceToObjectLeft = (ultrasonicGet(leftSonar));
        distanceToObjectRight = (ultrasonicGet(rightSonar));
        distanceToObjectMid = (ultrasonicGet(midSonar));
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
            power = 20;
            motorSet(2, power);
            motorSet(3, power + turn);
            motorSet(4, power + turn);
        }
        else if (distanceToObjectLeft > distanceToObjectRight) { //turn left
            power = -20;
            motorSet(2, power);
            motorSet(5, power - turn);
            motorSet(6, power - turn);
        }
        wait(50);
    }
    delay(50);
}