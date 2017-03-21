#pragma once
#include "Hero.h"
#include "BattleField.h"

class Game
{
private :
	BattleField* GamePole;
	Hero* Player;
public :
	void init();
	void tutorial(Hero*& char1);
	void midgame();
};