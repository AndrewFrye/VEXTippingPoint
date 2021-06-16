#include "vex.h"

using namespace vex;

// Measurements used in the measured moves class
class measurements {
public:
  int claw = 180;
  int clawRing = 90;
};

// Measured Movements for Clawbot and Tipping Point Game
class measuredMoves {
  measurements obj;

public:
  // Close the claw From the open position
  void close() { Claw.spinFor(forward, obj.claw, degrees); }

  // Open the claw from the closed position
  int open() {
    Claw.spinFor(reverse, obj.claw, degrees);
    return 0;
  }

  // Closes the claw from open onto a ring
  void closeOnRing() { Claw.spinFor(forward, obj.clawRing, degrees); }
};

// Simple movement commands to streamline development
class moveFunctions {

private:
  drivetrain train = Drivetrain;

  
public:
  moveFunctions(drivetrain dtrain) { train = dtrain; }

  // Drives in a given direction until a condition is met
  void driveUntil(bool x, bool target, directionType dir) {
    train.drive(dir);
    waitUntil(x == target);
    train.stop();
  }

  // Float override of previous function
  void driveUntil(float x, float target, directionType dir) {
    train.drive(dir);
    waitUntil(x == target);
    train.stop();
  }

  // Integer override of previous function
  void driveUntil(int x, int target, directionType dir) {
    train.drive(dir);
    waitUntil(x == target);
    train.stop();
  }

  // Double override of previous function
  void driveUntil(double x, double target, directionType dir) {
    train.drive(dir);
    waitUntil(x == target);
    train.stop();
  }

  
};
int callback(){return 0;}
thread (callback);