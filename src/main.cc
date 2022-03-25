#define CNFG_IMPLEMENTATION

#include <iostream>

#include "./util/color.h"
#include "./camera.h"
#include "./triangle.h"
#include "./solid.h"
#include "./vec3.h"
#include "./binary_reader.h"
#include "./scene.h"
#include "./renderer.h"

#define PI M_PI

void HandleButton( int x, int y, int button, int bDown ) { }
void HandleMotion( int x, int y, int mask ) { }
void HandleDestroy() { }

void HandleKey( int keycode, int bDown ) {
	if (keycode == 65307) {
		std::cout << "... Stopping ..." << std::endl;
		std::exit(0);
	}
}

int main()
{
	std::cout << "... Starting ..." << std::endl;

	Camera cam1(v(0, 0, -2), v(0, 0, 0));
	Light light1(v(-1, 0, 0));
	Scene scene1(&cam1);

	// CNFGSetup( "Example App", 1024, 768 );
	Renderer renderer1("C++ 3D Engine v0.1", 1024, 768);

	Solid solid1(
		v(0, 0, 0),
		v(0, 0, 0),
		readFile("assets/torus.bin.stl")
	);

	solid1.move(v(0, 0, 2));
	// solid1.rotate(v(0, 0, 2));
	scene1.addSolid(solid1, "my-cube");
	scene1.addLight(light1);
	renderer1.setScene(scene1);

	float a = 0;

	// Vec3 x = v(1, 0, 0);
	// x.print();
	// x.rotate(v(0, 1, 0));
	// x.print();

	Vec3 angle(0, 0, 0);

	while(1) {
		angle.y += 0.04;
		// std::cout << "Frame" << std::endl;
		// std::cout << a << std::endl;
		solid1.rotate(&angle);
		// solid1.print();
		renderer1.render();
	}
}