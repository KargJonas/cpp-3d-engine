#include "./triangle.h"
#include "./vec3.h"
#include <vector>

using namespace std;

class Solid {
public:
  Vec3 position;
  Vec3 rotation;
  vector<Triangle> triangles;
  uint triangleCount;

  Solid(Vec3 _position, Vec3 _rotation, vector<Triangle> _triangles)
  : position(_position), rotation(_rotation), triangles(_triangles) {
  }

  void move(Vec3 _position) {
    position = _position;
  }

  void rotate(Vec3 _rotation) {
    rotation = _rotation;
  }

  Solid computeAdjusted() {
    // int triangleCount = triangles.size();
    // Solid adjustedTriangles[triangleCount];

    for_each(triangles.begin(), triangles.end()) {
    } // !!

    return *this;
  }
};
