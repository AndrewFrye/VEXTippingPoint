#include "vex.h"

using namespace vex;

class measurements{
  public:
    int claw = 180;
    int clawRing = 45;
};

class measuredMoves{
  measurements obj;

  public:
    void close(){
      Claw.spinFor(forward, obj.claw, degrees);
    }

    void open(){
      Claw.spinFor(reverse, obj.claw, degrees);
    }

    void closeOnRing(){
      Claw.spinFor(forward, obj.clawRing, degrees);
    }
};