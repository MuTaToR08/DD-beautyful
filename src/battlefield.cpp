#include "BattleField.h"
#include "Hero.h"
#include <iostream>
#include <conio.h>

using namespace std;

BattleField::BattleField()
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			field[i][j] = '0';

	field[0][0] = 'X';
}

BattleField& BattleField::operator=(BattleField& bf)
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			this->field[i][j] = bf.field[i][j];

	return *this;
}

bool BattleField::checkRoom(int index1, int index2)
{
	bool r = true;

	if (index1 < 0 || index1 >= SIZE ||
		index2 < 0 || index2 >= SIZE)
		r = false;

	return r;
}

void BattleField::showfield()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			std::cout << field[i][j] << " ";
		std::cout << "\n";
	}
}

void BattleField::MoveHero()
{
	system("cls");
	this->field[players->getX()][players->getY()] = 'X';
	this->field[players->getLX()][players->getLY()] = '1';
	this->showfield();
}

void BattleField::rules()
{
	cout << endl << "Welcome to the Scrapyard! Rules are simple:" << endl
		<< "You are stacked in a cube. If you want to quit, you have to find a key first," << endl
		<< "then find an exit. Beware of local mobsters." << endl
		<< "Check rooms, beat the crap out of enemies, gain buffs," << endl
		<< "use pure power and live only once." << endl;
}

void BattleField::commands()
{
	cout << "Use arrows for moving, y/n to select an option" << endl
		<< "press 'h' for fast briefing, 's' for checking stats" << endl
		<< "press 'c' for command list, 'm' for minimap guide" << endl;

}

void BattleField::minimap()
{
	cout << "0 on minimap - unchecked rooms" << endl
		<< "1 - revealed and looted" << endl
		<< "s - your current position" << endl;
}

void BattleField::addPlayer(Hero * player)
{
	players = player;
}

void BattleField::BackMoveHero()
{
	this->field[players->getX()][players->getY()] = '0';
	this->field[players->getLX()][players->getLY()] = 'X';
	this->showfield();
}

void BattleField::trigger()
{
	cout << "1";
}

bool BattleField::checkTrigger()
{
	return (field[this->players->getX()][this->players->getY()] == '0');
}

bool BattleField::checkTrigger(int x, int y)
{
	return (field[x][y] == '0');
}
