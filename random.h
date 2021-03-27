//
// Created by Magda on 20.03.2021.
//

#ifndef QUANTUMWELL_RANDOM_H
#define QUANTUMWELL_RANDOM_H

#include <random>
#include <chrono>

auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 mt_rand(seed);
std::uniform_real_distribution<double> randDouble(0.1, 4.0);
std::uniform_real_distribution<float> probability(0.0, 1.0);

#endif //QUANTUMWELL_RANDOM_H
