#pragma once
#include "Shape.h"
class iTriangle : public Shape
{
public:
	DECLARE_SERIAL(iTriangle)
	iTriangle(void);
	~iTriangle(void);
	void innerDraw(CDC* dc);
	bool InShape(CPoint point);
};

