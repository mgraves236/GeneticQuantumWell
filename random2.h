//
// Created by Magda on 20.03.2021.
//

#ifndef QUANTUMWELL_RANDOM2_H
#define QUANTUMWELL_RANDOM2_H

#include <random>
#include <chrono>

auto seed2 = std::chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 mt_rand2(seed2);
std::uniform_real_distribution<double> randDouble2(0.1, 4.0);
std::uniform_real_distribution<float> probability2(0.0, 1.0);

#endif //QUANTUMWELL_RANDOM2_H
