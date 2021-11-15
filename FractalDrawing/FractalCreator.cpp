#include "FractalCreator.h"



namespace caveofprogramming {

void FractalCreator::run(string name) {




	calculateIteration();
	calculateTotalIterations();
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
		//cout << "boucle 1." << y << endl;
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

	RGB startColor(0, 0, 20);
	RGB endColor(255, 128, 74);
	RGB colorDiff = endColor - startColor;

	for (int y = 0; y < m_height; y++) {
		for (int x = 0; x < m_width; x++) {

			red = 0;
			green = 0;
			blue = 0;

			int iterations = m_fractal[(y * m_width) + x];

			uint8_t color = (uint8_t)(256 * (double)iterations / Mandelbrot::MAX_ITERATIONS);

			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				double hue = 0.0;
				for (int i = 0; i <= iterations; i++) {
					hue += (double)m_histogram[i] / m_total;
				}

				red = startColor.m_r + colorDiff.m_r * hue;
				green = startColor.m_g + colorDiff.m_g * hue;
				blue = startColor.m_b + colorDiff.m_b * hue;
				
			}
			m_bitmap.setPixel(x, y, red, green, blue);
		}
	}

}
void FractalCreator::addZoom(const Zoom& zoom) {
	m_zoomList.add(zoom);
}
void FractalCreator::writeBitmape(string name) {
	m_bitmap.write(name);
}




}