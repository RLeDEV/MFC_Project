#include "pch.h"
#include "iPentagon.h"

IMPLEMENT_SERIAL(iPentagon, Shape, 1)

iPentagon::iPentagon(void) {}
iPentagon::~iPentagon(void) {}

void iPentagon::innerDraw(CDC *dc) {
	CPoint PentagonP[5];
	PentagonP[0].SetPoint(startP.x, endP.y);
	PentagonP[1].SetPoint(endP.x, endP.y);
	PentagonP[2].SetPoint(endP.x + (endP.x - startP.x), (endP.y + startP.y) * 1 / 2);
	PentagonP[3].SetPoint(endP.x, startP.y);
	PentagonP[4].SetPoint(startP.x, startP.y);

	dc->Polygon(PentagonP, 5); // Drawing Pentagon
}

bool iPentagon::InShape(CPoint point) {
	int minX = startP.x < endP.x ? startP.x : endP.x;
	int maxX = startP.x > (endP.x + (endP.x - startP.x)) ? startP.x : (endP.x + (endP.x - startP.x));
	int minY = startP.y < endP.y ? startP.y : endP.y;
	int maxY = startP.y > endP.y ? startP.y : endP.y;

	if (point.x < minX || point.x > maxX || point.y < minY || point.y > maxY)
		return false;
	return true;
}