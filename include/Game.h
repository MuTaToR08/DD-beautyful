#pragma once

#include "Hero.h"
#include "BattleField.h"
#include <string>

class Game
{
private :
	BattleField* GamePole;
	Hero* Player;
	string output[255][10];
public :
	void init();
	void tutorial(Hero*& char1);
	void midgame();
};