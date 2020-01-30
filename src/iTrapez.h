#pragma once
#include "Shape.h"
#include "Line.h"
class iTrapez : public Line
{
public:
	DECLARE_SERIAL(iTrapez)
	iTrapez(void);
	~iTrapez(void);
	void innerDraw(CDC* dc);
	bool InShape(CPoint point);
};

