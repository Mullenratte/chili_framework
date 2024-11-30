#include "Brick.h"




Brick::Brick(const RectF& rect_in, int maxHealth, Color c)
	:	
	rect(rect_in),
	color(c),
	health(maxHealth)
{
}

void Brick::Draw(Graphics& graphics) const
{
	if (!destroyed) {
		graphics.DrawRect(rect, color);
	}
}

bool Brick::HandleBallCollision(Ball& ball)
{
	bool collided = false;
	if (!destroyed) {
		if (health <= 0) destroyed = true;

		RectF& ballRect = ball.GetRectCollider();
		if (rect.IsOverlappingWith(ballRect)) {
			ball.ReboundY();
			health--;
			collided = true;
		}
	}

	return collided;
}
