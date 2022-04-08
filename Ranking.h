#include <cstdio>

struct PlayInfo {
	char	name[200];		
	int		nMove;			
	double	tElapsed;	
};
extern void loadRanking(const char* filename);
extern void storeRanking(const char* filename);
extern void printRanking();
extern void addRanking(int nMove, double tElap);