#ifndef HERO_H
#define HERO_H

#include <string>
#include <conio.h>
#include <iostream>
#include <Point.h>

using namespace std;


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
	int getX();
	int getY();
	point getLoc();
private:
	string name;
	int luck, strength, magic, skillpoints;
	point tempBack, location;
	bool hp, moved;
	BattleField* pole;
	void move(int x, int y);
	void back();
	bool useTrigger();
};

#endif // !HERO_H
