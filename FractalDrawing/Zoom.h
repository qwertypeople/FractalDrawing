#pragma once
namespace caveofprogramming {


	class Zoom
	{
	public:

		int m_x{ 0 };
		int m_y{ 0 };
		double m_scale{ 1 };

		Zoom(int x, int y, double scale) :
			 m_x(x)
			,m_y(y)
			, m_scale(scale) {};
	};
}
