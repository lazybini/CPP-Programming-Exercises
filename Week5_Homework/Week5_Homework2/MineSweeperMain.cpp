#include "MineSweeper.h"
void main()
{
	int width, height, total;
	printf(" <Mine Sweeper>\n");
	printf(" ���ڸ��� ũ�� �Է�(���� ����) : ");
	scanf_s("%d%d", &width, &height);
	printf(" �ż��� �� ������ ���� �Է� : ");
	scanf_s("%d", &total);

	playMineSweeper(width, height, total);
}