#include "Game.h"
#include "Hero.h"
#include "Battlefield.h"

int main()
{
	//int button1 = _getch();
	//cout << "1: " << (int)button1;
	Game *MainGame = new Game();
	MainGame->init();
	MainGame->midgame();
	system("pause");
	return 0;
}