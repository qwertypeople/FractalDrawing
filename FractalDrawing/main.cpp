#include <iostream>
#include "FractalCreator.h"
using namespace std;
using namespace caveofprogramming;



int main() {

	cout << "Draw fractal"  << endl;


	FractalCreator fractalCreator(2560, 1440);

	fractalCreator.addRange(0.0, RGB(  0,   0,   0));
	//fractalCreator.addRange(0.1, RGB(255,   0,   0));
	//fractalCreator.addRange(0.2, RGB(0, 255,   255));
	fractalCreator.addRange(1.0, RGB(0, 0, 255));

	fractalCreator.addZoom(Zoom(800, 1000, 0.1));
	//fractalCreator.addZoom(Zoom(312, 304, 0.1));

	fractalCreator.run("test.bmp");

	
	cout << "Finished" << endl;
	return 0;
}