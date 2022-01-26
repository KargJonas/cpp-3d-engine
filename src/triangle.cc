// #include "./vec3.h"

class Triangle {
public:
  Vec3 vertices[3];
  Vec3 normal;
  float depth;

  Triangle(Vec3 _normal, Vec3 v1, Vec3 v2, Vec3 v3)
    : normal(_normal), vertices({ v1, v2, v3 }) {
  }

  // float getDistanceFromCamera(camera) {
  //   return vertices
  //     .reduce((accumulator, vertex) => accumulator.add(vertex), v3())
  //     .div(3)
  //     .dist(camera.position);
  // }
};