#ifndef __NOTECARD_H__
#define __NOTECARD_H__
#include <iostream>
#include <string>
#include <fstream>
#include "stdafx.h"
using namespace std;

class Notecard {
private:
	string _word;
	// definition
	string _def;

public:
	Notecard(string, string);

	void addWord(string);

	void addDef(string);

	string getWord();
	
	string getDef();

	string getCard();
};

#endif