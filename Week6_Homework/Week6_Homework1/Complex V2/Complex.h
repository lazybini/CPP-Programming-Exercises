#pragma once
#include <cstdio>
class Complex		// 데이터 멤버. 모두 private으로 선언됨
{
	double real;
	double imag;
public:
	void setComplex(double r, double i) {		// inlind으로 구현도니 멤버 함수. 매개변수가 하나 줄고, 코드도 단순해짐
		real = r;
		imag = i;
	}
	void readComplex(char* msg = " 복소수 = ");	// 멤버 함수들
	void printComplex(char* msg = "복소수 = ");
	void addComplex(Complex a, Complex b);
};