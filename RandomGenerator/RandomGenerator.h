#pragma once
#include "../main.h"

class RandomGenerator {
private:
	mt19937 engine;	
	static random_device seeder;

public:
	RandomGenerator();
	RandomGenerator(unsigned int seed);
	double Next(double _min, double _max);
	int Next(int _min, int _max);
};