/* 
	Name: Joseph Tastet
	Date: 4/13/2023
	Purpose: To take a file with a list of purchased groceries and convert it to more easily readable data
		in a new file or output.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <iomanip>
#include "Menu.h"

using namespace std;

//initiate menu object
Menu menu;

ifstream inFS; //input file stream
ofstream outFS; //output file stream

//initiate map for items[ key-item name: value-quantity]
map<string, int> items;

//used for temporary variable when extracting data
string item;
//used for temporary variable when selecting individual item for menu option 1
string uniqueItem;

//constant variable to permanently hold the value for closing application
const int QUIT_INT = 4;

//extract data from file
void GetData() {
	//for each item listed in the file, if key:item already exists increase value by 1
	//else create new key:item and value=1
	while (inFS >> item) {
		if (items.count(item)) {
			items[item]++;
		}
		else {
			items.emplace(item, 1);
		}
	}
	//close input file
	inFS.close();
};

//backup the data that was extracted from the file
void BackupData() {
	
	//for each key: value in map items, print "key value" to output file
	for (auto things : items) {
		outFS << things.first << " " << things.second << endl;
	}

	//close output file
	outFS.close();
}

//print each key: value on a new line from map items
void PrintFrequency() {
	for (auto things : items) {
		cout << things.first << " " << things.second << endl;
		
	}
	cout << endl;

}

//print a histogram graph for each key: value from map items
void PrintGraph() {
	//builds each graphic block around each key: value, key is item name, value displayed in equal number of asterisks
	for (auto things : items) {
		cout << "-----------------------------------" << endl;
		string aster(things.second, '*');
		cout << "|" << setw(11) << left << things.first << "|" <<  setw(21) << left << aster << "|" << endl;
	}
	//print the ending block showing what each axis is
	cout << "-----------------------------------" << endl;
	cout << "|   item    |        quantity     |" << endl;
	cout << "-----------------------------------" << endl;
	cout << endl;
}

//print the unique key: value that the user asked for
void PrintUnique() {
	int count = 0;
	cout << "Enter the item you would like to return the count for: ";
	cin >> uniqueItem;
	//checks to see if key exists in map, if so count = value
	if (items.count(uniqueItem) > 0) {
		count = items[uniqueItem];
	}
	//prints "key value"
	cout << uniqueItem << " " << count << endl;
	cout << endl;

}


int main() {
	//open the input file
	inFS.open("CS210_Project_Three_Input_File.txt");

	//error catch for input file opening
	if (inFS.fail()) {
		cout << "Something went wrong, please check the file." << endl;
		return 1;
	}

	//import data from the input file
	GetData();

	//open output file
	outFS.open("Frequency.dat");

	//error catch for the output file opening
	if (outFS.fail()) {
		cout << "Something went wrong backing up teh data" << endl;
		return -1;
	}

	//export data
	BackupData();

	//while the option selected is not 4 keep running app
	while (menu.GetMenuOption() != QUIT_INT) {
		//display menu to user
		menu.PrintMenu();
		//user selects menuOption
		menu.ChooseMenuOption();
		//case for each menuOption
		switch (menu.GetMenuOption()) {
			case 1:
				PrintUnique();
				break;
			case 2: 
				PrintFrequency();
				break;
			case 3:
				PrintGraph();
				break;
			case 4:
				break;
		}
	}

	return 0;
}