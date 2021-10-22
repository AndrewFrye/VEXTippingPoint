#include <Auto.h>

Auto::Auto(motor_group Forks, float ForksGearRatio)
{
    forks = Forks;
    forksGearRatio = ForksGearRatio;
}

void Auto::forkLift(float angle, bool direction)
{
    //Determines if the forks should be moving up or down
    if (direction)
    {
        forks.spinTo(angle * forksGearRatio, degrees, true);
    }
    else if (!direction)
    {
        forks.spinTo(angle * forksGearRatio * -1, degrees, true);
    }
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

    Drivetrain.turnFor(90, degrees, true);
    Drivetrain.driveFor(-10, inches, true);
    forkLift(135, true);
    Drivetrain.driveFor(20, inches, true);
}