#pragma once
#include "../main.h"

class Vector2 {
public:
	double x, y;

	Vector2(double x, double y);

	double SqDistanceTo(const Vector2& vec) const;

	double DistanceTo(Vector2 vec) const;

	Vector2 operator- (const Vector2& vec) const;

	operator string() const;
	
	// I have no idea why I had to include this in the header
	// file instead of the .cpp file, but idc
	// it's copy-pasted from Stack Overflow anyway...
	friend ostream & operator <<(ostream &out, const Vector2 &obj) {
		return out << static_cast<std::string>(obj);
	}
};