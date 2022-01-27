#include <iostream>

extern "C" {
#include "./lib/rawdraw_sf.h"
}

#include "./util/color.h"
#include "./camera.h"
#include "./triangle.h"
#include "./solid.h"
#include "./vec3.h"
#include "./binary_reader.h"
#include "./scene.h"
#include "./renderer.h"

#define PI M_PI

void HandleKey( int keycode, int bDown ) { }
void HandleButton( int x, int y, int button, int bDown ) { }
void HandleMotion( int x, int y, int mask ) { }
void HandleDestroy() { }

int main()
{
	cout << "... Starting ..." << endl;

	Camera cam1(v(0, 0, -2), v(0, 0, 0));
	Light light1(v(-1, 0, 0));
	Scene scene1(&cam1);

	CNFGSetup( "Example App", 1024, 768 );
	Renderer renderer1("C++ 3D Engine v0.1", 1024, 768);

	Solid solid1(
		v(0, 0, 0),
		v(0, 0, 0),
		readFile("assets/cube.bin.stl")
	);

	solid1.move(v(0, 0, 2));
	scene1.addSolid(solid1, "my-cube");

	scene1.addLight(light1);
	
	while(1)
	{
				
	}
}
