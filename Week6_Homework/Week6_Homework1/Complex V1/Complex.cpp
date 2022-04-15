#include "Complex.h"
Complex readComplex(const char* msg) {			// ���Ҽ� ��ü �Է� �Լ�
	Complex c;
	printf(" %s ", msg);
	scanf_s("%lf%lf", &c.real, &c.imag);
	return c;
}
void printComplex(Complex c,const char* msg) {	// ���Ҽ� ��ü ��� �Լ�
	printf(" %s %4.2f + %4.2fi\n", msg, c.real, c.imag);
}
Complex addComplex(Complex a, Complex b) {
	Complex c;
	c.real = a.real + b.real;
	c.imag = a.imag + b.imag;
	return c;
}