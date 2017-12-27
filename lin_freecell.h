/*
 * FreeCell for Linux
 *
 * Author: Anupam Srivastava
 * e-mail: anupam.srivastava@gmail.com
 * 
 * NOTE:
 * 	This program is derived from FreeCell for DOS v 1.1 by me. It was for Turbo C++ v 3.0,
 * 	and used custom libraries. Most of such code is removed and aim of this program is to
 * 	just be compatible with g++. The original program was not throughly checked for bugs.
 * 	Any comments and improvments are invited at anupam.srivastava@gmail.com.
 *
 * 	Indentation is left to Vim editor.
 *
 * LICENSE:
 * 	This program is licensed under GNU GPL v 2.	If you will inform about anyway this
 * 	program was helpful, you will satisfy my narcissistic needs and thus make me happy. ;)
 *
 * TODO:
 * 	1. Add fancyful colours.
 * 	2. Remove any bugs.
 */

#include <ncurses/curses.h>
#include <iostream>
using namespace std;

const char PAN = 'P';
const char EET = 'E';
const char CHIDI = 'C';
const char HUKUM = 'H';

class Card {
  private:
  public:
    int value;
    char face;

	Card() {
		value = -1;
		face = '\0';
	}
	
	Card(int cardValue) {
		value = cardValue;
		face = '\0';
	}

	Card(char cardFace) {
		if (cardFace == PAN
				|| cardFace == EET
				|| cardFace == CHIDI
				|| cardFace == HUKUM) {
			value = -1;
			face = cardFace;
		} else {
			value = cardFace;
			face = '\0';
		}
	}

    Card(int cardValue, char cardFace) {
		value = cardValue;
		face = cardFace;
	}

    void initialize() {
		value = -1;
		face = '\0';
	}

    void modify(int cardValue) {
		value = cardValue;
	}

    void modify(char cardFace) {
		if (cardFace == PAN
				|| cardFace == EET
				|| cardFace == CHIDI
				|| cardFace == HUKUM) {
			face = cardFace;
		} else {
			value = cardFace;
		}
	}

    void modify(int cardValue, int cardFace) {
		value = cardValue;
		face = cardFace;
	}

    int isComplete() {
		if (value != -1 && face != '\0') {
			return 1;
		}
		return 0;
	}
	
	void print() {
		if (value != -1 && face != '\0') {
			if (value > 10) {
				cout << char (value);
			} else {
				cout << int (value);
			}
			cout << char (face);
			if (face == 'P' || face == 'C') {
				cout << " (red)  ";
			} else {
				cout << " (black)";
			}
		} else {
			cout << "        ";
		}
	}
};

int nextToAlternate(Card card1, Card card2) {
	if (((card1.value + 1 == card2.value)
				|| (card1.value == 'A' && card2.value == 2)
				|| (card1.value == 10 && card2.value == 'J')
				|| (card1.value == 'J' && card2.value == 'Q')
				|| (card1.value == 'Q' && card2.value == 'K'))
			&& (((card1.face == PAN || card1.face == CHIDI)
					&& (card2.face == EET || card2.face == HUKUM))
				|| ((card2.face == PAN || card2.face == CHIDI)
					&& (card1.face == EET || card1.face == HUKUM)))) {
		return 1;
	}
	return 0;
}

int nextToSame(Card card1, Card card2) {
    if (((card1.value + 1 == card2.value)
				|| (card1.value == 'A' && card2.value == 2)
				|| (card1.value == 10 && card2.value == 'J')
				|| (card1.value == 'J' && card2.value == 'Q')
				|| (card1.value == 'Q' && card2.value == 'K'))
			&& card1.face == card2.face) {
		return 1;
	}
	return 0;
}

