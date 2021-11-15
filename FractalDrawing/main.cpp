#include <iostream>
#include "FractalCreator.h"
using namespace std;
using namespace caveofprogramming;



int main() {
	


	cout << "Draw fractal"  << endl;

	FractalCreator fractalCreator(800, 600);

	
	fractalCreator.addZoom(Zoom(295, 202, 0.1));
	fractalCreator.addZoom(Zoom(312, 304, 0.1));

	fractalCreator.run("test.bmp");
	
	cout << "Finished" << endl;
	return 0;
}