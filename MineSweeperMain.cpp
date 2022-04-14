#include "MineSweeper.h"
int main()
{
	int total;
	printf(" <Mine Sweeper>\n");
	printf(" 매설할 총 지뢰의 개수 입력 : ");
	scanf_s("%d", &total);
	playMineSweeper(total);
}