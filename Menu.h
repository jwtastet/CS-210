#pragma once
#ifndef MENU_H
#define MENU_H
#include <string>

using namespace std;

class Menu
{
	public:
		//default constructor
		Menu();
		//prints the display
		void PrintMenu();
		//accessors 
		int GetMenuOption();
		string GetMenuDisplay();
		//mutators
		void ChooseMenuOption();
		void SetMenuOption(int);
		

	private:
		//menu display
		string display;
		//selectable menu option
		int menuOption;

};

#endif