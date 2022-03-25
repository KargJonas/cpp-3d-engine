extern "C" {
#include "./lib/rawdraw_sf.h"
}

#include "./triangle.h"
#include "./scene.h"

class Renderer {
public:
  Scene scene;
  int width, height;

  Renderer(const char* windowName, int _width, int _height)
  : width(_width), height(_height) {
    CNFGSetup(windowName, width, height);
  }

  void setScene(Scene _scene) {
    scene = _scene;
  }

  void render() {
    const int offsetW = 0.5 * width;
    const int offsetH = 0.5 * height;

    CNFGBGColor = 0x000080ff;

		CNFGClearFrame();
		CNFGHandleInput();

    for (Solid solid : scene.solids) {
      solid.computeAdjusted();

      // for (Triangle triangle : solid.triangles) {
      //   triangle.depth = 
      // }

      for (Triangle tri : solid.adjusted) {
        // tri.project();

        // std::cout << tri.vertices[0].toString() << "  \t=>\t" << tri.projected[0].toString() << std::endl;

        RDPoint points[3];

        for (uint8_t i = 0; i < 3; i++) {
          points[i] = {
            // 0.5 * width + tri.projected[i].x * 0.5 * width,
            // 0.5 * height + tri.projected[i].y * 0.5 * height

            0.5 * width + tri.vertices[i].x * 0.5 * width,
            0.5 * height + tri.vertices[i].y * 0.5 * height
          };
        }

        // std::cout << tri.vertices[0].x << std::endl;

		    CNFGColor(b(tri.normal.dot(scene.camera->direction) * 255));	
  	    CNFGTackPoly( points, 3 );

        CNFGColor(rgb(255, 0, 0));
        for (short i = 0; i < 3; i++) {
          int next = (i + 1) % 3;
          
          CNFGTackSegment(
            points[i].x,
            points[i].y,
            points[next].x,
            points[next].y
          );
        }
      }
    }

    CNFGSwapBuffers();

    // for (const solid of adjustedSolids) {
    //   for (const triangle of solid.triangles) {
    //     const depth = triangle.getDistanceFromCamera(camera);
    //     triangle.depth = depth;
    //   }

    //   solid.triangles = solid.triangles.sort((a, b) => b.depth - a.depth);
    // }

    // for (const solid of adjustedSolids) {
    //   for (const triangle of solid.triangles) {
    //     const vertices = triangle.vertices
    //       .map(vertex => vertex.projectZ());

    //     const firstVertex = vertices[0];
    //     // const dist = t(...vertices).getDistanceFromCamera(camera);

    //     const specular = Math.pow(lights[0].direction.add(triangle.normal).unit().dot(camera.direction), 2) * 0.8;

    //     // const specular = 0;
    //     // let brightness = specular;
    //     const light = triangle.normal.dot(lights[0].direction);
    //     let brightness = (light + specular) * 255;

    //     ctx.beginPath();
    //     ctx.moveTo(firstVertex.x, firstVertex.y);

    //     for (const vertex of vertices) {
    //       ctx.lineTo(vertex.x, vertex.y);
    //     }

    //     // ctx.closePath();
    //     ctx.strokeStyle = 'rgba(0, 0, 0, 0)';
    //     ctx.fillStyle = `rgb(${brightness},${brightness},${brightness})`;
    //     ctx.fill();

    //     // ctx.stroke();
    //   }
    // }
  }
};
