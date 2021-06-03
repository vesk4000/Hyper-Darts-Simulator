#include "../main.h"

random_device RandomGenerator::seeder;

RandomGenerator::RandomGenerator(unsigned int seed) : engine(seed) {}

RandomGenerator::RandomGenerator() : engine(mt19937((int)seeder())) {}

double RandomGenerator::Next(double _min, double _max) {
	uniform_real_distribution<double> distribution(_min, nextafter(_max, numeric_limits<double>::max()));
	return distribution(engine);
}

int RandomGenerator::Next(int _min, int _max) {
	uniform_int_distribution<int> distribution(_min, _max);
	return distribution(engine);
}