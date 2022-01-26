#include "./vec3.h"
#include "fmt/format.h"
#include <iostream>

class Camera {
public:
  Vec3 position;
  Vec3 rotation;
  Vec3 direction;

  Camera(Vec3 _position, Vec3 _rotation)
    : position(_position), rotation(_rotation), direction(Vec3(0, 0, 0)) {
  }

  void aimTowards(Vec3 point) {

  }

  string toString() {
    return fmt::format("Camera (\n  Position: {}\n  Rotation: {}\n)", position.toString(), rotation.toString());
  }

  void print() {
    cout << toString() << endl;
  }
};
