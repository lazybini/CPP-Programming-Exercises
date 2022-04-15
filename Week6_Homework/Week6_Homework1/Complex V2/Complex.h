#pragma once
#include <cstdio>
struct Complex {
	double real;
	double imag;
};
inline void setComplex(Complex &c, double r, double i) {
	c.real = r;
	c.imag = i;
};
extern Complex readComplex(const char* msg = "º¹¼Ò¼ö =");
extern void printComplex(Complex c,const char* msg = "º¹¼Ò¼ö =");
extern Complex addComplex(Complex a, Complex b);
