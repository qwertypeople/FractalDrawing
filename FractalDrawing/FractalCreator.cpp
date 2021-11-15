#include "FractalCreator.h"


#include <iostream>
#include <assert.h>


namespace caveofprogramming {


void FractalCreator::addRange(double rangeEnd, const RGB& rgb) {

	m_ranges.push_back(rangeEnd*Mandelbrot::MAX_ITERATIONS);
	m_colors.push_back(rgb);

	if (m_bGotFirstRange) {
		m_rangeTotals.push_back(0);
	}

	m_bGotFirstRange = true;
}

int FractalCreator::getRange(int iterations) const {
	int range = 0;

	for (int i = 1; i < m_ranges.size(); i++) {
		range = i;

		if (m_ranges[1] > iterations) {
			break;
		}
	}

	range--;
	
	assert(range > -1);
	assert(range < m_ranges.size());

	return range;
}

void FractalCreator::addZoom(const Zoom& zoom) {
	m_zoomList.add(zoom);
}

void FractalCreator::run(string name) {
	calculateIteration();
	calculateTotalIterations();
	calculateRangeTotals();
	drawFractal();
	writeBitmape(name);
}

FractalCreator::FractalCreator(int width, int height): 
	 m_width(width)
	,m_height(height)
	,m_histogram (new int[Mandelbrot::MAX_ITERATIONS + 1]{ 0 })
	,m_fractal(new int[m_width * m_height]{ 0 })
	,m_bitmap(m_width, m_height)
	,m_zoomList(m_width, m_height){

	m_zoomList.add(Zoom(width / 2, height / 2, (4. / m_width)));
}

FractalCreator::~FractalCreator() {

}

void FractalCreator::calculateIteration() {
	for (int y = 0; y < m_height; y++) {
		for (int x = 0; x < m_width; x++) {

			pair<double, double> coords = m_zoomList.doZoom(x, y);

			int iterations = Mandelbrot::getIterations(coords.first, coords.second);
			m_fractal[(y * m_width) + x] = iterations;

			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				m_histogram[iterations]++;
			}
		}
	}
}

void FractalCreator::calculateRangeTotals() {

	int rangeIndex = 0;

	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
		int pixels = m_histogram[i];
		
		if (i >= m_ranges[rangeIndex + 1]) {
			rangeIndex++;			
		}

		m_rangeTotals[rangeIndex] += pixels;
	}
}

void FractalCreator::calculateTotalIterations() {
	int total = 0;
	for (int i = 0; i <= Mandelbrot::MAX_ITERATIONS; i++) {
		m_total += m_histogram[i];
	}
}

void FractalCreator::drawFractal() {

	uint8_t red = 0;
	uint8_t green = 0;
	uint8_t blue = 0;
	int iterations = 0;
	int range = 0;
	int rangeTotal = 0;
	int rangeStart = 0;
	int totalPixels = 0;


	for (int y = 0; y < m_height; y++) {
		for (int x = 0; x < m_width; x++) {

			iterations = m_fractal[(y * m_width) + x];
			range = getRange(iterations);
			rangeTotal = m_rangeTotals[range];
			rangeStart = m_ranges[range];

			RGB& startColor = m_colors[range];
			RGB& endColor   = m_colors[range+1];
			RGB colorDiff = endColor - startColor;

			red = 0;
			green = 0;
			blue = 0;			

			uint8_t color = (uint8_t)(256 * (double)iterations / Mandelbrot::MAX_ITERATIONS);

			if (iterations != Mandelbrot::MAX_ITERATIONS) {

				totalPixels = 0;
				
				for (int i = 0; i <= iterations; i++) {
					totalPixels += m_histogram[i];

				}
				red =   startColor.m_r + colorDiff.m_r * (double)totalPixels / rangeTotal;
				green = startColor.m_g + colorDiff.m_g * (double)totalPixels / rangeTotal;
				blue =  startColor.m_b + colorDiff.m_b * (double)totalPixels / rangeTotal;
				
			}
			m_bitmap.setPixel(x, y, red, green, blue);
		}
	}
}

void FractalCreator::writeBitmape(string name) {
	m_bitmap.write(name);
}

}