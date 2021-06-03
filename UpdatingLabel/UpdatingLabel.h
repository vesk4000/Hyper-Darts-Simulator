#pragma once
#include "../main.h"

class UpdatingLabel {
private:
	const function<string()> getter;
	size_t lastLength;
	Vector2 position;

public:
	UpdatingLabel();
	UpdatingLabel(const function<string()>& getter);
	void Update();
};