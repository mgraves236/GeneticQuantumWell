//
// Created by Magda on 08.03.2021.
//

#include "fOdd.h"

#include <iostream>

double fOdd::value(double x, double v0, double a) {
	double k = sqrt(2.0 * (v0 + x));
	return sin(k * a/2.0) + cos(k * a/2.0) * k / sqrt(-2.0 * x);
}

fOdd::fOdd (double a, double b, int numPnt) {
	this->size = numPnt;
	this->x = new double [size + 1];
	this->y = new double [size + 1];
	//calculate values
	double h = 0.99 * a / (size - 1);

	for (int i = 1; i < size + 1; i++) {
		x[i] = -a + 0.001 * a + (i - 1) * h;
		y[i] = this->value(x[i], a, b);
	}
};
