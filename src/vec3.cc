#define FMT_HEADER_ONLY
#include "fmt/format.h"
#include <iostream>

using namespace std;

class Vec3 {
public:
  float x;
  float y;
  float z;

  Vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) { }
  Vec3() : x(0), y(0), z(0) { }

  // ~Vec3() {
  //   delete x;
  //   delete y;
  //   delete z;
  // }

  string toString() {
    return fmt::format("Vec3 ( {}, {}, {} )", x, y, z);
  }

  void print() {
    cout << toString() << endl;
  }

  Vec3 clone() {
    return Vec3(x, y, z);
  }

  Vec3 mul(float factor) {
    x *= factor;
    y *= factor;
    z *= factor;

    return *this;
  }

  Vec3 div(float factor) {
    x /= factor;
    y /= factor;
    z /= factor;

    return *this;
  }

  float mag() {
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
  }

  Vec3 unit() {
    return div(mag());
  }

  Vec3 scale(float length) {
    return unit().mul(length);
  }

  Vec3 add(Vec3 other) {
    x += other.x;
    y += other.y;
    z += other.z;

    return *this;
  }

  Vec3 sub(Vec3 other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;

    return *this;
  }

  float dist(Vec3 other) {
    return clone().sub(other).mag();
  }

  float dot(Vec3 other) {
    return x * other.x +
           y * other.y +
           z * other.z;
  }

  // Multiply components individually => results in vector
  Vec3 compMul(Vec3 other) {
    x *= other.x;
    y *= other.y;
    z *= other.z;

    return *this;
  }

  Vec3 cross(Vec3 other) {
    float _x = y * other.z - z * other.y;
    float _y = z * other.x - x * other.z;
    float _z = x * other.y - y * other.x;
    
    x = _x;
    y = _y;
    z = _z;

    return *this;
  }

  Vec3 rotateX(float angle) {
    float sinA = sin(angle);
    float cosA = cos(angle);

    y = y * cosA - z * sinA;
    z = y * sinA + z * cosA;

    return *this;
  }

  Vec3 rotateY(float angle) {
    float sinA = sin(angle);
    float cosA = cos(angle);

    x = x * cosA + z * sinA;
    z = z * cosA - x * sinA;

    return *this;
  }

  Vec3 rotateZ(float angle) {
    float sinA = sin(angle);
    float cosA = cos(angle);

    x = x * cosA - y * sinA;
    y = x * sinA + y * cosA;

    return *this;
  }

  Vec3 rotate(Vec3 angle) {
    return rotateX(angle.x)
      .rotateY(angle.y)
      .rotateZ(angle.z);
  }

  Vec3 rotateAround(Vec3 pivot, Vec3 angle) {
    return sub(pivot)
      .rotate(angle)
      .add(pivot);
  }

  Vec3 projectZ() {
    x /= z;
    y /= z;

    return *this;
  }

  Vec3 abs() {
    x = std::abs(x);
    y = std::abs(y);
    z = std::abs(z);
    
    return *this;
  }
};
