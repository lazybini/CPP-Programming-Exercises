// 모든 멤버 함수에 범위 연산자(::)가 적용됨. 모두 Complex 클래스의 멤버 함수임을 나타냄
#include "Complex.h"	
void Complex::readComplex(char* msg) {				// 반환형이 void로 바뀜. scanf()의 인수가 단순해짐
	printf(" %s ", msg);
	scanf("%lf%lf", &real, &imag);
}
void Complex::printComplex(char* msg) {				// 매개변수가 줄어듦. 직접 real, imag 사용
	printf(" %s %4.2f + %4.2fi\n", msg, real, imag);
}
void Complex::addComplex(Complex a, Complex b) {	// 반환형이 void로 바뀜. 직접 real, imag 사용
	real = a.real + b.real;
	imag = a.imag + b.imag;
}