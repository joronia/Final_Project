#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "MakeDeck.h"
#include "Notecard.h"
using namespace std;

Deck::Deck(string deckName) {
	string txt = deckName + ".txt";
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
	if (x != _deck.size() - 1) {
		for (x; x < _deck.size() - 1; x++) {
			_deck.at(x) = _deck.at(x + 1);
		}
	}
	_deck.pop_back();
}
void Deck::removeCard(string card) {
	int i = removeCard(_deck.size(), card);
	if (i == -1) {
		cout << "The card you entered was not found\n";
	} else {
		removeCard(i);
		cout << "Card was successfully removed\n";
	}
}
int Deck::removeCard(int x, string card) {
	// card was found
	if (_deck.at(x).getWord() == card) {
		return (_deck.size() - x);
	}
	// card was not found
	if (x == 0) {
		return -1;
	}
	return removeCard(x - 1, card);
}

Notecard Deck::getCard(int x) {
	return _deck.at(x);
}
int Deck::getSize() {
	return _deck.size();
}

void Deck::showDeck() {
	for (int i = 0; i < _deck.size() - 1; i++) {
		cin.get();
		cout << getCard(i).getWord();
		cin.get();
		cout << getCard(i).getDef() << endl;
	}
}

void Deck::shuffle() {
	srand(time(NULL));
	shuffle(_deck.size());
	_deck = _temp;
	_temp.clear();
}
void Deck::shuffle(int x) {
	int r = rand() % x;
	_temp.push_back(_deck.at(r));
	removeCard(r);
	if (x > 1) { shuffle(x - 1); }
}