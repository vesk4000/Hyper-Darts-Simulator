#include "main.h"

int main() {
	cout << "Enter number of threads to execute with: ";
	int threads;
	cin >> threads;
	vector<Simulator> sims(threads);
	ConsoleClear();

	cout << "Uptime: ";
	system_clock::time_point startTime = system_clock::now();
	UpdatingLabel labelUptime( [&startTime]() { return GetUptime(startTime); } );
	cout << endl;

	cout << "Total Simulations: ";
	UpdatingLabel labelSimulationCount( [&sims]() -> string {
		long long int count = 0;
		for(size_t i = 0; i < sims.size(); ++i)
			count += sims[i].NumSimulations;
		ostringstream ss;
		ss << count;
		return ss.str();
	});
	cout << endl;

	cout << "Average Score: ";
	UpdatingLabel labelAverageScore( [&sims]() -> string {
		long long int count = 0;
		long long int score = 0;
		for(size_t i = 0; i < sims.size(); ++i) {
			count += sims[i].NumSimulations;
			score += sims[i].TotalScore;
		}
		ostringstream ss;
		ss << setprecision(50) << double(score) / count;
		return ss.str();
	});
	cout << endl;

	cout << "Press enter to terminate: ";

	Updater labelUpdater( [&labelUptime, &labelSimulationCount, &labelAverageScore]() -> void {
		labelUptime.Update();
		labelSimulationCount.Update();
		labelAverageScore.Update();
	}, 50);

	cin.ignore();
	cin.get();

	labelUpdater.StopAndWait();
	for(size_t i = 0; i < sims.size(); ++i)
		sims[i].StopAndWait();
	
	string finalUptime = GetUptime(startTime);

	ConsoleClear();

	cout << "Simulations terminated successfully" << endl;
	cout << "Total time taken: " << finalUptime << endl;
	long long int finalSimsCount = 0;
	long long int finalScore = 0;
	for(size_t i = 0; i < sims.size(); ++i) {
		finalSimsCount += sims[i].NumSimulations;
		finalScore += sims[i].TotalScore;
	}
	cout << "Total number of simulations ran: " << finalSimsCount << endl;
	cout << "Total score of all simulations: " << finalScore << endl;
	cout << "Maximum score achieved: " << Simulator::MaxScore << endl;
	cout << "Average score across all simulations: "
		<< setprecision(50) << double(finalScore) / finalSimsCount << endl;

	return 0;
}