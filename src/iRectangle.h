#pragma once
#include "Shape.h"
class iRectangle :
	public Shape
{
public:
	DECLARE_SERIAL(iRectangle)
	iRectangle(void);
	~iRectangle(void);
	void innerDraw(CDC *dc);
	bool InShape(CPoint p);
};

