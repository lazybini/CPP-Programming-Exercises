#include "Ranking.h"
extern int playTwentyFourPuzzle();
void main()
{
	loadRanking("ranking.txt");
	int rank = playTwentyFourPuzzle();
	printRanking();
	storeRanking("ranking.txt");
}