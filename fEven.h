//
// Created by Magda on 08.03.2021.
//

#ifndef QUANTUMWELL_FEVEN_H
#define QUANTUMWELL_FEVEN_H

#include "function.h"

class fEven : public Function1D {
	public:
	//using Function1D::Function1D;
	fEven(double, double, int);
	double value(double, double, double);
};

#endif //QUANTUMWELL_FEVEN_H
