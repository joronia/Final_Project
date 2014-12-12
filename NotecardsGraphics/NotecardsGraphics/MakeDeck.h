#ifndef __DECK_H__
#define __DECK_H__
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Notecard.h"
#include "stdafx.h"
using namespace std;

class Deck {
private:
	vector<Notecard> _deck;

public:
	Deck(string);

	void addCard(Notecard);

	void addCard(string, string);

	void removeCard(int);

	Notecard getCard(int);

	int getSize();
};

#endif