#include "ZoomList.h"

namespace caveofprogramming {

ZoomList::ZoomList(int width, int height) : m_width(width), m_height(width){


}

void ZoomList::add(const Zoom& zoom) {
	zooms.push_back(zoom);
}

pair<double, double> ZoomList::doZoom(int x, int y) {


	return pair<double, double>(0, 0);
}

}