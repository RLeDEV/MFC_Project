#pragma once
#include "Shape.h"
#include "Line.h"
class iEllipse : public Line
{
public:
	DECLARE_SERIAL(iEllipse);
	iEllipse(void);
	~iEllipse(void);
	void innerDraw(CDC* dc);
	bool InShape(CPoint point);
};

