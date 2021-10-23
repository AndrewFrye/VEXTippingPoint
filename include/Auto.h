#include <vex.h>

using namespace vex;

class Auto
{
public:
    Auto(motor_group Forks, float forksGearRatio);
    Auto();
    void forkLift(float angle);
    void autoMain();

private:
    motor_group forkGroup;
    float forksGearRatio;
};