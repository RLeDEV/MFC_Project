#include "pch.h"
#include "addColor.h"

addColor::addColor(Shape *s, COLORREF color) {
	this->s = s;
	this->newClr = color;
}

void addColor::perform() {
	lstClr = s->bgColor;
	lstPen = s->pColor;
	lstSize = s->penSize;
	lstType = s->penType;
	s->setBg(newClr);
	s->setP(RGB(0, 0, 0));
	s->setPenSize(1);
	s->setPenType(PS_SOLID);
}

void addColor::rollback() {
	s->setBg(lstClr);
	s->setP(lstPen);
	s->setPenSize(lstSize);
	s->setPenType(lstType);
}