#include "Ranking.h"
extern int play5x5Puzzle();
void main()
{
	loadRanking("ranking.txt");
	int rank = play5x5Puzzle();
	printRanking();
	storeRanking("ranking.txt");
}