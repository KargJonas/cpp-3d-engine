#include "./vec3.h"

class Light {
public:
  Vec3 direction;

  Light(Vec3 _direction)
  : direction(_direction) { }
};
