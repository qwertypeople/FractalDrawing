#pragma once

namespace caveofprogramming {

	struct RGB
	{
	public:
		double m_r;
		double m_g;
		double m_b;
	
		RGB(double r, double g, double b);
		

	};

	RGB operator-(const RGB& first, const RGB& sedond);

}

