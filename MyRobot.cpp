/*
 * Team 9 Final Project Code
 * RBE 1001 D'19
 * Vignesh Kadarabad, Dawson Scheid, Mike Viozzi
 */

// ************ Libraries ************ //
#include <MyRobot.h>
#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Servo.h>

// ************ Servos & LCD ************ //

Servo lMotor;
Servo rMotor;
Servo liftr;
Servo grabr;

//LiquidCrystal lcd(                                  // *** FIGURE OUT WHICH PORTS TO CONNECT THE LCD TO *** //

// ************ Pins & Ports ************ //

// Drive Motor Pins
const int lMotorPort = 4;     // Left Motor, S4
const int rMotorPort = 8;     // Right Motor, S8

// Lifter/Grabber Pins
const int liftMotor = 10;
const int grabMotor = 11;

// Sensor Input Pins
const int potPin =        // 4-Bar Potentiometer (P-Control)
const int LO_photo = 26;   // Left Outside photocell, D26
const int LI_photo = 27;   // Left Inside -- , D27
const int RO_photo = 28;   // Right Outside -- , D28
const int RI_photo = 29;   // Right Inside -- , D29

// Red/Blue Checker
const int red_Blu = 22;

// Enumerates states for autonomous program
enum autoStates {
  LINETRACK,        // Tracks white line
  TURN,             // Turns 90 deg one direction (depends on team)
  UP_n_TRACK,       // Moves arm into position while also tracking the second guidance line.
  HALT,             // Stops on bump switch press
  DELIVER,          // Delivers Pizza to dorm
  BEGONE            // Stops the program and prevents anything else from happening. Autonomous end state
} state;




// ************ Custom Functions ************ //
  // Used in autonomous and teleoperated modes, but are not the autonomous code itself







// ************ "MyRobot" Code ************ //
  // Included in DFW template, the robot actually runs all this stuff

/**
 * Called when the start button is pressed and the robot control begins
 */
 void MyRobot::robotStartup(){
		Serial.println("Startup begun...");
    
    // Sets up Liquid Crystal Display
    //lcd.begin(16,2)                      

    // Setup Servos
    lMotor.attach(lMotorPort,1000,2000);
    rMotor.attach(rMotorPort,1000,2000);
    liftr.attach(liftMotor,1000,2000);
    grabr.attach(grabMotor,1000,2000);

    // Setup Photocell Pins
    pinMode(LO_photo, INPUT);
    pinMode(LI_photo, INPUT);
    pinMode(RO_photo, INPUT);
    pinMode(RI_photo, INPUT);

    // Setup Potentiometer Pin
    pinMode(potPin, INPUT);

    // Setup Red/Blue Checker
    pinMode(red_Blu, INPUT);
    
 }
/**
 * Called by the controller between communication with the wireless controller
 * during autonomous mode
 * @param time the amount of time remaining
 * @param dfw instance of the DFW controller
 */
 void MyRobot::autonomous(long time){
  Serial.print("\r\nAuto time remaining: ");
	Serial.print(time);
 
  switch (state){
    case LINETRACK:
      lineTrack;
    
  }
   
 }
/**
 * Called by the controller between communication with the wireless controller
 * during teleop mode
 * @param time the amount of time remaining
 * @param dfw instance of the DFW controller
 */
 void MyRobot::teleop(long time){
		Serial.print("\r\nTeleop time remaining: ");
		Serial.print(time);
		Serial.print("\tright joystick: ");
		Serial.print(dfw->joystickrv());
		Serial.print("\tleft joystick: ");
		Serial.print(dfw->joysticklv());
		//Run functions in the robot class
 }
/**
 * Called at the end of control to reset the objects for the next start
 */
 void MyRobot::robotShutdown(void){
		Serial.println("Here is where I shut down my robot code");

 }
