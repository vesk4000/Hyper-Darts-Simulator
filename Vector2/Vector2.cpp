#include "../main.h"

Vector2::Vector2(double x, double y) : x(x), y(y) {}

double Vector2::SqDistanceTo(const Vector2& vec) const {
	Vector2 diff = (*this) - vec;
	return diff.x * diff.x + diff.y * diff.y;
}

double Vector2::DistanceTo(Vector2 vec) const {
	return sqrt(SqDistanceTo(vec));
}

Vector2 Vector2::operator- (const Vector2& vec) const {
	return Vector2(this->x - vec.x, this->y - vec.y);
}

Vector2::operator string() const {
	ostringstream ss;
	ss << setprecision(10) << x << " " << y;
	return ss.str();
}