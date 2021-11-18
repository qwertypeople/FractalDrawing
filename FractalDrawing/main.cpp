#include <iostream>
#include "FractalCreator.h"
using namespace std;
using namespace caveofprogramming;



int main() {

	cout << "Draw fractal"  << endl;

	int dim1 = 1, dim2 = 2;
	cout << "width factor: ";
	cin >>dim1;
	cout << endl << "height factor: ";
	cin >> dim1;
	cout << endl;
	try {
		FractalCreator fractalCreator(2560 * dim1, 2560 * dim2);

		fractalCreator.addRange(0.0, RGB(0, 0, 0));
		//fractalCreator.addRange(0.1, RGB(255,   0,   0));
		//fractalCreator.addRange(0.2, RGB(0, 255,   255));
		fractalCreator.addRange(1.0, RGB(0, 0, 255));

		//fractalCreator.addZoom(Zoom(800, 1000, 0.1));
		//fractalCreator.addZoom(Zoom(312, 304, 0.1));

		fractalCreator.run("test.bmp");

	}
	catch (exception& e) { cout << endl << e.what(); }
	


	
	cout << "Finished" << endl;
	return 0;
}