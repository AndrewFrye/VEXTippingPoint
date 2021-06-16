/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Andrew Frye                                               */
/*    Created:      Tuesday June 8, 2021                                      */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller
// Drivetrain           drivetrain    1, 10
// Arm                  motor         8
// Claw                 motor         3
// Forks                motor_group   4, 5
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "Measurements.cpp"
#include "vex.h"

using namespace vex;

//robot motor and sensor settings
void roboConfigs() {
  Arm.setStopping(brake);
  Claw.setStopping(brake);
  Drivetrain.setStopping(brake);
  Forks.setStopping(brake);
  Drivetrain.setDriveVelocity(100, percent);
}

int main() {

  // initialize the robot
  vexcodeInit();
  roboConfigs();

  // Define classes to be used
  measuredMoves calcMoves;
  moveFunctions simpMoves(Drivetrain);
}
