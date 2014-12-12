#include "Notecard.h"
#include "MakeDeck.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void outputuser() {
	string user;
	cout << "Enter the file you want to write in?" << endl;
	cin >> user;
	cout << endl;
	fstream creatingFlash;
	creatingFlash.open(user, ios::app);
	cin.ignore();

	if (creatingFlash.fail()) {
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
		creatingFlash << word << endl;
		creatingFlash << def << endl;
	} while (def != "imdone");

	creatingFlash.close();
}