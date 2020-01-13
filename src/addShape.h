#pragma once
#include "command.h"
#include "Shape.h"

class addShape : public command
{
public:
	addShape(CTypedPtrArray<CObArray, Shape*> &myShapes, Shape *s);
	~addShape(void);
	void perform();
	void rollback();
private:
	CTypedPtrArray<CObArray, Shape*> &myShapes;
	Shape *s;
};