#pragma once
#include "command.h"
#include "Shape.h"

class deleteShape : public command
{
public:
	deleteShape(CTypedPtrArray<CObArray, Shape*> &myShapes, Shape* s);
	~deleteShape(void);
	void perform();
	void rollback();
private:
	CTypedPtrArray<CObArray, Shape*> &myShapes;
	Shape *s;
	CPoint lstStart, lstEnd;
};

