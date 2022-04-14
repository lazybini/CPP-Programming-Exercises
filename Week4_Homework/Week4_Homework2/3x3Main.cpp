#include "Ranking.h"
extern int playEightPuzzle();
void main()
{
	loadRanking("ranking.txt");
	int rank = playEightPuzzle();
	printRanking();
	storeRanking("ranking.txt");
}
