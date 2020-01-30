#pragma once
#include "Shape.h"
#include "Line.h"
class iTriangle : public Line
{
public:
	DECLARE_SERIAL(iTriangle)
	iTriangle(void);
	~iTriangle(void);
	void innerDraw(CDC* dc);
	bool InShape(CPoint point);
};

