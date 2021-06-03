#include "../main.h"

int Simulator::MaxScore = 0;

Simulator::Simulator() : Simulation(thread(&Simulator::RunSimulation, this)) {}

void Simulator::RunSimulation() {
	while(!toStop) {
		TotalScore += Simulate();
		++NumSimulations;
	}
}

int Simulator::Simulate() {
	int score = 0;
	double sqRadius = 1;
	Vector2 center(0, 0);
	while(true) {
		++score;
		Vector2 pos(rng.Next(-1.0, 1.0), rng.Next(-1.0, 1.0));
		double sqDist = pos.SqDistanceTo(center);
		if(sqDist <= sqRadius)
			sqRadius -= sqDist;
		else {
			MaxScore = max(MaxScore, score);
			return score;
		}
	}
	return 1;
}

void Simulator::StopAndWait() {
	toStop = true;
	Simulation.join();
}