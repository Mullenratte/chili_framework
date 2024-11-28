#include "Vec2.h"

Vec2::Vec2(float x_in, float y_in)
	:
	x(x_in),
	y(y_in)
{
}

Vec2 Vec2::operator+(const Vec2& b) const
{
	return Vec2(x + b.x, y + b.y);
}

Vec2& Vec2::operator+=(const Vec2& b)
{
	return *this = *this + b;
}

Vec2 Vec2::operator*(float b) const
{
	return Vec2(x * b, y * b);
}

Vec2& Vec2::operator*=(float b)
{
	return *this = *this * b;
}
