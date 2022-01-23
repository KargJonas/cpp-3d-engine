#include "./triangle.h"
#include "./vector.h"
#include <vector>

class Solid {
public:
  Vector position;
  Vector rotation;
  Triangle triangles[];

  Solid(Vector _position, Vector _rotation, Triangle* _triangles)
  : position(_position), rotation(_rotation), triangles(_triangles) {
    
  }
};
