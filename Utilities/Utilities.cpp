#include "../main.h"

Vector2 ConsoleGetCursor() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle( STD_OUTPUT_HANDLE ), &csbi);
	return Vector2(csbi.dwCursorPosition.X, csbi.dwCursorPosition.Y);
}

void ConsoleSetCursor(Vector2 pos) {
	COORD coord;
	coord.X = pos.x;
	coord.Y = pos.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ConsoleClear() {
	#if defined _WIN32
		system("cls");
	#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
		system("clear");
	#elif defined (__APPLE__)
		system("clear");
	#endif
}

string GetUptime(system_clock::time_point startTime) {
	system_clock::duration upTime = system_clock::now() - startTime;
	seconds s = duration_cast<seconds>(upTime);
	minutes m = duration_cast<minutes>(upTime);
	hours h = duration_cast<hours>(upTime);
	ostringstream ss;
	if(h.count() > 0)
		ss << h.count() << "h ";
	if(m.count() > 0)
		ss << m.count() % 60 << "m ";
	ss << s.count() % 60 << "s";
	return ss.str();
}