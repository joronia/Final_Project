#include "Notecard.h"
#include "MakeDeck.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

/*void outputuser() {
	string user;
	cout << "Enter the file you want to write in?" << endl;
	cin >> user;
	cout << endl;
	fstream creatingflash;
	creatingflash.open(user, ios::app);
	cin.ignore();

	if (creatingflash.fail()) {
		cout << "Can't open file!" << endl;
	}

	cout << "type 'imdone' when finished" << endl;

	string word;
	string def;
	do {
		cout << "Enter word / phrase" << endl;
		getline(cin, word);
		//exits
		if (word == "imdone") 
			break;
		cout << "Enter definition" << endl;
		getline(cin, def);
		creatingflash << word << endl;
		creatingflash << def << endl;
	} while (def != "imdone");

	creatingflash.close();
}*/

void readDeckNames();

void outputUser(int x) {
	// new entry
	if (x == 1) {
		cout << "What do you want to name this deck?" << endl;
	}
	// appending a deck
	if (x == 2) {
		cout << "Which deck do you want to add to?\n";
		readDeckNames();
	}

	string user;
	cin >> user;
	cout << endl;

	// Adds the deck name given to the deck list on new entry
	if (x == 1) {
		ofstream fout("decklist.txt", ios::app);
		fout << endl << user;
	}

	string usert = user + ".txt";
	fstream creatingflash;
	creatingflash.open(usert, ios::app);
	cin.ignore();

	if (creatingflash.fail()) {
		cout << "Can't open file!" << endl;
	}

	cout << "type \"endinput\" when finished" << endl;

	string word;
	string def;
	do {
		cout << "Enter word / phrase" << endl;
		getline(cin, word);
		//exits
		if (word == "endinput") 
			break;
		cout << "Enter definition" << endl;
		getline(cin, def);
		creatingflash << word << endl;
		creatingflash << def << endl;
	} while (def != "endinput");

	creatingflash.close();

}

void readDeckNames() {
	ifstream fin("decklist.txt");
	while(!fin.eof()) {
		string fileName;
		getline(fin, fileName);
		cout << fileName << endl;
	}
	fin.close();
}