// ��� ��� �Լ��� ���� ������(::)�� �����. ��� Complex Ŭ������ ��� �Լ����� ��Ÿ��
#include "Complex.h"	
void Complex::readComplex(char* msg) {				// ��ȯ���� void�� �ٲ�. scanf()�� �μ��� �ܼ�����
	printf(" %s ", msg);
	scanf("%lf%lf", &real, &imag);
}
void Complex::printComplex(char* msg) {				// �Ű������� �پ��. ���� real, imag ���
	printf(" %s %4.2f + %4.2fi\n", msg, real, imag);
}
void Complex::addComplex(Complex a, Complex b) {	// ��ȯ���� void�� �ٲ�. ���� real, imag ���
	real = a.real + b.real;
	imag = a.imag + b.imag;
}