#include "pch.h"
#include "addShape.h"

addShape::addShape(CTypedPtrArray<CObArray, Shape*> &myShapes, Shape *s)
	: myShapes(myShapes), s(s) {}

addShape::~addShape(void) {}

void addShape::perform() {
	myShapes.Add(s);
}

void addShape::rollback() {
	for (int i = 0; i < myShapes.GetSize(); i++) {
		if (myShapes[i] == s) {
			myShapes.RemoveAt(i);
			return;
		}
	}
}