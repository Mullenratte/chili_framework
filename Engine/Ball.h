#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "RectF.h"

class Ball
{
public:
	Ball(const Vec2& center_in, const Vec2& velocity_in, Color c);
	void Draw(Graphics& graphics);
	void Update(float dt);
	bool HandleWallCollision(const RectF& wall);
	RectF GetRectCollider() const;
private:
	void ReboundX();
	void ReboundY();
private:
	static constexpr float radius = 8.0f;
	Vec2 center;
	Color color;
	Vec2 velocity;
	
};

