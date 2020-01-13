#include "pch.h"
#include "Shape.h"
#include "afx.h"

IMPLEMENT_SERIAL(Shape, CObject, 1)

Shape::Shape(void) {}

Shape::~Shape(void) {}

void Shape::Serialize(CArchive& archive) {
	CObject::Serialize(archive); // calling the base class

	// Specific class commands
	if (archive.IsStoring()) {
		archive << startP.x << startP.y << endP.x << endP.y << bgColor << pColor << penSize << penType;
	}
	else {
		archive >> startP.x >> startP.y >> endP.x >> endP.y >> bgColor >> pColor >> penSize >> penType;
	}
}

void Shape::draw(CDC* dc) {
	CPen pen(penType, penSize, pColor);
	CBrush brush(bgColor);
	CBrush *oldBrush = dc->SelectObject(&brush); // saving
	CPen *oldPen = dc->SelectObject(&pen); // saving
	innerDraw(dc);
	dc->SelectObject(oldPen);
	dc->SelectObject(oldBrush);
}