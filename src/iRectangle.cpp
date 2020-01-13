#include "pch.h"
#include "iRectangle.h"
#include "Shape.h"

IMPLEMENT_SERIAL(iRectangle, Shape, 1);

iRectangle::iRectangle(void) {}
iRectangle::~iRectangle(void) {}

void iRectangle::innerDraw(CDC *dc) {
	dc->Rectangle(startP.x, startP.y, endP.x, endP.y);
}

bool iRectangle::InShape(CPoint point) {
	int minX = startP.x < endP.x ? startP.x : endP.x;
	int maxX = startP.x > endP.x ? startP.x : endP.x;
	int minY = startP.y < endP.y ? startP.y : endP.y;
	int maxY = startP.y > endP.y ? startP.y : endP.y;

	if (point.x < minX || point.x > maxX || point.y < minY || point.y > maxY)
		return false;
	return true;
}
