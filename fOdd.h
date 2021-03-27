//
// Created by Magda on 08.03.2021.
//

#ifndef QUANTUMWELL_FODD_H
#define QUANTUMWELL_FODD_H

#include "function.h"

class fOdd : public Function1D {
	public:
		//using Function1D::Function1D;
		fOdd(double, double, int);
		double value(double, double, double);
};

#endif //QUANTUMWELL_FODD_H
