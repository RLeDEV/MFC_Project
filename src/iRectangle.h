#pragma once
#include "Shape.h"
#include "Line.h"
class iRectangle :
	public Line
{
public:
	DECLARE_SERIAL(iRectangle)
	iRectangle(void);
	~iRectangle(void);
	void innerDraw(CDC *dc);
	bool InShape(CPoint p);
};

