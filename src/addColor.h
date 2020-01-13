#pragma once
#include "command.h"
#include "PicFiller.h"
#include "pch.h"
#include "Shape.h"
class addColor : public command
{
public:
	addColor(Shape *s, COLORREF color);
	~addColor(void);
	void perform();
	void rollback();
private:
	Shape *s;
	COLORREF lstClr, lstPen, newClr;
	int lstSize, lstType;
};

