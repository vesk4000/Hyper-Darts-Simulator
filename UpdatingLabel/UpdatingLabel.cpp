#include "../main.h"

UpdatingLabel::UpdatingLabel(const function<string()>& getter) :
	getter(getter),
	position(Vector2(ConsoleGetCursor())) {
		string text = getter();
		cout << text;
		lastLength = text.size();
	};

void UpdatingLabel::Update() {
	Vector2 oldPos = ConsoleGetCursor();
	ConsoleSetCursor(position);
	string text = getter();
	cout << text;
	if(text.length() < lastLength)
		for(size_t i = 0; i < lastLength - text.length(); ++i)
			cout << " ";
	lastLength = text.length();
	ConsoleSetCursor(oldPos);
}