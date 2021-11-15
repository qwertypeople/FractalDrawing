#pragma once
#include <string>
#include "ZoomList.h"

namespace caveofprogramming {

class FractalCreator
{
public:
	FractalCreator(int width, int height);
	virtual ~FractalCreator();

	void calculateIteration();
	void drawFractal();
	void addZoom(const Zoom& zoom);
	void writeBitmape(string name);
};

}