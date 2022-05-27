#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include <time.h>

void main()
{
	srand((unsigned int)time(NULL));
	int w = 16, h = 8;
	MonsterWorld game(w, h);

	game.add(new Zombie("±è°æ´ö", "¡Ý", rand() % w, rand() % h));
	game.add(new Vampire("±è°»µæ", "¡Ú", rand() % w, rand() % h));
	game.add(new KGhost("±è°æµ¶", "¢¾", rand() % w, rand() % h));
	game.add(new Jiangshi("±è°æµæ", "¡ê", rand() % w, rand() % h, true));
	game.add(new Jiangshi("±è¿µ´ö", "¢Õ", rand() % w, rand() % h, false));
	game.add(new Human	("±è¸¸´ö", "¡Ï", rand() % w, rand() % h));
	game.play(500, 10);
	printf("------°ÔÀÓ Á¾·á-------------------\n");
	getchar();
	getchar();
}