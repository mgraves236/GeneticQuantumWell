//
// Created by Magda on 20.03.2021.
//

#include "Population.h"
#include "random2.h"

// constructor
Population::Population(double targetE1, double targetE2, int totalPopulation,
					   double mutationRate, int numPnt) {
	this->totalPopulation = totalPopulation;
	this->targetE1 = targetE1;
	this->targetE2 = targetE2;
	this->mutationRate = mutationRate;
	population = new Chromosome [totalPopulation];
	newPopulation = new Chromosome [totalPopulation];
	for (int i = 0; i < totalPopulation; i++) {
		population[i] = Chromosome(numPnt);
	}
}

// rejection sampling
Chromosome Population::acceptReject() {
	std::uniform_int_distribution<int> randInt(0, this->totalPopulation);
	int counter = 0;
	while (true) {
		int index = randInt(mt_rand2);
		double random = probability2(mt_rand2) * this->maxFitness;
		Chromosome partner = population[index];

		if (random < partner.fitness) {
			return partner;
		}
		counter++;
		if (counter > 10000) {
			return population[index];
		}
	}
}

void Population::generate () {
	// natural selection
	for (int i = 0; i < totalPopulation; i++) {
		population[i].caculateFitness(targetE1, targetE2);
	}

	for (int i = 0; i < totalPopulation; i++) {
		if (population[i].fitness > maxFitness) {
			maxFitness = population[i].fitness;
		}
	}

	for (int i = 0; i < totalPopulation; i++) {
		Chromosome partnerA = acceptReject();
		Chromosome partnerB = acceptReject();

		while ((partnerB.a == partnerA.a) && (partnerA.v0 == partnerB.v0)) {
			partnerB = acceptReject();
		}
		Chromosome child = partnerA.crossover(partnerB);
		child.mutate(mutationRate);
		newPopulation[i] = child;
	}
	for (int i = 0; i < totalPopulation; i++) {
		population[i] = newPopulation[i];
	}
	generations++;
}


void Population::getBest () {
	double best = 0;
	int index = 0;
	for (int i = 0; i < totalPopulation; i++) {
		population[i].caculateFitness(targetE1, targetE2);
	}
	for (int i = 0; i < totalPopulation; i++) {
		if (population[i].fitness > best) {
			index = i;
			best = population[i].fitness;
		}
	}
	std::cout << "Best fitness: " << best << " generation # " << generations
				<< " a = " << population[index].a
			  	<< " v0 = " << population[index].v0 <<std::endl;

	if (best > perfectScore) {
		std::cout << "BEST" << std::endl << "a = " << population[index].a
					<< " v0 = " << population[index].v0 << std::endl;
		finished = true;
	}
}

bool Population::isFinished() {
	return finished;
}

