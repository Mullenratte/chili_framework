#pragma once
#include "Graphics.h"

class Enemy
{
public:
	void Init(int x, int y, int vX, int vY);
	void Update();
	void ProcessHit(int collX, int collY, int collWidth, int collHeight);
	void Draw(Graphics& gfx) const;
	bool IsDestroyed() const;

private:
	int xPos;
	int yPos;
	int velX;
	int velY;
	static constexpr int width = 24;
	static constexpr int height = 24;
	bool isDestroyed = false;
	bool initialized = false;
private:

};

