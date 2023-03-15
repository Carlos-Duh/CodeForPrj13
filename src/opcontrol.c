/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"

/*
 * Runs the user operator control code. This function will be started in its own task with the
 * default priority and stack size whenever the robot is enabled via the Field Management System
 * or the VEX Competition Switch in the operator control mode. If the robot is disabled or
 * communications is lost, the operator control task will be stopped by the kernel. Re-enabling
 * the robot will restart the task, not resume it from where it left off.
 *
 * If no VEX Competition Switch or Field Management system is plugged in, the VEX Cortex will
 * run the operator control task. Be warned that this will also occur if the VEX Cortex is
 * tethered directly to a computer via the USB A to A cable without any VEX Joystick attached.
 *
 * Code running in this task can take almost any action, as the VEX Joystick is available and
 * the scheduler is operational. However, proper use of delay() or taskDelayUntil() is highly
 * recommended to give other tasks (including system tasks such as updating LCDs) time to run.
 *
 * This task should never exit; it should end with some kind of infinite loop, even if empty.
 */
//int power, turn;
void operatorControl() {
Ultrasonic leftSonar;
Ultrasonic rightSonar;
Ultrasonic midSonar;
leftSonar = ultrasonicInit(3, 4);
rightSonar = ultrasonicInit(1, 2); //two for when there is an imbalance it will be able to turn
midSonar = ultrasonicInit(5, 6);
int distanceToObjectLeft;
int distanceToObjectRight;
int distanceToObjectMid;
//distanceToObjectLeft = ultrasonicGet(leftSonar);
//distanceToObjectRight = ultrasonicGet(rightSonar);
//distanceToObjectMid = ultrasonicGet(midSonar);

printf("code start");
int power, turn;
    while (1)
    {
        //front left is 5, back left is 6, front right is 4, back right is 3, omni wheel is 2
        power = 0;
        turn = 0;

        distanceToObjectLeft = (ultrasonicGet(leftSonar));
        distanceToObjectRight = (ultrasonicGet(rightSonar));
        distanceToObjectMid = (ultrasonicGet(midSonar));
        printf("leftsonar %d ",ultrasonicGet(leftSonar));
        printf("middlesonar %d ",ultrasonicGet(midSonar));
        printf("rightsonar %d \n",ultrasonicGet(rightSonar));

        //printf("the distance to object left is %d", (distanceToObjectLeft + 2));
        //printf("the distnace to object right is %d", (distanceToObjectRight + 2));
        //printf("the distnace to object mid is %d", (distanceToObjectMid+2));
        if (10 < distanceToObjectMid < 20) { //move towards
            power = -30;
            motorSet(3, power); //makes back right wheel go forward
            motorSet(4, power); //makes front right wheel go forward
            motorSet(5, power); //makes front left wheel go forward
            motorSet(6, power); //makes back left wheel go forward
        }
        if (10 > distanceToObjectMid) { //back away
            power = 30;
            motorSet(3, power);
            motorSet(4, power);
            motorSet(5, power);
            motorSet(6, power);
        }
        if (abs(distanceToObjectLeft - distanceToObjectRight) < 0.5) {
            power = 30;
            motorSet(3, power);
            motorSet(4, power);
            motorSet(5, power);
            motorSet(6, power);
        }
        else if (distanceToObjectLeft < distanceToObjectRight) { //turn right
            power = -30;
            motorSet(2, power);
            motorSet(3, power / 2);
            motorSet(4, power / 2);
            motorSet(5, power);
            motorSet(6, power);
        }
        else if (distanceToObjectLeft > distanceToObjectRight) { //turn left
            power = 30;
            motorSet(2, power);
            motorSet(3, power);
            motorSet(4, power);
            motorSet(5, power / 2);
            motorSet(6, power / 2);
        }
        delay(40);
    }
    // after the while loop, not doing anything
    //
    /*delay(200);

	/*while (1) {
		power = joystickGetAnalog(1,2); //vertical axis on left joystick
		turn = joystickGetAnalog(1,4); //horizontal axis on left joystick
		motorSet(2, -turn); //makes the omni wheel spin the right way when turning left and right
		motorSet(3, power + turn); //set left wheel
		motorSet(4, power + turn); //set left wheel
		motorSet(5, power - turn); //set right wheel
		motorSet(6, power - turn); //set right wheel
		delay(20);	
	}*/
	/*
	read the ultra soinc sensor
	print value to the terminal
	if (ultrasonic is > target follow distance) {
		drive forward
	}
	else if (ultrasonic is < target follow distance){
		back up
	}
	else {
		stop
	}
	*/
	
}
