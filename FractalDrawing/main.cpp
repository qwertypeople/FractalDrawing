#include <iostream>




#include "FractalCreator.h"



using namespace std;

using namespace caveofprogramming;

int main() {
	cout <<"Draw fractal"  << endl;

	int height = 600;

	FractalCreator fractalCreator(8000, 6000);	
	//fractalCreator.addZoom(Zoom(295, height -202, 0.1));
	//fractalCreator.addZoom(Zoom(312, height - 304, 0.1));
	fractalCreator.calculateIteration();
	fractalCreator.calculateTotalIterations();
	fractalCreator.drawFractal();
	fractalCreator.writeBitmape("test.bmp");
	
	cout << "Finished" << endl;
	return 0;
}