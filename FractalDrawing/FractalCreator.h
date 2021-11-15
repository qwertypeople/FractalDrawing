#pragma once
#include <string>
#include <cstdint>
#include <memory>
#include <math.h>
#include <vector>
#include "ZoomList.h"
#include "Mandelbrot.h"
#include "Bitmap.h"
#include "RGB.h"

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
	vector<int> m_ranges;
	vector<RGB> m_colors;
	vector<int> m_rangeTotals;
	bool m_bGotFirstRange{ false };
			
	void calculateIteration();
	void calculateTotalIterations();
	void calculateRangeTotals();
	void drawFractal();	
	void writeBitmape(string name);
	

public:
	FractalCreator(int width, int height);
	void addRange(double rangeEnd, const RGB& rgb);
	int getRange(int iterations) const;
	virtual ~FractalCreator();
	void addZoom(const Zoom& zoom);
	void run(string name);
};

}