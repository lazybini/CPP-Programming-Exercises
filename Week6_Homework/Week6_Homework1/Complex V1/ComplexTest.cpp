#include "Complex.h"
void main()
{
	Complex a, b, c;			// Complex ��ü ����
	a = readComplex("A =");		// ���Ҽ� ��ü a�� b�� ���� �Է�
	b = readComplex("B =");
	c = addComplex(a, b);		// ���Ҽ� ���� ���� c = a + b
	printComplex(a, " A = ");	// ���Ҽ� ��ü ���
	printComplex(b, " B = ");
	printComplex(c, " C = ");
} // lazybini@github.com