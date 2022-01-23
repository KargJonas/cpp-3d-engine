#include "./vector.h"
#include "fmt/format.h"
#include <iostream>

class Camera {
public:
  Vector position;
  Vector rotation;
  Vector direction;

  Camera(Vector _position, Vector _rotation)
    : position(_position), rotation(_rotation), direction(Vector(0, 0, 0)) {
  }

  void aimTowards(Vector point) {

  }

  string toString() {
    return fmt::format("Camera (\n  Position: {}\n  Rotation: {}\n)", position.toString(), rotation.toString());
  }

  void print() {
    cout << toString() << endl;
  }
};
