#pragma once
#include "Graphics.h"
#include "RectF.h"

class Brick
{
public:
	Brick(const RectF& rect_in, Color c);
	void Draw(Graphics& graphics) const;
private:
	//int health;
	RectF rect;
	Color color;
};

