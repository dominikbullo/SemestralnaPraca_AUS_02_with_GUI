#include "UI.h"

using namespace std;


UI::UI()
{
	loader = new Nacitanie();
	controller = new Controller(loader->getData());
}


UI::~UI()
{
	delete loader;
	delete controller;
}

void UI::hlavneMenu()
{
	while (running) {
		cout << "++++++++++ Aplikacia na spracovanie volebných výsledkov ++++++++++" << endl;
		cout << "Zvolte si moznost :" << endl << endl <<
			"123\t - TEST" << endl <<
			"111\t - Vynutene ukoncenie" << endl <<
			"0\t - Koniec" << endl <<
			endl;

		switch (getIntInputFromUser("Zvolte si moznost zo zoznamu"))
		{
		case 111:
			// hard exit
			running = false;
			exit(0);
		case 123:
			system("cls");
			cout << "Toto je test." << endl;

			break;
		case 0:
			running = false;
			cout << "Dovidenia." << endl;
			break;
		default:
			cout << "Nespravna volba. " << endl;
		}
	}
}

string UI::getStrInputFromUser(string consoleOutput)
{
	string userInput;
	cout << consoleOutput << ": " << endl;
	cin >> userInput;

	return userInput;
}

int UI::getIntInputFromUser(string consoleOutput)
{
	cout << consoleOutput << ": " << endl;
	int pom;
	cin >> pom;
	while (!cin)
	{
		cout << "Nespravna volba. Zadajte cislo: " << endl;
		cin.clear();
		cin.ignore(numeric_limits < streamsize > ::max(), '\n');
		cin >> pom;
	}
	return pom;
}