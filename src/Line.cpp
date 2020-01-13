#include "pch.h"
#include "Line.h"
#include "Shape.h"

IMPLEMENT_SERIAL(Line, Shape, 1);

Line::Line(void) {}
Line::~Line(void) {}

void Line::innerDraw(CDC* dc) { // Drawing a line between startP to endP
	dc->MoveTo(startP.x, startP.y);
	dc->LineTo(endP.x, endP.y);
}

bool Line::InShape(CPoint point) {
	int x = startP.x - endP.x;
	int y = startP.y - endP.y;

	int minX = startP.x < endP.x ? startP.x : endP.x;
	int maxX = startP.x > endP.x ? startP.x : endP.x;
	int minY = startP.y < endP.y ? startP.y : endP.y;
	int maxY = startP.y > endP.y ? startP.y : endP.y;

	double m = (double)y / double(x);
	if ((point.y - startP.y - m * (point.x - startP.x)) - 7 && (point.y - startP.y - m * (point.x - startP.x) < 7) && (!(point.x < minX || point.x > maxX || point.y < minY || point.y > maxY)))
		return true;
	return false;
}

