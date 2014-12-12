#include <iostream>
#include <string>
#include <fstream>
#include "Notecard.h"
using namespace std;

Notecard::Notecard(string word, string def) {
	_word = word;
	_def = def;
}

void Notecard::addWord(string word) {
	_word = word;
}

void Notecard::addDef(string def) {
	_def = def;
}

string Notecard::getWord() {
	return _word;
}

string Notecard::getDef() {
	return _def;
}

string Notecard::getCard() {
	string s = _word + " - " + _def;
	return s;
}