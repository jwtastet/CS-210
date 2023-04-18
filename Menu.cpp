#include "Menu.h"
#include <iostream>


using namespace std;

//default constructor, sets display = to menu display and menuOption = 0
Menu::Menu() {
	display = "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n"
			  "|Option [1]: Specific item lookup            |\n"
			  "|Option [2]: Print items and their frequency |\n"
			  "|Option [3]: Print histogram of data         |\n"
			  "|Option [4]: Exit                            |\n"
			  "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|";
	menuOption = 0;
}

//prints the menu display
void Menu::PrintMenu() {
	cout << display << endl;
}

//mutator menuOption
void Menu::SetMenuOption(int option) {
	menuOption = option;
}

//accessor menuOption
int Menu::GetMenuOption() {
	return menuOption;
}

//accessor display
string Menu::GetMenuDisplay() {
	return display;
}

//sets menuOption = to user input
void Menu::ChooseMenuOption() {
	int option = 0;


	do {
		cout << "Select an option from the menu above: ";
		cin >> option;
		//input validation for type other than integer
		if (cin.fail()) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "You must enter a type integer " << endl;
			continue;
		}
		//input validation for an int outside of the accepted range
		else if (option <= 0 || option >= 5) {
			cout << "You must select an option between 1 and 4" << endl;
			continue;
		}
	} while (option <= 0 || option >= 5);

	menuOption = option;
}