#include "Game.h"
#include "Hero.h"
#include "Battlefield.h"

int main()
{
	Game *MainGame = new Game();
	MainGame->init();
	MainGame->midgame();
	system("pause");
	return 0;
}