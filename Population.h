//
// Created by Magda on 20.03.2021.
//

#ifndef QUANTUMWELL_POPULATION_H
#define QUANTUMWELL_POPULATION_H

#include "Chromosome.h"

class Population {

public:
	double mutationRate = 0;
	int totalPopulation = 0;
	double targetE1 = 0;
	double targetE2 = 0;
	float maxFitness = 0;
	int generations = 0;
	float perfectScore = 0.997;
	bool finished = false;
	Chromosome* population = nullptr;
	Chromosome* newPopulation = nullptr;

	Population(double, double, int, double, int);
	Chromosome acceptReject();
	bool isFinished();
	void getBest();
	void generate ();
};


#endif //QUANTUMWELL_POPULATION_H
