#ifndef HERO_H
#define HERO_H

#include <string>
#include <conio.h>
#include <iostream>

using namespace std;

struct point
{
	int posX;
	int posY;
};

class BattleField;

class Hero 
{
public:
	Hero( );
	void random();
	void self();
	void stat();
	void changename(string);
	void setPole(BattleField*);
	void up();
	void down();
	void left();
	void right();
private:
	string name;
	int luck, strength, magic, skillpoints;
	point tempBack, location;
	bool hp, moved;
	BattleField* pole;
	void move(Hero char1,int x, int y);
	void back();
	bool useTrigger()
	{
		while (1)
		{
			cout << "Use trigger?";
			int input = _getch();
			switch (input)
			{
			case 121:
				// u do shit
				return true;
			case 110:
				return false;
			}
			if (input == 121 || input == 110) break;
			cout << "(y/n)\n";
		}
		return false;
	}
};

#endif // !HERO_H
