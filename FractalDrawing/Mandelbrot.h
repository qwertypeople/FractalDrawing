#pragma once

namespace caveofprogramming {


class Mandelbrot
{
public:
	static const int MAX_ITERATIONS =  250;
public:
	Mandelbrot();
	virtual ~Mandelbrot();
	static int getIterations(double x, double y);
};

}

