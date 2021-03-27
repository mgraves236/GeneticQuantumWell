//
// Created by Magda on 17.03.2021.
//

#include "eigenEnergies.h"


double* eigenEnergies (double a, double v0, fEven fE, fOdd fO) {

	//std::ofstream en("energies.bin");

	double deltaE = v0 / 100.0;
	double eps = v0 / 1000.0;
	double E1 = -v0 + 0.001 * v0;
	double E2 = E1 + deltaE;
	int counter = 0;
	static double* results = nullptr;
	double* moreResults = nullptr;

	while (E2 < 0) {
		E2 = E1 + deltaE;
		if (fE.value(E1, v0, a) * fE.value(E2, v0, a) < 0) {
			counter++;
			moreResults = (double*) realloc (results, counter * sizeof(double) + 1);
			results = moreResults;
			results[counter] = fE.bisecZero(E1, E2, eps, a, v0);
			/*en << std::fixed << std::setprecision(10) << counter << "\t" <<
			   fE.bisecZero(E1, E2, eps, a, v0) << std::endl;*/
		}
		if (fO.value(E1, v0, a) * fO.value(E2, v0, a) < 0) {
			counter++;
			moreResults = (double*) realloc (results, counter * sizeof(double) + 1);
			results = moreResults;
			results[counter] = fO.bisecZero(E1, E2, eps, a, v0);
			/*en << std::fixed << std::setprecision(10) << counter << "\t" <<
			   fO.bisecZero(E1, E2, eps, a, v0) << std::endl;*/
		}
		E1 = E2;
	}
	//en.close();
	results[0] = (double)counter;
	/*for (int i = 0; i < counter + 1; i++) {
		std::cout << results[i] << std::endl;
	}*/
	return results;
}