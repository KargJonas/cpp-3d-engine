#define FMT_HEADER_ONLY
#include "fmt/format.h"
#include <iostream>

using namespace std;

class Vector {
public:
  float x;
  float y;
  float z;

  Vector(float _x, float _y, float _z) {
    x = _x;
    y = _y;
    z = _z;
  }

  // ~Vector() {
  //   delete x;
  //   delete y;
  //   delete z;
  // }

  string toString() {
    return fmt::format("Vector ( {}, {}, {} )", x, y, z);
  }

  void print() {
    cout << toString() << endl;
  }

  Vector clone() {
    return Vector(x, y, z);
  }

  Vector mul(float factor) {
    x *= factor;
    y *= factor;
    z *= factor;

    return *this;
  }

  Vector div(float factor) {
    x /= factor;
    y /= factor;
    z /= factor;

    return *this;
  }

  float mag() {
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
  }

  Vector unit() {
    return div(mag());
  }

  Vector scale(float length) {
    return unit().mul(length);
  }

  Vector add(Vector other) {
    x += other.x;
    y += other.y;
    z += other.z;

    return *this;
  }

  Vector sub(Vector other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;

    return *this;
  }

  float dist(Vector other) {
    return clone().sub(other).mag();
  }

  float dot(Vector other) {
    return x * other.x +
           y * other.y +
           z * other.z;
  }

  // Multiply components individually => results in vector
  Vector compMul(Vector other) {
    x *= other.x;
    y *= other.y;
    z *= other.z;

    return *this;
  }

  Vector cross(Vector other) {
    float _x = y * other.z - z * other.y;
    float _y = z * other.x - x * other.z;
    float _z = x * other.y - y * other.x;
    
    x = _x;
    y = _y;
    z = _z;

    return *this;
  }

  Vector rotateX(float angle) {
    float sinA = sin(angle);
    float cosA = cos(angle);

    y = y * cosA - z * sinA;
    z = y * sinA + z * cosA;

    return *this;
  }

  Vector rotateY(float angle) {
    float sinA = sin(angle);
    float cosA = cos(angle);

    x = x * cosA + z * sinA;
    z = z * cosA - x * sinA;

    return *this;
  }

  Vector rotateZ(float angle) {
    float sinA = sin(angle);
    float cosA = cos(angle);

    x = x * cosA - y * sinA;
    y = x * sinA + y * cosA;

    return *this;
  }

  Vector rotate(Vector angle) {
    return rotateX(angle.x)
      .rotateY(angle.y)
      .rotateZ(angle.z);
  }

  Vector rotateAround(Vector pivot, Vector angle) {
    return sub(pivot)
      .rotate(angle)
      .add(pivot);
  }

  Vector projectZ() {
    x /= z;
    y /= z;

    return *this;
  }

  Vector abs() {
    x = std::abs(x);
    y = std::abs(y);
    z = std::abs(z);
    
    return *this;
  }
};
