#include <Auto.h>

Auto::Auto(motor_group Forks, float ForksGearRatio)
{
  forkGroup = Forks;
  forksGearRatio = ForksGearRatio;
}

void Auto::forkLift(float angle)
{
  forkGroup.spinFor(fwd, angle * forksGearRatio, deg);
}
void Auto::autoMain()
{
  /*
    Start on the side of the see-saw that has a tower on it
    Turn 90 Degrees to the right
    back up a bit
    Lay down the forks
    move forwards
    lift the forks just a bit
    drive up the ramp
    go enough to set the base towards the other end of the ramp
    set it down
    back up
    */

<<<<<<< HEAD
    Drivetrain.turnFor(90, degrees, true);
    Drivetrain.driveFor(-10, inches, true);
    forkLift(135, true);
    Drivetrain.driveFor(20, inches, true); 
=======
  Drivetrain.turnFor(70, deg, true);
  Drivetrain.driveFor(-10, inches, true);
  forkLift(-150);
  Drivetrain.driveFor(10, inches, true);
  forkLift(50);
  Drivetrain.driveFor(30, inches, true);
  forkLift(-50);
  Drivetrain.driveFor(-20, inches, true);
>>>>>>> 300f5fedfc359ab224f1363b60ff19c44403e33b
}