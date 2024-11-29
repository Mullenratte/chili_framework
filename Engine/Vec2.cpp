#include "Vec2.h"
#include "math.h"

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

Vec2& Vec2::Normalize()
{
	return *this = GetNormalized();
}

Vec2 Vec2::GetNormalized() const
{
	float length = GetLength();
	if (length != 0.0f) {
		return *this * (1.0f / length);
	}
	return *this;
}

float Vec2::GetLength() const
{
	return sqrt(GetLengthSquared());
}

float Vec2::GetLengthSquared() const
{
	return x * x + y * y;
}
