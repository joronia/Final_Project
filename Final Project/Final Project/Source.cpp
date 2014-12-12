#include "Notecard.h"
#include "MakeDeck.h"
#include "AddDeck.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void welcome();
void menu();

int main() {
	welcome();
	menu();
	/*string answerOne;
	cout << "do you want to add a deck? (yes/no)\n";
	cin >> answerOne;
	if (answerOne == "yes") {
		outputUser(1);
	}

	string answerTwo;
	cout << "do you want to study a deck? (yes/no)" << endl;
	cin >> answerTwo;
	if(answerTwo == "yes") {
		cout << "which deck?\n";
		string deck;
		cin >> deck;
		Deck m(deck);
		for (int i = 0; i < m.getSize() - 1; i++) {
			cin.get();
			cout << m.getCard(i).getWord();
			cin.get();
			cout << m.getCard(i).getDef() << endl;
		}
	}*/
}
void welcome() {
	cout << "Welcome to FlashCards+, we hope you enjoy the program" << endl << endl;
}

void menu() {
	// user's answer
	string a;
	while (a != "e" && a != "E") {
		cout << "What do you want to do?\n1 - Add a new deck\n2 - Add to an existing deck\n3 - Use a deck\nE - Exit\n";
		getline(cin, a);
		if (a == "1") {
			outputUser(1);
		} else if (a == "2") {
			outputUser(2);
		} else if (a == "3") {
			cout << "Which deck do you want to use?\n";
			readDeckNames();
			string deck;
			getline(cin, deck);
			Deck m(deck);
			string b;
			while (b != "e" && b != "E") {
				cout << "What would you like to do?\n1 - Begin\n2 - Shuffle\n3 - Remove card\nE - Exit\n";
				getline(cin, b);
				if (b == "1" || b == "begin") {
					m.showDeck();
				} else if (b == "2" || b == "shuffle") {
					m.shuffle();
					m.showDeck();
				} else if (b == "3" || b == "remove card") {
					cout << "Enter the card you would like removed from this deck: ";
					cin >> b;
					m.removeCard(b);
				}
			}
		}
	}
}