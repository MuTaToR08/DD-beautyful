#include "Game.h"
#include "BattleField.h"
#include "Hero.h"

void Game::init()
{
	GamePole = new BattleField();
	Player = new Hero();

	Player->setPole(GamePole);
	GamePole->addPlayer(Player);
	tutorial(Player);
	midgame();
}

void Game::tutorial(Hero *& char1)
{
	cout << "Welcome to the budget version of the Scrapyard!" << endl << endl;
	cout << "For now, you will create a hero, smart and brave as CSKA fan." << endl << endl;

	string name = "";
	bool flag = true;

	while (name.size() == 0)
	{
		cout << "Please, introduce yourself" << endl << endl;
		getline(cin, name);
	}

	char1->changeName(name);

	cout << endl << "Thank you, " << name << "!"
		<< endl << "Now press any key to go to the next screen." << endl << endl;

	system("pause");
	system("cls");

	cout << "Your character has 3 primary attributes:"
		<< endl << "Magic, responsible for spell power" << endl << endl
		<< "Strength, used for melee attacks" << endl << endl
		<< "Luck, which lets you find more loot, escape form tricky traps" << endl
		<< "or even came back from hell for one more match!" << endl << endl;
	system("pause");

	cout << endl << "Now u have to spread your skill points" << endl << endl;
	cout << "Do you want to do it randomly? (y/n)";
	cout << endl << "In other case, you will have to do it by yourself" << endl << endl;


	while (flag)
	{
		int input;
		input = _getch();
		cout << "(y/n)" << endl;
		switch (input)
		{
		case 121:
			char1->random();
			flag = false;
			break;
		case 110:
			system("cls");
			char1->self();
			flag = false;
		}
	}

	char1->stat();
}

void Game::midgame()
{
	system("cls");
	cout << "Our story began, when you got stacked in a strange hallway" << endl;
	cout << "Well, probably you have to find an exit first, looks simple" << endl << endl;

	int input;
	GamePole->showfield();

	while (1)
	{
		input = _getch();
		switch (input)
		{
		case 72: // вверх
			Player->up();
			break;
		case 80: //влево
			Player->down();
			break;
		case 75: //вниз
			Player->left();
			break;
		case 77: //вправо
			Player->right();
			/*case 115:
			{
				char1->stat();
				system("pause");
				break;
			}
			case 104:
			{
				char1->rules();
				system("pause");
				break;
			}
			case 99:
			{
				arena.commands();
				system("pause");
				break;
			}
			case 109:
			{
				arena.minimap();
				system("pause");
				break;
			}*/
		}

		system("cls");
		GamePole->showfield();
	}
}