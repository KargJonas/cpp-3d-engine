#include <vector>
#include <string>
#include <map>
#include "./camera.h"
#include "./solid.h"
#include "./directional_light.h"

class Scene {
public:
  Camera *camera;
  vector<Solid> solids;
  vector<Light> lights;
  map<string, int> solidNames;

  Scene(Camera *_camera)
  : camera(_camera) { }

  Scene() { }

  void addSolid(Solid _solid, string name) {
    uint index = solids.size();
    solidNames[name] = index;

    solids.push_back(_solid);
  }

  void addLight(Light light) {
    lights.push_back(light);
  }

  void setCamera(Camera *_camera) {
    camera = _camera;
  }

  // Should return reference, not value
  Solid getSolid(string name) {
    uint index = solidNames[name];
    return solids[index];
  }
};
