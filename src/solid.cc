#include "./triangle.h"
#include "./vec3.h"
#include <vector>

using namespace std;

class Solid {
public:
  Vec3 position;
  Vec3 rotation;
  vector<Triangle> triangles;
  vector<Triangle> adjusted;
  uint triangleCount;

  Solid(Vec3 _position, Vec3 _rotation, vector<Triangle> _triangles)
  : position(_position), rotation(_rotation), triangles(_triangles) {
    // adjusted = triangles;
  }

  void move(Vec3 _position) {
    position = _position;
  }

  void rotate(Vec3* _rotation) {
    *rotation = _rotation;
  }

  string toString() {
    return fmt::format(
      magenta("Solid") + " (\n  Position: {}\n  Rotation: {}\n)",
      position.toString(),
      rotation.toString()
    );
  }

  void print() {
    cout << toString() << endl << endl;
  }

  void print(string from) {
    string message = fmt::format(
      "{} [{}]",
      toString(),
      red(from)
    );

    cout << message << endl << endl;
  }

  Solid computeAdjusted() {
    rotation.print("computeAdjusted()");

    // Im not sure how efficient this is,
    // might have to change it.
    adjusted = triangles;

    for (Triangle triangle : adjusted) {
      triangle.normal.rotate(rotation);
      
      for (Vec3 vertex : triangle.vertices) {
        vertex.add(position)
          .rotateAround(position, rotation);
      }
    }

    return *this;
  }
};
