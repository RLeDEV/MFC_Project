#include "pch.h"
#include "iTriangle.h"

IMPLEMENT_SERIAL(iTriangle, Shape, 1);

iTriangle::iTriangle(void) {}
iTriangle::~iTriangle(void) {}

void iTriangle::innerDraw(CDC *dc) {
	CPoint TriangleP[3];
	TriangleP[0].SetPoint(startP.x, endP.y);
	TriangleP[1].SetPoint(endP.x, endP.y);
	TriangleP[2].SetPoint((startP.x + endP.x) / 2, startP.y);

	dc->Polygon(TriangleP, 3);
}

bool iTriangle::InShape(CPoint point) {
	int minX = startP.x < endP.x ? startP.x : endP.x;
	int maxX = startP.x > endP.x ? startP.x : endP.x;
	int minY = startP.y < endP.y ? startP.y : endP.y;
	int maxY = startP.y > endP.y ? startP.y : endP.y;

	if (point.x < minX || point.x > maxX || point.y < minY || point.y > maxY)
		return false;
	return true;
}