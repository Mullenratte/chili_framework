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
	void ReboundX();
	void ReboundY();
	void AddVelocity(const Vec2& vel);
private:
	static constexpr float radius = 8.0f;
	Vec2 center;
	Color color;
	Vec2 velocity;
	
};

