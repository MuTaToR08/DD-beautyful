#include "Game.h"
#include "battlefield.h"
#include "Hero.h"

void Game::init()
{

	{
		//int button1 = _getch();
		//cout << "1: " << (int)button1;
		GamePole = new BattleField();
		Player = new Hero();
		Player->setPole(GamePole);
		GamePole->addPlayer(Player);
		tutorial(Player);
		//midgame(char1);
	}
}

void Game::tutorial(Hero *& char1)

{
	cout << "Welcome to the budget version of the Scrapyard!\n\n";
	cout << "For now, you will create a hero, smart and brave as CSKA fan.\n\n";
	string name = "";
	while (name.size() == 0)
	{
		cout << "Please, introduce yourself\n\n";
		getline(cin, name);
	}
	char1->changename(name);
	cout << "\nThank you, " << name << "!\nNow press any key to go to the next screen.\n\n";
	system("pause");
	system("cls");
	cout << "Your character has 3 primary attributes:\nMagic, responsible for spell power\n\nStrength, used for melee attacks\n\nLuck, which lets you find more loot, escape form tricky traps\nor even came back from hell for one more match! \n\n";
	system("pause");
	cout << "\nNow u have to spread your skill points\n\n";
	cout << "Do you want to do it randomly? (y/n)";
	cout << "\nIn other case, you will have to do it by yourself\n\n";
	while (1)
	{
		int input;
		input = _getch();
		switch (input)
		{
		case 121:
			char1->random();
			break;
		case 110:
			system("cls");
			char1->self();
			break;
		}
		if (input == 121 || input == 110) break;
		cout << "(y/n)\n";
	}
	char1->stat();
}