#pragma once
#include "Shape.h"
class iPentagon : public Shape
{
public:
	DECLARE_SERIAL(iPentagon)
	iPentagon(void);
	~iPentagon(void);
	void innerDraw(CDC *dc);
	bool InShape(CPoint point);
};

