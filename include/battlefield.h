#pragma once

#define SIZE 6

class Hero;

class BattleField
{
private:
	char field[SIZE][SIZE];
	Hero* players;
public:
	BattleField();
	BattleField& BattleField::operator=(BattleField&);
	bool checkRoom(int, int);
	void showfield();
	void MoveHero();
	void BackMoveHero();
	void rules();
	void commands();
	void minimap();
	void addPlayer(Hero*);
	void trigger();
	bool checkTrigger();
	bool checkTrigger(int, int);
};