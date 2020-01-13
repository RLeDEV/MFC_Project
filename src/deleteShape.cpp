#include "pch.h"
#include "deleteShape.h"

deleteShape::deleteShape(CTypedPtrArray<CObArray, Shape*> &myShapes, Shape *s)
	: myShapes(myShapes), s(s) {}

deleteShape::~deleteShape(void) {}

void deleteShape::perform() {
	lstStart = s->startP;
	lstEnd = s->endP;
	s->startP = 0;
	s->endP = 0;
}

void deleteShape::rollback() {
	s->startP = lstStart;
	s->endP = lstEnd;
}