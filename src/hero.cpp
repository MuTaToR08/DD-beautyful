#include "../include/Hero.h"
#include <iostream>
#include <ctime>
#include <conio.h>
#include "../include/BattleField.h"
using namespace std;

Hero::Hero()
{
	name = ("");
	strength = 0;
	magic = 0;
	luck = 0;
	skillpoints = 10;
	hp = true;
	//this->pole = arena;
}
void Hero::move(Hero char1,int x, int y)
{
	if (!this->pole->checkroom(x, y))
		return;
	moved = true;
	tempBack = location;
	location.posX = x;
	location.posY = y;
	this->pole->MoveHero();
	if (this->useTrigger())
	{
		// u do shit
	}
	else
	{
		this->back();
	}
	moved = false;
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
void Hero::stat()
{
	cout << "Hello, "<< this->name<<"\nNow you have:\n" << "Strength: " <<this->strength <<"\nMagic: " <<this->magic <<"\nLuck: " <<this->luck<<"\n\n";
}
void Hero::changename(string a)
{
	this->name = a;
}
void Hero::setPole(BattleField * pbatle)
{
	pole = pbatle;
}
void Hero::back()
{
	if (moved)
		pole->BackMoveHero();
}