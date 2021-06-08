/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\fryeac                                           */
/*    Created:      Wed May 26 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    1, 10           
// Arm                  motor         2               
// Claw                 motor         3               
// Forks                motor_group   4, 5            
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "Measurements.cpp"

using namespace vex;

void roboConfigs(){
  Arm.setStopping(brake);
  Claw.setStopping(brake);
  Drivetrain.setStopping(brake);
  Forks.setStopping(brake);
  Drivetrain.setDriveVelocity(100,percent);
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  roboConfigs();

  measuredMoves obj;

  obj.open();
  wait(10, seconds);
  obj.closeOnRing();
  //auton();
}


