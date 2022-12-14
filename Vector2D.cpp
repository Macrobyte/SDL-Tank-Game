#include "Vector2D.h"


std::ostream& operator<<(std::ostream& os, const Vector2D& vec)
{
	os << "X: " << vec.x << ", Y" << vec.y;
	return os;
}