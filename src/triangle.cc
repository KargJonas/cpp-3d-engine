// #include "./vector.h"

class Triangle {
public:
  Vector vertices[3];
  Vector normal;
  float depth;

  Triangle(Vector _normal, Vector v1, Vector v2, Vector v3)
    : normal(_normal), vertices({ v1, v2, v3 }) {
  }

  // float getDistanceFromCamera(camera) {
  //   return vertices
  //     .reduce((accumulator, vertex) => accumulator.add(vertex), v3())
  //     .div(3)
  //     .dist(camera.position);
  // }
};