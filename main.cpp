#include <iostream>
#include <iomanip>

#include "fOdd.h"
#include "fEven.h"
#include "eigenEnergies.h"
#include "Population.h"

int main() {
	//initial parameters
	int numPnt = 100;
	/*
	 * searching for Bohr parameters (2 first energy levels)
	 * using genetic algorithm
	 */
	double targetE1 = -0.5;
	double targetE2 = - 0.125;
	static int populationMax = 1000;
	static double mutationRate = 0.3;
	static Population population(targetE1, targetE2, populationMax, mutationRate, numPnt);
	std::cout << "Population created." << std::endl;

	while (!population.isFinished()) {
		population.generate();
		population.getBest();
		std::cout << "-------------------------------------------------------------------" << std::endl;
	}

	return 0;
}
