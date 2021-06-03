#pragma once
#include "../main.h"

class Updater {
private:
	thread task;
	int updateTimer;
	const function<void()> update;
	bool toStop = false;

public:
	Updater(const function<void()>& update, int updateTimer = 50);
	void StopAndWait();
private:
	void RunUpdates();
};