#include <vex.h>

using namespace vex;

motor_group forks;

float forksGearRatio;

class Auto{
    public:
        Auto(motor_group Forks, float forksGearRatio);
        void forkLift (float angle, bool direction);
        void autoMain ();
};