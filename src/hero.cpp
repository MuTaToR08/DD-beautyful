#include "../include/Hero.h"
#include <iostream>
#include <ctime>
#include <conio.h>
#include "../include/BattleField.h"
using namespace std;

//INITIALISATION

Hero::Hero()
{
	name = ("");
	strength = 0;
	magic = 0;
	luck = 0;
	skillpoints = 10;
	hp = true;
}
void Hero::setPole(BattleField * pbatle)
{
	pole = pbatle;
}


//TUTORIAL

void Hero::changename(string a)
{
	this->name = a;
}
void Hero::random()
{
	system("cls");
	srand((unsigned int)time(NULL));
	int tmp;
	while(0 < this->skillpoints)
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
	cout << "Now you have "<< skillpoints <<" skillpoints\n";
	while (0 < this->skillpoints)
	{
		cout << "Enter the number to upgrade your skill:\ns is for strength, l is for luck, m is for magic\n\n";
		cout << "Ok, now you have:\n" << strength << " strength\n" << magic << " magic\n" << luck << " luck\nSkillpoints left:" << skillpoints << "\n\n";
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
				skillpoints++;
			}
			skillpoints--;
			system("cls");
		system("cls");
	}
	cout << "Distribution of skill points has been done perfectly!\n";
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
			// u do shit
			flag = true;
			break;
		case 110:
			flag = false;
		}
		if (input == 121 || input == 110) break;
		cout << "(y/n)\n";
	}
	return flag;
}

//MOVE ACTIONS

void Hero::move(int x, int y)
{
	if (!this->pole->checkroom(x, y))
		return;
	moved = true;
	tempBack = location;
	location.posX = x;
	location.posY = y;
	this->pole->MoveHero();
	/*if (this->useTrigger())
	{
		this->pole->trigger();
	}
	else
	{
	location = tempBack;
		this->back();
	}*/
	moved = false;
}
void Hero::up() 
{
	int tmp1 = this->location.posX - 1;
	move(tmp1,this->location.posY);
}
void Hero::down() 
{
	int tmp1 = this->location.posX + 1;
	move(tmp1, this->location.posY);
}
void Hero::left()
{
	int tmp1 = this->location.posY - 1;
	move(this->location.posX, tmp1);
}
void Hero::right()
{
	int tmp1 = this->location.posY + 1;
	move(this->location.posX, tmp1);
}
void Hero::back()
{
	
	if (moved)
		this->pole->BackMoveHero();
}

//SHOW OFF

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
point Hero::getLoc()
{
	return this->location;
}
