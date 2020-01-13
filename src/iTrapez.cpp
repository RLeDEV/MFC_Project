#include "pch.h"
#include "iTrapez.h"

IMPLEMENT_SERIAL(iTrapez, Shape, 1);

iTrapez::iTrapez(void) {}
iTrapez::~iTrapez(void) {}

void iTrapez::innerDraw(CDC* dc) {
	CPoint TrapezP[4];
	TrapezP[0].SetPoint(startP.x, endP.y);
	TrapezP[1].SetPoint(endP.x, endP.y);
	TrapezP[2].SetPoint((endP.x - startP.x) * 3 / 4 + startP.x, startP.y); // base
	TrapezP[3].SetPoint((endP.x - startP.x) * 1 / 4 + startP.x, startP.y); // base

	dc->Polygon(TrapezP, 4); // Drawing Trapez
}

bool iTrapez::InShape(CPoint point) {
	int minX = startP.x < ((endP.x - startP.x) * 1 / 4) ? startP.x : ((endP.x - startP.x) * 1 / 4);
	int maxX = endP.x < ((endP.x - startP.x) * 3 / 4) ? ((endP.x - startP.x) * 3 / 4) : endP.x;
	int minY = startP.y < endP.y ? startP.y : endP.y;
	int maxY = endP.y < startP.y ? startP.y : endP.y;

	if (point.x < minX || point.x > maxX || point.y < minY || point.y > maxY)
		return false;
	return true;
}