#pragma once
#include "afx.h"
#include "pch.h"
#include "PicFiller.h"

class Shape : public CObject
{
public:
	DECLARE_SERIAL(Shape);
	Shape(void);
	virtual ~Shape();
	
	// setters
	void setStart(CPoint point) { startP = point; }
	void setEnd(CPoint point) { endP = point; }
	void setBg(COLORREF color) { bgColor = color; }
	void setPenType(int type) { penType = type; }
	void setPenSize(int size) { penSize = size; }
	void setP(COLORREF color) { pColor = color; }

	// getters
	CPoint getStart() const { return startP; }
	CPoint getEnd() const { return endP;  }
	COLORREF getBg() const { return bgColor; }
	int getPenType() const { return penType; }
	int getPenSize() const { return penSize;  }
	COLORREF getP() const { return pColor; }

	virtual void draw(CDC* dc);
	virtual void innerDraw(CDC* dc) {}
	void Serialize(CArchive& archive);
	virtual bool InShape(CPoint point) { return 0; }
	CPoint startP, endP;
	COLORREF bgColor, pColor;
	int penType, penSize;

};

