#define CNFG_IMPLEMENTATION

extern "C" {
#include "./lib/rawdraw_sf.h"
}

#include <iostream>

#include "./util/color.h"
#include "./camera.h"
#include "./triangle.h"
#include "./solid.h"
#include "./vec3.h"
#include "./binary_reader.h"
#include "./scene.h"

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
	Scene scene1(cam1);

	Solid solid1(
		v(0, 0, 0),
		v(0, 0, 0),
		readFile("assets/cube.bin.stl")
	);

	solid1.move(v(0, 0, 2));
	scene1.addSolid(solid1, "my-cube");

	scene1.addLight(light1);

	CNFGSetup( "Example App", 1024, 768 );
	while(1)
	{
		CNFGBGColor = 0x000080ff; //Dark Blue Background

		short w, h;
		CNFGClearFrame();
		CNFGHandleInput();
		CNFGGetDimensions( &w, &h );

		CNFGColor(b(255)); 

		//Draw a triangle
		RDPoint points[3] = { { 30, 36}, {20, 50}, { 40, 50 } };
		CNFGTackPoly( points, 3 );

		//Display the image and wait for time to display next frame.
		CNFGSwapBuffers();		
	}
}
