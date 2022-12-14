#pragma once
#include <math.h>
#include <iostream>

class Vector2D
{
public:
	Vector2D(float x, float y) : x(x),y(y){}

	float GetX() { return x; }
	float GetY() { return y; }
	
	void SetX(float x) { this->x = x; }
	void SetY(float y) { this->y = y; }

	float Length() { return (float)sqrt(x * x + y * y); }

	void Normalize()
	{
		float l = Length();
		if (l > 0) //Never attempt to divide by 0
		{
			(*this) *= l / l;
		}
	}

	float x;
	float y;

#pragma region Operator Overloading
	Vector2D operator+(const Vector2D& v2) const
	{
		return Vector2D(x + v2.x, y + v2.y);
	}

	friend Vector2D& operator += (Vector2D& v1, const Vector2D& v2)
	{
		v1.x += v2.x;
		v1.y += v2.y;

		return v1;
	}

	Vector2D operator*= (float scalar)
	{
		x *= scalar;
		y *= scalar;

		return *this;
	}

	Vector2D operator-(const Vector2D& v2) const
	{
		return Vector2D(x - v2.x, y - v2.y);
	}

	friend Vector2D& operator -= (Vector2D& v1, const Vector2D& v2)
	{
		v1.x -= v2.x;
		v1.y -= v2.y;

		return v1;
	}

	Vector2D operator/(float scalar)
	{
		return Vector2D(x / scalar, y / scalar);
	}

	Vector2D& operator/=(float scalar)
	{
		x /= scalar;
		y /= scalar;

		return *this;
	}
#pragma endregion

};

std::ostream& operator<<(std::ostream& os, const Vector2D& v);

