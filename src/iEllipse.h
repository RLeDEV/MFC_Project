#pragma once
#include "Shape.h"
class iEllipse : public Shape
{
public:
	DECLARE_SERIAL(iEllipse);
	iEllipse(void);
	~iEllipse(void);
	void innerDraw(CDC* dc);
	bool InShape(CPoint point);
};

