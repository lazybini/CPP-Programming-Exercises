#include "Complex.h"
void main()
{
	Complex a, b, c;			// Complex 객체 생성
	a = readComplex("A =");		// 복소수 객체 a와 b의 정보 입력
	b = readComplex("B =");
	c = addComplex(a, b);		// 복소수 덧셈 연산 c = a + b
	printComplex(a, " A = ");	// 복소수 객체 출력
	printComplex(b, " B = ");
	printComplex(c, " C = ");
} // lazybini@github.com