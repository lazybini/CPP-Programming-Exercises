#pragma once
#include <cstdio>
class Complex		// ������ ���. ��� private���� �����
{
	double real;
	double imag;
public:
	void setComplex(double r, double i) {		// inlind���� �������� ��� �Լ�. �Ű������� �ϳ� �ٰ�, �ڵ嵵 �ܼ�����
		real = r;
		imag = i;
	}
	void readComplex(char* msg = " ���Ҽ� = ");	// ��� �Լ���
	void printComplex(char* msg = "���Ҽ� = ");
	void addComplex(Complex a, Complex b);
};