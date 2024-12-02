#include "Ball.h"

Ball::Ball(const Vec2& center_in, const Vec2& velocity_in, Color c)
	:
	center(center_in),
	velocity(velocity_in),
	color(c)
{
}

void Ball::Draw(Graphics& graphics)
{
	graphics.DrawCircle(center, radius, color);
}

void Ball::Update(float dt)
{
	center += velocity * dt;
}

bool Ball::HandleWallCollision(const RectF& walls)
{
	bool collided = false;
	const RectF rectColl = GetRectCollider();
	if (rectColl.left < walls.left) {
		center.x += walls.left - rectColl.left;
		ReboundX();
		collided = true;
	}
	if (rectColl.right > walls.right) {
		center.x -= rectColl.right - walls.right;
		ReboundX();
		collided = true;
	}
	if (rectColl.top < walls.top) {
		center.y += walls.top - rectColl.top;
		ReboundY();
		collided = true;
	}
	if (rectColl.bottom > walls.bottom) {
		center.y -= rectColl.bottom - walls.bottom;
		ReboundY();
		collided = true;
	}

	return collided;
}

RectF Ball::GetRectCollider() const
{
	return RectF::FromCenter(center, radius, radius);
}

void Ball::ReboundX()
{
	velocity.x = -velocity.x;
}

void Ball::ReboundY()
{
	velocity.y = -velocity.y;
}

void Ball::AddVelocity(const Vec2& vel)
{
	velocity += vel;
}
