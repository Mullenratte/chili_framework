#pragma once
#include "Graphics.h"
#include "RectF.h"
#include "Ball.h"

class Brick
{
public:
	Brick() = default;
	Brick(const RectF& rect_in, int maxHealth, Color c);
	void Draw(Graphics& graphics) const;
	bool HandleBallCollision(Ball& ball);
private:
	int health;
	bool destroyed = false;
	RectF rect;
	Color color;
};

