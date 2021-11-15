#include "RGB.h"

namespace caveofprogramming {

RGB::RGB(double r, double g, double b) :
	 m_r(r)
	,m_g(g)
	,m_b(b){

}

RGB operator-(const RGB& first, const RGB& sedond) {
	return RGB((first.m_r - sedond.m_r)
			  ,(first.m_g - sedond.m_g)
			  ,(first.m_b - sedond.m_b));
}

}