#include "Ranking.h"
#include <Windows.h>  
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#define DIM 5

int flag;
double tElap = 0;
double d;
void SaveGame(char* filename);

enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };
static int DirKey[4] = { Left,Right,Up,Down };
static int map[DIM][DIM];
static int x, y;
static int nMove;
static clock_t tStart;

static void init()
{
	for (int i = 0; i < DIM * DIM - 1; i++)
	{
		map[i / DIM][i % DIM] = i + 1;
	}
	map[DIM - 1][DIM - 1] = 0;
	x = DIM - 1; y = DIM - 1;

	srand(time(NULL));
	tStart = clock();
	nMove = 0;

}
static void display()
{

	system("cls");
	printf("\n \n");
	printf("\t5x5 Puzzle\n\t");
	printf("-------------------\n\t");
	for (int r = 0; r < DIM; r++) {
		for (int c = 0; c < DIM; c++) {
			if (map[r][c] > 0)
				printf("%3d", map[r][c]);
			else
				printf(" ");
		}
		printf("\n\t");
	}
	printf("-------------------\n\t");
	clock_t t1 = clock();

	if (flag == 0)
	{
		d = double(t1 - tStart) / CLOCKS_PER_SEC;
		printf("\n\t 이동횟수:%6d\n\t소요시간:%6.1lf\n\n", nMove, d);
	}
	if (flag == 1)
	{
		d = (double(t1 - tStart) / CLOCKS_PER_SEC) + tElap;
		printf("\n\t 이동횟수:%6d\n\t소요시간:%6.1lf\n\n", nMove, d);
	}
}
static bool move(int dir)
{
	if (dir == Right && x > 0)
	{
		map[y][x] = map[y][x - 1];
		map[y][--x] = 0;
	}
	else if (dir == Left && x < DIM - 1)
	{
		map[y][x] = map[y][x + 1];
		map[y][++x] = 0;
	}
	else if (dir == Up && y < DIM - 1)
	{
		map[y][x] = map[y + 1][x];
		map[++y][x] = 0;
	}
	else if (dir = Down && y > 0)
	{
		map[y][x] = map[y - 1][x];
		map[--y][x] = 0;
	}
	else return false;

	nMove++;
	return true;
}
static void shuffle(int nShuffle)
{
	for (int i = 0; i < nShuffle; i++)
	{
		int key = DirKey[rand() % 4];
		if (move(key) == false)
		{
			i--;
			continue;
		}
		display();
		Sleep(50);
	}
}
static bool isDone()
{
	for (int r = 0; r < DIM; r++)
	{
		for (int c = 0; c < DIM; c++)
		{
			if (map[r][c] != r * DIM + c + 1)
				return (r == DIM - 1) && (c == DIM - 1);
		}
	}
	return true;
}
static int getDirKey()
{
	return _getche() == 224 ? _getche() : 0;
}
static int getSaveKey()
{
	if (_getch() == 48)
	{
		printf("\n 게임을 저장하고 종료합니다...");
		SaveGame((char*)"SaveGame.txt");
		exit(0);
	}
	else if (_getch() == 224)
	{
		int key = getDirKey();
		return key;
	}
}
int playFifteenPuzzle() {
	init();
	display();
	printRanking();
	printf("\n 퍼즐을 섞어주세요(엔터)...");
	_getche();
	shuffle(50);
	printf("\n 게임이 시작됩니다...");
	_getche();

	nMove = 0;
	tStart = clock();
	while (!isDone()) {
		move(getDirKey());
		display();
	}
	clock_t t1 = clock();
	double d = (double)(t1 - tStart) / CLOCKS_PER_SEC;
	return addRanking(nMove, d);
}

// replay
static int mapTmp[DIM][DIM];
static int history[1000];
static int nHist = 0, _x, _y;

void backupInitMap(bool backup = true)
{
	if (backup)
	{
		for (int r = 0; r < DIM; r++)
		{
			for (int c = 0; c < DIM; c++)
			{
				mapTmp[r][c] = map[r][c];
			}
		}
		_x = x;
		_y = y;
	}
	else
	{
		for (int r = 0; r < DIM; r++)
		{
			for (int c = 0; c < DIM; c++)
			{
				map[r][c] = mapTmp[r][c];
			}
		}
		x = _x;
		y = _y;
	}
}
//  game save
static int mapPresent[DIM][DIM];

void SaveGame(char* filename)
{
	FILE* wp;
	fopen_s(&wp, filename, "w");

	for (int r = 0; r < DIM; r++)
	{
		for (int c = 0; c < DIM; c++)
		{
			mapPresent[r][c] = map[r][c];
			fprintf(wp, "%3d\n", mapPresent[r][c]);
		}
	}

	fprintf(wp, "%d\n", nMove);
	fprintf(wp, "%lf\n", d);
	fprintf(wp, "%d\n", x);
	fprintf(wp, "%d\n", y);
	fprintf(wp, "%d\n", nHist);

	for (int c = 0; c < nHist; c++)
	{
		fprintf(wp, "%3d\n", history[c]);
	}
	for (int r = 0; r < DIM; r++)
	{
		for (int c = 0; c < DIM; c++)
		{
			fprintf(wp, "%3d\n", mapTmp[r][c]);
		}
	}
	fprintf(wp, "%d\n", _x);
	fprintf(wp, "%d\n", _y);
	fclose(wp);
}

// game restart
void RestartSaveGame(char* filename)
{
	FILE* rp;
	fopen_s(&rp, filename, "r");

	if (rp == NULL)
	{
		printf(" 저장된 게임이 없습니다!!!");
		exit(0);
	}

	for (int r = 0; r < DIM; r++)
	{
		for (int c = 0; c < DIM; c++)
		{

			fscanf_s(rp, "%3d", &(map[r][c]));
		}
	}

	fscanf_s(rp, "%d", &nMove);
	fscanf_s(rp, "%lf", &tElap);
	fscanf_s(rp, "%d", &x);
	fscanf_s(rp, "%d", &y);
	fscanf_s(rp, "%d", &nHist);

	for (int c = 0; c < nHist; c++)
	{
		fscanf_s(rp, "%3d", &(history[c]));
	}
	for (int r = 0; r < DIM; r++)
	{
		for (int c = 0; c < DIM; c++)
		{
			fscanf_s(rp, "%3d\n", &(mapTmp[r][c]));
		}
	}

	fscanf_s(rp, "%d", &_x);
	fscanf_s(rp, "%d", &_y);
	fclose(rp);
}
int play5x5Puzzle()
{
	printf("\n 이전 게임을 이어서 하겠습니까?( yes==>1, no==>0) :");
	scanf_s("%d", &flag);
	if (flag == 0)
	{
		init();
		display();
		printf("\n 퍼즐을 섞어주세요(엔터)...");
		_getche();
		shuffle(50);

		backupInitMap();

		printf("\n 게임이 시작됩니다...");
		_getche();

		nMove = 0;
		nHist = 0;
		tStart = clock();
	}
	else if (flag == 1)
	{
		RestartSaveGame((char*)"SaveGame.txt");

		tStart = clock();
		display();
	}
	while (!isDone())
	{
		history[nHist] = getSaveKey();
		move(history[nHist]);
		display();
		nHist++;
	}

	double end_time = d;

	printf("\n Replay...");
	_getche();
	init();
	backupInitMap(false);
	display();
	printf("\n 엔터키를 눌러주세요...");
	_getche();

	for (int i = 0; i < nHist; i++)
	{
		move(history[i]);
		display();
		Sleep(200);
	}
	return addRanking(nMove, end_time);
}