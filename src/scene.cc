#include "./camera.h"

class Scene {
public:
  Scene(Camera _camera)
  : camera(_camera) {
    this.solids = [];
    this.lights = [];

    this.solidNames = {};
  }

  addSolid(solid, name) {
    const index = this.solids.length;
    this.solidNames[name] = index;
    this.solids.push(solid);
  }

  getSolid(name) {
    const index = this.solidNames[name];
    return this.solids[index];
  }

  addLight(light) {
    this.lights.push(light);
  }
}