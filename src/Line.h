#pragma once
#include "Shape.h"
class Line : public Shape
{
	DECLARE_SERIAL(Line);
	Line(void);
	~Line(void);
	void innerDraw(CDC* dc);
	bool InShape(CPoint point);
};

