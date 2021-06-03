#pragma once

// Yeah Microsoft do your own stupid defines in windows.h,
// after all... why should you follow C++ standards?
#define NOMINMAX

#include <iostream>
#include <cmath>
#include <sstream>
#include <time.h>
#include <iomanip>
#include <thread>
#include <chrono>
#include <windows.h>
#include <functional>
#include <vector>
#include <random>
#include <limits>
using namespace std;
using namespace std::chrono;

#include "RandomGenerator/RandomGenerator.h"
#include "Vector2/Vector2.h"
#include "Simulator/Simulator.h"
#include "UpdatingLabel/UpdatingLabel.h"
#include "Utilities/Utilities.h"
#include "Updater/Updater.h"