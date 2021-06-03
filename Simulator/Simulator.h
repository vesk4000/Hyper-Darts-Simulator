#pragma once
#include "../main.h"

class Simulator {
public:
	long long int TotalScore = 0;
	long long int NumSimulations = 0;
	static int MaxScore;
private:
	thread Simulation;
	bool toStop = false;
	RandomGenerator rng;

public:
	Simulator();
	void StopAndWait();
private:
	void RunSimulation();
	int Simulate();
};