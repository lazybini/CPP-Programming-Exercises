#include "Ranking.h"
extern int play3x3Puzzle();
void main()
{
	loadRanking("ranking.txt");
	int rank = play3x3Puzzle();
	printRanking();
	storeRanking("ranking.txt");
}