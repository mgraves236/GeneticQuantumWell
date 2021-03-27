#include "function.h"

/*Function1D::Function1D (double a, double b, int numPnt) {
	this->size = numPnt;
	this->x = new double [size + 1];
	this->y = new double [size + 1];
	//calculate values
	double h = 0.99 * a / (size - 1);

	for (int i = 1; i < size + 1; i++) {
		x[i] = -a + 0.001 * a + (i - 1) * h;
		//double k = sqrt(2.0 * (a + x[i]));
		//y[i] = sin(k * b/2.0) - cos(k * b/2.0) * sqrt(-2.0 * x[i]) / k;
		y[i] = this->value(x[i], a, b);
		std::cout << y[i] << std::endl;
	}
};*/


double Function1D::value(double x, double v0, double a) {
	return 0;
};

Function1D::~Function1D() {
	/*free(this->x);
	free(this->y);*/
};

double Function1D::bisecZero(double xL, double xR, double eps, double a, double v0) {
	if (value(xL, a, v0) == .0) return xL;
	if (value(xR, a, v0) == .0) return xR;

	double xM;
	while ((xR - xL) > eps) {
		xM = (xL + xR) / 2.0;
		if (value(xL, a, v0) * value(xM, a, v0) < 0) {
			xR = xM;
		} else {
			xL = xM;
		}
	}
	return xM;
}
