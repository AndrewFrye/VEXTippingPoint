/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Andrew Frye                                               */
/*    Created:      Tuesday June 8, 2021                                      */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"

using namespace vex;

// robot motor and sensor settings
void roboConfigs()
{
  Arm.setStopping(brake);
  Claw.setStopping(brake);
  Drivetrain.setStopping(brake);
  Forks.setStopping(brake);
  Drivetrain.setDriveVelocity(100, percent);
}

competition Competition;

void pre_auton(void)
{
  vexcodeInit();
  roboConfigs();
}

void autonomous(void)
{
}

void usercontrol(void)
{
  while (1)
  {
    wait(20, msec);
  }
}

int main()
{

  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  //stop all tasks between sections
  Competition.bStopAllTasksBetweenModes = true;

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true)
  {
    wait(100, msec);
  }
}
