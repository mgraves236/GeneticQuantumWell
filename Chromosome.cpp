//
// Created by Magda on 20.03.2021.
//

#include "Chromosome.h"
#include "random.h"
#include <math.h>

Chromosome::Chromosome() {
	a = randDouble(mt_rand);
	v0 = randDouble(mt_rand);
}

Chromosome::Chromosome(int numPnt) {
	this->numPnt = numPnt;
	a = randDouble(mt_rand);
	v0 = randDouble(mt_rand);
}

void Chromosome::caculateFitness (double targetE1, double targetE2) {

	fEven fE (v0, a, numPnt);
	fOdd fO (v0, a, numPnt);

	double* energies = nullptr;
	energies = eigenEnergies (a, v0, fE, fO);
	if (energies == nullptr) {
		this->fitness = 0;
	} else {
		// we're intersted in the first two energy states
		// fit for the first energy
		double score1 = abs(energies[1] - targetE1);
		if (energies[0] != 2.0 ) {
			this -> fitness = 0;
		} else {
			double score2 = abs(energies[2] - targetE2);
			if ((score1 > 1.0) || (score2 > 1.0)) {
				this->fitness = 0.0;
			} else {
				double score = (double) 1 - (score1 + score2);
				this->fitness = score;
			}
		}
	}
}

Chromosome Chromosome::crossover (Chromosome partner) {
	Chromosome child = Chromosome(this->numPnt);
	float prob = probability(mt_rand);
	if (prob > 0.5) {
		child.a = this->a;
	} else {
		child.a = partner.a;
	}
	prob = probability(mt_rand);
	if (prob > 0.5) {
		child.v0 = this->v0;
	} else {
		child.v0 = partner.v0;
	}
	return child;
}

// mutate genes with probability of mutationRate
void Chromosome::mutate(double mutationRate) {
	float rand = probability(mt_rand);
	if (mutationRate > (double)rand) {
		this->a = randDouble(mt_rand);
	}
	rand = probability(mt_rand);
	if (mutationRate > rand) {
		this->v0 = randDouble(mt_rand);
	}
}