#define CNFG_IMPLEMENTATION

extern "C" {
#include "./lib/rawdraw_sf.h"
}

#include "./triangle.h"
#include "./scene.h"

class Renderer {
public:
  Scene scene;

  Renderer(const char* windowName, int width, int height) {
    // CNFGSetup(windowName, width, height);
  }

  void setScene(Scene _scene) {
    scene = _scene;
  }

  void render() {
    CNFGBGColor = 0x000080ff;

		CNFGClearFrame();
		CNFGHandleInput();

		CNFGColor(b(255));	

    for (Solid solid : scene.solids) {
      solid.computeAdjusted();

      // for (Triangle triangle : solid.triangles) {
      //   triangle.depth = 
      // }

      for (Triangle tri : solid.triangles) {
        tri.project();

    		RDPoint points[3] = {
          { tri.projected[0].x, tri.projected[0].y },
          { tri.projected[1].x, tri.projected[1].y },
          { tri.projected[2].x, tri.projected[2].y },
        };

		    // CNFGTackPoly( points, 3 );	
		    CNFGTackPoly( points, 3 );	
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
