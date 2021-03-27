//
// Created by Magda on 03.03.2021.
//

#ifndef FIRST_STEPS_FUNCTION_H
#define FIRST_STEPS_FUNCTION_H

#include <fstream>
#include <iostream>
#include <cmath>

class Function1D {

public:
	//constructor
	//Function1D(double, double, int);
	//destructor
	~Function1D();
	double value(double, double, double);
	double bisecZero(double, double, double, double, double);

	double* x;
	double* y;
	int size;
};

#endif //FIRST_STEPS_FUNCTION_H
