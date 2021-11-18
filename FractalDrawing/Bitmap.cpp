#include <fstream>
#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"


using namespace std;
using namespace caveofprogramming;

namespace caveofprogramming  {

	Bitmap::Bitmap(int width, int heigth) : 
		 m_width(width)
		,m_height(heigth)
		,m_pPixels(new uint8_t[width * heigth * 3]{}) {

	}

	bool Bitmap::write(string filename) {



		BitmapFileHeader fileHeader;
		BitmapInfoHeader infoHeader;

		fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);
		fileHeader.fileSize = sizeof(fileHeader.dataOffset) + m_width * m_height * 3;

		infoHeader.width = m_width;
		infoHeader.height = m_height;

		ofstream file;
		file.open(filename, ios::out | ios::binary);
		
		// check is file is open
		if (!file) {
			return false;
		}

		
		file.write((char*)&fileHeader, sizeof(fileHeader));
		file.write((char*)&infoHeader, sizeof(infoHeader));
		file.write((char*)m_pPixels.get(), m_width * m_height * 3);

		file.close();
		// check is file is close
		if (!file) {
			return false;
		}
		return true;
	}

	void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t bleu) {
		//uint8_t* pPixel = m_pPixels.get();
		uint8_t* pPixel = m_pPixels.get();
		pPixel += (y*3) * m_width + (x*3);
		pPixel[0] = bleu;
		pPixel[1] = green;
		pPixel[2] = red;


	}

	Bitmap::~Bitmap(){

	}

} /* namespace caveofprogramming */

