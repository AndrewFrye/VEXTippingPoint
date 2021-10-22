/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Andrew Frye                                               */
/*    Created:      Tuesday June 8, 2021                                      */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
//#include <Auto.h>

using namespace vex;

//Auto Autonomous(Forks, (5.0 / 3.0));

// robot motor and sensor settings
void roboConfigs()
{
  Arm.setStopping(brake);
  Claw.setStopping(brake);
  CenterDrive.setStopping(brake);
  Drivetrain.setStopping(brake);
  Forks.setStopping(brake);
  Drivetrain.setDriveVelocity(100, percent);
  CenterDrive.setVelocity(100, percent);
}

competition Competition;

void pre_auton(void)
{
  vexcodeInit();
  roboConfigs();
}

void autonomous(void)
{
  //Autonomous.autoMain();
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
