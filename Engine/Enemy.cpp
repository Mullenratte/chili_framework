#include "Enemy.h"
#include "Graphics.h"
#include <cassert>

void Enemy::Init(int x, int y, int vX, int vY)
{
	assert(initialized == false);
	xPos = x;
	yPos = y;
	velX = vX;
	velY = vY;
	initialized = true;
}

void Enemy::Update() {
	assert(initialized == true);
	xPos += velX;
	yPos += velY;

	const int right = xPos + width;
	if (xPos < 0) {
		xPos = 0;
		velX = -velX;
	}
	else if (right >= Graphics::ScreenWidth) {
		xPos = (Graphics::ScreenWidth - 1) - width;
		velX = -velX;
	}
	
	const int bottom = yPos + height;
	if (yPos < 0) {
		yPos = 0;
		velY = -velY;
	}
	else if (bottom >= Graphics::ScreenHeight) {
		yPos = Graphics::ScreenHeight - 1 - height;
		velY = -velY;
	}
}

void Enemy::ProcessHit(int collX, int collY, int collWidth, int collHeight)
{
	assert(initialized == true);

	const int right = xPos + width;
	const int bottom = yPos + height;
	const int collRight = collX + collWidth;
	const int collBottom = collY + collHeight;

	if ((collX <= xPos || collX <= right) && collRight >= xPos && (collY <= yPos || collY <= bottom) && collBottom >= yPos) {	
		isDestroyed = true;
	}
}


void Enemy::Draw(Graphics& gfx) const
{
	assert(initialized == true);

	if (!isDestroyed) {
		for (int j = yPos; j < yPos + height; j++) {
			for (int i = xPos; i < xPos + width; i++) {
				gfx.PutPixel(i, j, Colors::Red);
			}
		}
	}
}

bool Enemy::IsDestroyed() const
{
	assert(initialized == true);

	return isDestroyed;
}
