#pragma once
#include "Vec2.h"
#include "RectF.h"
#include "Graphics.h"
#include "Keyboard.h"
#include "Ball.h"


class Paddle
{
public:
	Paddle(const Vec2& pos, float halfW, float halfH, Color c);
	void Update(Keyboard& kbd, float dt);
	void Draw(Graphics& gfx);
	RectF GetRect() const;
	bool HandleBallCollision(Ball& ball);
	void HandleWallCollision(const RectF& walls);
private:
	Color color;
	Vec2 position;
	Vec2 direction;
	static constexpr float moveSpeed = 250.0f;
	float halfWidth;
	float halfHeight;


};

