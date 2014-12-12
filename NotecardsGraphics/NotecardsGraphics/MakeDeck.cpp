#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "MakeDeck.h"
#include "Notecard.h"
using namespace std;

Deck::Deck(string txt) {
	ifstream fin(txt);

	if (!fin.fail()) {
		string word;
		string def;
		while (!fin.eof()) {
			getline(fin, word);
			getline(fin, def);
			Notecard n(word, def);
			_deck.push_back(n);
		}
	}
	fin.close();
}

void Deck::addCard(Notecard n) {
	_deck.push_back(n);
}

void Deck::addCard(string word, string def) {
	Notecard n(word, def);
	_deck.push_back(n);
}

void Deck::removeCard(int x) {
	for (x; x < _deck.size(); x++) {
		_deck.at(x) = _deck.at(x+1);
	}
	_deck.pop_back();
}

Notecard Deck::getCard(int x) {
	return _deck.at(x);
}

int Deck::getSize() {
	return _deck.size();
}