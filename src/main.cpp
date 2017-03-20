//#include "tutorial.h"
#include "Game.h"
#include "Hero.h"
//#include "midgame.h"
#include "Battlefield.h"

int main()
{
	Game *MainGame = new Game();
	MainGame->init();
	
	system("pause");
	return 0;
}