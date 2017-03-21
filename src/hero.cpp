#include "Hero.h"
#include "BattleField.h"

#include <iostream>
#include <ctime>
#include <conio.h>

using namespace std;

Hero::Hero() :name(""), strength(0), magic(0),
luck(0), skillpoints(10), hp(true)
{}

void Hero::setPole(BattleField * pbatle)
{
	pole = pbatle;
}


//TUTORIAL
void Hero::changeName(string a)
{
	this->name = a;
}

void Hero::random()
{
	system("cls");
	srand((unsigned int)time(NULL));

	int tmp;

	while (0 < this->skillpoints)
	{
		tmp = rand() % 3;
		switch (tmp)
		{
		case 0:
			this->strength += 1;
			break;
		case 1:
			this->magic += 1;
			break;
		case 2:
			this->luck += 1;
			break;
		}
		skillpoints--;
	}
}

void Hero::self()
{

	while (0 < this->skillpoints)
	{
		system("cls");
		cout << "Now you have " << skillpoints << " skillpoints" << endl;

		cout << "Enter the number to upgrade your skill:" << endl
			 << "s is for strength, l is for luck, m is for magic" << endl << endl;
		cout << "Ok, now you have:" << endl 
			 << strength << " strength" << endl 
			 << magic << " magic" << endl
			 << luck << " luck" << endl 
			 << "Skillpoints left:" << skillpoints << endl << endl;

		int input;
		input = _getch();
		switch (input)
		{
		case 115:
			this->strength += 1;
			break;
		case 109:
			this->magic += 1;
			break;
		case 108:
			this->luck += 1;
			break;
		default:
			continue;
		}
		skillpoints--;
	}

	cout << "Distribution of skill points has been done perfectly!"<<endl;
}

bool Hero::useTrigger()
{
	bool flag;

	while (1)
	{
		cout << "Use trigger?";
		int input = _getch();
		switch (input)
		{
		case 121:
			return true;
		case 110:
			return false;
		}
		cout << "(y/n)\n";
	}
	return false;
}

//MOVE ACTIONS
void Hero::move(int x, int y)
{
	if (!this->pole->checkRoom(x, y))
		return;

	moved = true;
	tempBack = location;
	location.posX = x;
	location.posY = y;
	
	bool checkedTriger = this->pole->checkTrigger();
	this->pole->MoveHero();
	
	if (checkedTriger)
		if (this->useTrigger())
		{
			this->pole->trigger();
		}
		else
		{
			this->back();
			location = tempBack;
		}

	moved = false;
}

void Hero::up()
{
	move(this->location.posX - 1, this->location.posY);
}

void Hero::down()
{
	move(this->location.posX + 1, this->location.posY);
}

void Hero::left()
{
	move(this->location.posX, this->location.posY - 1);
}

void Hero::right()
{
	move(this->location.posX, this->location.posY + 1);
}

void Hero::back()
{
	if (moved)
		this->pole->BackMoveHero();
}

/*SHOW OFF*/
void Hero::stat()
{
	cout << "Hello, " << this->name << "\nNow you have:\n" << "Strength: " << this->strength << "\nMagic: " << this->magic << "\nLuck: " << this->luck << "\n\n";
}

int Hero::getX()
{
	return this->location.posX;
}

int Hero::getY()
{
	return this->location.posY;
}

int Hero::getLX()
{
	return this->tempBack.posX;
}

int Hero::getLY()
{
	return this->tempBack.posY;
}