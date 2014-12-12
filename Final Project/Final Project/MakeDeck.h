#ifndef __DECK_H__
#define __DECK_H__
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Notecard.h"
using namespace std;

class Deck {
private:
	vector<Notecard> _deck;
	vector<Notecard> _temp;

	int removeCard(int, string);
	void shuffle(int);

public:
	Deck(string);

	void addCard(Notecard);
	void addCard(string, string);

	void removeCard(int);
	void removeCard(string);

	Notecard getCard(int);
	int getSize();

	void showDeck();

	void shuffle();
};

#endif