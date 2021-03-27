//
// Created by Magda on 20.03.2021.
//

#ifndef QUANTUMWELL_CHROMOSOME_H
#define QUANTUMWELL_CHROMOSOME_H

#include <iostream>

#include "fOdd.h"
#include "fEven.h"
#include "eigenEnergies.h"


class Chromosome {

public:
	int numPnt = 0;
	double a = 0;
	double v0 = 0;
	float fitness = 0;

	Chromosome();
	Chromosome(int);
	void caculateFitness(double, double);
	Chromosome crossover(Chromosome);
	void mutate(double);
};


#endif //QUANTUMWELL_CHROMOSOME_H
