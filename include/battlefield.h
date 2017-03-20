#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H
#define SIZE 6

class Hero;

class BattleField
{
private:
	char field[SIZE][SIZE];
	Hero* players;
public:
	BattleField();
	BattleField& BattleField::operator=(BattleField& bf);

	bool checkroom(int index1, int index2);
	void showfield();
	void setroom(int index1, int index2);
	void delroom(int index1, int index2);
	void setpos(int index1, int index2);
	void MoveHero();
	void BackMoveHero();
	void rules();
	void commands();
	void minimap();
	void addPlayer(Hero*);
};
/*

class BattleField
{
	BattleField() {};
	
private:
	char field[SIZE][SIZE];
public:
	//battlefield& battlefield::operator=(battlefield& bf);
	BattleField();
	bool checkroom(int index1, int index2);
	void showfield();
	void setroom(int index1, int index2);
	void delroom(int index1, int index2);
	void setpos(int index1, int index2);
	void MoveHero();
	void BackMoveHero();
	void rules();
	void commands();
	void minimap();//
};
*/
#endif