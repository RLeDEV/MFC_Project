#pragma once
#include "Shape.h"
class iTrapez : public Shape
{
public:
	DECLARE_SERIAL(iTrapez)
	iTrapez(void);
	~iTrapez(void);
	void innerDraw(CDC* dc);
	bool InShape(CPoint point);
};

