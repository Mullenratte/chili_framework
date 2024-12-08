#include "Brick.h"




Brick::Brick(const RectF& rect_in, int maxHealth, Color c)
	:	
	rect(rect_in),
	health(maxHealth),
	color(c)	
{
}

void Brick::Draw(Graphics& graphics) const
{
	if (!destroyed) {
		graphics.DrawRectPadding(rect, 2.0f, color);
	}
}

bool Brick::HandleBallCollision(Ball& ball)
{
	bool collided = false;
	if (!destroyed) {
		if (health <= 0) destroyed = true;

		RectF& ballRect = ball.GetRectCollider();
		Vec2 center = rect.GetCenter();
		if (rect.IsOverlappingWith(ballRect)) {
			if (ball.center.x > rect.right) {
				ball.ReboundX();
				ball.center.x += rect.right - ballRect.left;
			}
			else if (ball.center.x < rect.left) {
				ball.ReboundX();
				ball.center.x += rect.left - ballRect.right;
			}
			else if (ball.center.y > rect.bottom) {
				ball.ReboundY();
				ball.center.y += rect.bottom - ballRect.top;

			}
			else if (ball.center.y < rect.top){
				ball.ReboundY();
				ball.center.y += rect.top - ballRect.bottom;
			}
			health--;
			collided = true;
		}
	}

	return collided;
}
