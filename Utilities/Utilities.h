#pragma once
#include "../main.h"

/*void InitRandom();
double DoubleRandomRange(double _min, double _max);*/
Vector2 ConsoleGetCursor();
void ConsoleSetCursor(Vector2 pos);
void ConsoleClear();
string GetUptime(system_clock::time_point startTime);