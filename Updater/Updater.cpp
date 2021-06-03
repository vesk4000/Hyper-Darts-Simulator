#include "../main.h"

Updater::Updater(const function<void()>& update, int updateTimer) :
	task(thread(&Updater::RunUpdates, this)),
	updateTimer(updateTimer),
	update(update) {};

void Updater::StopAndWait() {
	toStop = true;
	task.join();
}

void Updater::RunUpdates() {
	while(!toStop) {
		update();
		this_thread::sleep_for(chrono::milliseconds(updateTimer));
	}
}