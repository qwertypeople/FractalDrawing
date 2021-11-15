#pragma once
#include <string>
#include <cstdint>
#include <memory>
#include <math.h>
#include "ZoomList.h"
#include "Mandelbrot.h"
#include "Bitmap.h"

using namespace std;

namespace caveofprogramming {

class FractalCreator
{
private:
	int m_width;
	int m_height;
	int m_total{0};

	unique_ptr<int[]> m_histogram;
	unique_ptr<int[]> m_fractal;
	Bitmap m_bitmap;
	ZoomList m_zoomList;
public:
	FractalCreator(int width, int height);
	virtual ~FractalCreator();

	void calculateIteration();
	void calculateTotalIterations();
	void drawFractal();
	void addZoom(const Zoom& zoom);
	void writeBitmape(string name);
};

}