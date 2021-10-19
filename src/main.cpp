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

#include "Measurements.h"
#include "vex.h"
#include <thread>

using namespace vex;

// robot motor and sensor settings
void roboConfigs() {
  Arm.setStopping(brake);
  Claw.setStopping(brake);
  Drivetrain.setStopping(brake);
  Forks.setStopping(brake);
  Drivetrain.setDriveVelocity(100, percent);
}

void moveThreadFactory(void *moveCmd) {
  measuredMoves calcMoves;

  int *intPtr{static_cast<int *>(moveCmd)};

  switch ((int)*intPtr) {
  case 1:
    calcMoves.open();
    break;
  case 2:
    calcMoves.close();
    break;
  case 3:
    Arm.spinFor(reverse, 360, degrees);
    break;
  case 4:
    Arm.spinFor(forward, 360, degrees);
    break;
  }
}

int main() {

  // initialize the robot
  vexcodeInit();
  roboConfigs();

  // Define classes to be used
  measuredMoves calcMoves;
  moveFunctions simpMoves(Drivetrain);

  int x = 1;
  void *a = &x;
  while(1)
  {vex::thread t1(moveThreadFactory, a);
  
  wait(500, msec);
  x=3;
  vex::thread t3(moveThreadFactory, a);
  t3.detach();

  t3.join();
  t1.join();

  x = 2;
  vex::thread t2(moveThreadFactory, a);
  
  x=4;
  vex::thread t4(moveThreadFactory, a);
  t4.join();
  t2.join();

  Drivetrain.driveFor(forward, 200, mm);
  Drivetrain.turnFor(left, 90, degrees);
  }
}
