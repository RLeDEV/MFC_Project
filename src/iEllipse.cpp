#include "pch.h"
#include "iEllipse.h"

IMPLEMENT_SERIAL(iEllipse, Shape, 1);

iEllipse::iEllipse(void) {}
iEllipse::~iEllipse(void) {}

void iEllipse::innerDraw(CDC* dc) {
	dc->Ellipse(startP.x, startP.y, endP.x, endP.y); // drawing an ellipse
}

bool iEllipse::InShape(CPoint point) {
	if (point.x > startP.x && point.x < endP.x && point.y > startP.y && point.y < endP.y)
		return true;
	return false;
}