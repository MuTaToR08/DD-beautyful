#include <Game.h>
#include <BattleField.h>
#include <Hero.h>

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

void Game::midgame()
{
	system("cls");
	cout << "Out story began, when you got stacked in a strange hallway\n";
	cout << "Well, probably you have to find an exit first, looks simple\n\n";
	int index1 = 0, index2 = 0;
	int input;
	while (1)
	{
		cout << "where?\n";
		input = _getch();
		switch (input)
		{
		case 72: // вверх
			if (index1 > 0)
				Player->up();
			break;
		case 80: //влево
			if (index1 < SIZE - 1)
				Player->down();
			break;
		case 75: //вниз
			if (index2 > 0)
				Player->left();
			break;
		case 77: //вправо
			Player->right();
			break;
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
		cout << Player->getX() << Player->getX();
		point k =  Player->getLoc();
		cout << k.posX << k.posY;
	}
}