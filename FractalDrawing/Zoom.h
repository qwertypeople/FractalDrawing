#pragma once
namespace caveofprogramming {


	class Zoom
	{
		int m_x{ 0 };
		int m_y{ 0 };
		double m_sacle{ 0 };

		Zoom(int x, int y, int scale) : m_x(x), m_y(y), m_sacle(scale) {};

	};

}
