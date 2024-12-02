#include "Paddle.h"
#include <iostream>

Paddle::Paddle(const Vec2& pos, float halfW, float halfH, Color c)
	:
	position(pos),
	direction({0, 0}),
	halfWidth(halfW),
	halfHeight(halfH),
	color(c)
{
}

void Paddle::Update(Keyboard& kbd, float dt)
{
	if (kbd.KeyIsPressed('A')) {
		direction = Vec2(-1, 0);

	}
	else if (kbd.KeyIsPressed('D')) {
		direction = Vec2(1, 0);
	}
	else {
		direction = Vec2(0, 0);
	}
	position.x += direction.x * moveSpeed * dt;
}

void Paddle::Draw(Graphics& gfx)
{
	RectF rect = GetRect();
	gfx.DrawRect(rect, color);
}

RectF Paddle::GetRect() const
{
	RectF rect = RectF::FromCenter(position, halfWidth, halfHeight);
	return rect;
}

bool Paddle::HandleBallCollision(Ball& ball)
{
	bool collided = false;

	RectF& ballRect = ball.GetRectCollider();
	if (GetRect().IsOverlappingWith(ballRect)) {
		ball.ReboundY();
		ball.AddVelocity(direction * moveSpeed);	// does not consider angle of collision yet
		collided = true;
	}	

	return collided;
}

void Paddle::HandleWallCollision(const RectF& walls)
{
	RectF rect = GetRect();
	if (rect.right >= walls.right) {
		position.x -= rect.right - walls.right;
	}
	else if (rect.left <= walls.left) {
		position.x += walls.left - rect.left;
	}
}
