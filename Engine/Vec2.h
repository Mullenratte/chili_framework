#pragma once

class Vec2 
{
public:
	Vec2() = default;
	Vec2(float x_in, float y_in);
	Vec2 operator+(const Vec2& b) const;
	Vec2& operator+=(const Vec2& b);	
	Vec2 operator-(const Vec2& b) const;
	Vec2& operator-=(const Vec2& b);
	Vec2 operator*(float b) const;
	Vec2& operator*=(float b);
	Vec2& Normalize();
	Vec2 GetNormalized() const;
	float GetLength() const; 
	float GetLengthSquared() const;
	Vec2 CrossProduct(const Vec2& b) const;
	float DotProduct(const Vec2& b) const;
public:
	float x;
	float y;
};