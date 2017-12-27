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

#include <cstdlib>
#include <ctype.h>
#include <ctime>
#include "lin_freecell.h"
using namespace std;

Card deck[8][52], freeCell[4], homeCell[4];
int quit = 0, show = 1;
const int ESCAPE = 27;

void generate() {
    int arrayOfNumbers[52], done = 0;
    srand(time(0));
    for (int i = 0; i < 52; ++i) {
		do {
			arrayOfNumbers[i] = rand() % 52;
			for (int j = 0; j < i; ++j) {
				if (arrayOfNumbers[j] == arrayOfNumbers[i]) {
					done = 1;
					break;
				} else {
					done = 0;
				}
			}
		}
		while (done != 0);
	}
	Card arrayOfCards[52];
	for (int i = 0; i < 52; ++i) {
		if (arrayOfNumbers[i] % 13 == 0) {
			arrayOfCards[i].modify('A');
		} else if (arrayOfNumbers[i] % 13 == 10) {
			arrayOfCards[i].modify('J');
		} else if (arrayOfNumbers[i] % 13 == 11) {
			arrayOfCards[i].modify('Q');
		} else if (arrayOfNumbers[i] % 13 == 12) {
			arrayOfCards[i].modify('K');
		}
		if (arrayOfNumbers[i] < 13) {
			if (arrayOfCards[i].value == -1) {
				arrayOfCards[i].modify(arrayOfNumbers[i] + 1);
			}
			arrayOfCards[i].modify(PAN);
		} else if (arrayOfNumbers[i] < 26) {
			if (arrayOfCards[i].value == -1) {
				arrayOfCards[i].modify(arrayOfNumbers[i] - 12);
			}
			arrayOfCards[i].modify(EET);
		} else if (arrayOfNumbers[i] < 39) {
			if (arrayOfCards[i].value == -1) {
				arrayOfCards[i].modify(arrayOfNumbers[i] - 25);
			}
			arrayOfCards[i].modify(CHIDI);
		} else if (arrayOfNumbers[i] < 52) {
			if (arrayOfCards[i].value == -1) {
				arrayOfCards[i].modify(arrayOfNumbers[i] - 38);
			}
			arrayOfCards[i].modify(HUKUM);
		}
	}
	for (int i = 0; i < 52; ++i) {
		for (int j = 0; j < 8; ++j) {
			deck[j][i].initialize();
		}
	}
	for (int i = 0; i < 52; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (i * 8 + j < 52) {
				deck[j][i].modify(arrayOfCards[i * 8 + j].value);
				deck[j][i].modify(arrayOfCards[i * 8 + j].face);
			}
		}
	}
	for (int i = 0; i < 4; ++i) {
		homeCell[i].initialize();
		freeCell[i].initialize();
	}
	freeCell[0].modify(PAN);
    freeCell[1].modify(EET);
    freeCell[2].modify(CHIDI);
    freeCell[3].modify(HUKUM);
}

void display() {
    cout << "\r\n" << "      ";
    for (int i = 0; i < 4; ++i) {
		if (homeCell[i].isComplete()) {
			homeCell[i].print();
		} else {
			cout << "--";
		}
		cout << ", ";
	}
	cout << ":Home Cells\t";
	for (int j = 0; j < 4; ++j) {
		if (freeCell[j].isComplete()) {
			freeCell[j].print();
		} else {
			cout << "--";
		}
		cout << ", ";
	}
	cout << ":Free Cells\r\nDeck:\r\n\n";
	int maxNumber = 0;
	while (deck[0][maxNumber].isComplete()
			|| deck[1][maxNumber].isComplete()
			|| deck[2][maxNumber].isComplete()
			|| deck[3][maxNumber].isComplete()
			|| deck[4][maxNumber].isComplete()
			|| deck[5][maxNumber].isComplete()
			|| deck[6][maxNumber].isComplete()
			|| deck[7][maxNumber].isComplete()) {
		++maxNumber;
	}
	for (int i = 0; i < maxNumber; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (deck[j][i].value != 10) {
				cout << " ";
			}
			if (!deck[j][i].isComplete()) {
				cout << "  ";
			}
			cout << "      ";
			deck[j][i].print();
			if (j % 8 == 7) {
				cout << "\r\n";
			}
		}
	}
}

void type(const char *msg) {
    cout << "\r\n" << msg << "\r\n";
}

void error(int way) {
    if (way == 0) {
		type("Command cancelled");
	} else {
		if (way == 1) {
			type("No such column or cell");
		} else if (way == 2) {
			type("Column/Cell Empty");
		} else if (way == 3) {
			type("Invalid move");
		}
	}
	type("Press h for help...");
}

int makeMove() {
	cout << "\r\nfreecell> ";
	char command[4];
	cin >> command[0];
	command[0] = tolower(command[0]);
	if (command[0] == ESCAPE) {
		error(0);
	} else if (command[0] == 'm') {
		cout << "move ";
		cin >> command[1];
		command[1] -= 48;
		if (command[1] + 48 == ESCAPE) {
			error(0);
		} else if (command[1] >= 1 && command[1] <= 8) {
			int rowLast = -1;
			int colInitial = command[1] - 1;
			while (deck[colInitial][rowLast + 1].isComplete()) {
				++rowLast;
			}
			if (rowLast != -1) {
				deck[colInitial][rowLast].print();
				cout << " to ";
				cin >> command[2];
				command[2] = tolower(command[2]);
				if (command[2] == ESCAPE) {
					error(0);
				} else if (command[2] - 48 >= 1 && command[2] - 48 <= 8) {
					int rowEmpty = 0;
					int colFinal = command[2] - 49;
					cout << "Column #" << colFinal + 1;
					while (deck[colFinal][rowEmpty].isComplete()) {
						++rowEmpty;
					}
					if (rowEmpty == 0) {
						deck[colFinal][rowEmpty] =
							deck[colInitial][rowLast];
						deck[colInitial][rowLast].initialize();
					} else {
						if (nextToAlternate
								(deck[colInitial][rowLast],
								 deck[colFinal][rowEmpty - 1])) {
							deck[colFinal][rowEmpty] =
								deck[colInitial][rowLast];
							deck[colInitial][rowLast].initialize();
						} else {
							error(3);
						}
					}
				} else if (command[2] == 'h') {
					cout << "Home Cell #";
					cin >> command[3];
					command[3] -= 48;
					if (command[3] + 48 == ESCAPE) {
						error(0);
					} else if (command[3] >= 1 && command[3] <= 4) {
						if (!homeCell[command[3] - 1].isComplete()) {
							homeCell[command[3] - 1] =
								deck[colInitial][rowLast];
							deck[colInitial][rowLast].initialize();
						} else {
							error(3);
						}
					} else {
						error(1);
					}
				} else if (command[2] == 'f') {
					cout << "Free Cell";
					if (deck[colInitial][rowLast].face == PAN) {
						if ((!freeCell[0].isComplete()
									&& deck[colInitial][rowLast].value == 'A')
								|| (freeCell[0].isComplete()
									&& nextToSame(freeCell[0],
										deck[colInitial][rowLast]))) {
							freeCell[0] = deck[colInitial][rowLast];
							deck[colInitial][rowLast].initialize();
						} else {
							error(3);
						}
					} else if (deck[colInitial][rowLast].face == EET) {
						if ((!freeCell[1].isComplete()
									&& deck[colInitial][rowLast].value == 'A')
								|| (freeCell[1].isComplete()
									&& nextToSame(freeCell[1],
										deck[colInitial][rowLast]))) {
							freeCell[1] = deck[colInitial][rowLast];
							deck[colInitial][rowLast].initialize();
						} else {
							error(3);
						}
					} else if (deck[colInitial][rowLast].face == CHIDI) {
						if ((!freeCell[2].isComplete()
									&& deck[colInitial][rowLast].value == 'A')
								|| (freeCell[2].isComplete()
									&& nextToSame(freeCell[2],
										deck[colInitial][rowLast]))) {
							freeCell[2] = deck[colInitial][rowLast];
							deck[colInitial][rowLast].initialize();
						} else {
							error(3);
						}
					} else if (deck[colInitial][rowLast].face == HUKUM) {
						if ((!freeCell[3].isComplete()
									&& deck[colInitial][rowLast].value == 'A')
								|| (freeCell[3].isComplete()
									&& nextToSame(freeCell[3],
										deck[colInitial][rowLast]))) {
							freeCell[3] = deck[colInitial][rowLast];
							deck[colInitial][rowLast].initialize();
						} else {
							error(3);
						}
					} else {
						error(3);
					}
				} else {
					error(1);
				}
			} else {
				cout << "Column #" << command[1];
				error(2);
			}
		} else if (command[1] + 48 == 'h') {
			cout << "Home Cell #";
			cin >> command[2];
			command[2] -= 48;
			if (command[2] + 48 == ESCAPE) {
				error(0);
			} else if (command[2] >= 1 && command[2] <= 4) {
				if (homeCell[command[2] - 1].isComplete()) {
					cout << "(";
					homeCell[command[2] - 1].print();
					cout << ") to ";
					cin >> command[3];
					command[3] -= 48;
					if (command[3] + 48 == ESCAPE) {
						error(0);
					} else if (command[3] >= 1 && command[3] <= 8) {
						cout << "Column #" << command[3];
						int rowEmpty = 0;
						int colFinal = command[3] - 1;
						while (deck[colFinal][rowEmpty].isComplete()) {
							++rowEmpty;
						}
						if (rowEmpty == 0) {
							deck[colFinal][rowEmpty] = homeCell[command[2] - 1];
							homeCell[command[2] - 1].initialize();
						} else {
							if (nextToAlternate
									(homeCell[command[2] - 1],
									 deck[colFinal][rowEmpty - 1])) {
								deck[colFinal][rowEmpty] =
									homeCell[command[2] - 1];
								homeCell[command[2] - 1].initialize();
							} else {
								error(3);
							}
						}
					} else if (command[3] + 48 == 'f') {
						cout << "Free Cell";
						if (homeCell[command[2] - 1].face == PAN) {
							if ((!freeCell[0].isComplete()
										&& homeCell[command[2] - 1].value == 'A')
									|| (freeCell[0].isComplete()
										&& nextToSame(freeCell[0],
											homeCell[command[2] -
											1]))) {
								freeCell[0] = homeCell[command[2] - 1];
								homeCell[command[2] - 1].initialize();
							} else {
								error(3);
							}
						} else if (homeCell[command[2] - 1].face == EET) {
							if ((!freeCell[1].isComplete()
										&& homeCell[command[2] - 1].value == 'A')
									|| (freeCell[1].isComplete()
										&& nextToSame(freeCell[1], homeCell[command[2] - 1]))) {
								freeCell[1] = homeCell[command[2] - 1];
								homeCell[command[2] - 1].initialize();
							} else {
								error(3);
							}
						} else if (homeCell[command[2] - 1].face == CHIDI) {
							if ((!freeCell[2].isComplete()
										&& homeCell[command[2] - 1].value == 'A')
									|| (freeCell[2].isComplete()
										&& nextToSame(freeCell[2], homeCell[command[2] - 1]))) {
								freeCell[2] = homeCell[command[2] - 1];
								homeCell[command[2] - 1].initialize();
							} else {
								error(3);
							}
						} else if (homeCell[command[2] - 1].face == HUKUM) {
							if ((!freeCell[3].isComplete()
										&& homeCell[command[2] - 1].value == 'A')
									|| (freeCell[3].isComplete()
										&& nextToSame(freeCell[3], homeCell[command[2] - 1]))) {
								freeCell[3] = homeCell[command[2] - 1];
								homeCell[command[2] - 1].initialize();
							} else {
								error(3);
							}
						} else {
							error(3);
						}
					} else {
						error(1);
					}
				} else {
					error(2);
				}
			} else {
				error(1);
			}
		} else if (command[1] + 48 == 'f') {
			cout << "card from Free Cell";
			type("Cannot move from Free Cells");
		} else {
			error(1);
		}
	} else if (command[0] == 'h') {
		cout << "help";
		type("\tKEY\t\tACTION");
		type("\t[n]\t\tnew game");
		cout << "\t[u]\t\tundo last move(NOT IMPLEMENTED)\r\n\
			\t[h]\t\thelp\r\n\
			\t[m]\t\tmove card from column #[1,2,3,4,5,6,7,8] or\r\n\
			\t\t\t[h]ome cell #[1,2,3,4] to column #[1,2,3,4,5,6,7,8] or\r\n\
			\t\t\t[h]ome cell #[1,2,3,4] or [f]ree cell\r\n\
			\t\[e]\t\texit\r\n\
			\t\[c]\t\tcheck deck for win and valid moves\r\n\
			\t[ESC]\t\tCancel command\r\n";
		show = 0;
	} else if (command[0] == 'n') {
		cout << "new game(y/n)";
		cin >> command[0];
		command[0] = tolower(command[0]);
		if (command[0] == ESCAPE) {
			error(0);
			command[0] = '\0';
		}
	} else if (command[0] == 'u') {
		cout << "undo";
		type("Undo not supported yet. But you may implement it. More information at");
		show = 0;
	} else if (command[0] == 'e') {
		cout << "exit?(y/n)";
		cin >> command[0];
		command[0] = tolower(command[0]);
		if (command[0] == ESCAPE) {
			error(0);
			command[0] = '\0';
		} else {
			quit = 1;
		}
	} else if (command[0] == 'c') {
		cout << "check deck";
		for (int i = 0; i < 8; ++i) {
			int rowLast = -1;
			int colInitial = i;
			while (deck[colInitial][rowLast + 1].isComplete()) {
				++rowLast;
			}
			if (rowLast != -1) {
				if (deck[colInitial][rowLast].face == PAN) {
					if ((!freeCell[0].isComplete()
								&& deck[colInitial][rowLast].value == 'A')
							|| (freeCell[0].isComplete()
								&& nextToSame(freeCell[0], deck[colInitial][rowLast]))) {
						freeCell[0] = deck[colInitial][rowLast];
						deck[colInitial][rowLast].initialize();
					}
				} else if (deck[colInitial][rowLast].face == EET) {
					if ((!freeCell[1].isComplete()
								&& deck[colInitial][rowLast].value == 'A')
							|| (freeCell[1].isComplete()
								&& nextToSame(freeCell[1], deck[colInitial][rowLast]))) {
						freeCell[1] = deck[colInitial][rowLast];
						deck[colInitial][rowLast].initialize();
					}
				} else if (deck[colInitial][rowLast].face == CHIDI) {
					if ((!freeCell[2].isComplete()
								&& deck[colInitial][rowLast].value == 'A')
							|| (freeCell[2].isComplete()
								&& nextToSame(freeCell[2], deck[colInitial][rowLast]))) {
						freeCell[2] = deck[colInitial][rowLast];
						deck[colInitial][rowLast].initialize();
					}
				} else if (deck[colInitial][rowLast].face == HUKUM) {
					if ((!freeCell[3].isComplete()
								&& deck[colInitial][rowLast].value == 'A')
							|| (freeCell[3].isComplete()
								&& nextToSame(freeCell[3], deck[colInitial][rowLast]))) {
						freeCell[3] = deck[colInitial][rowLast];
						deck[colInitial][rowLast].initialize();
					}
				}
			}
		}
		if (freeCell[0].value == 'K' && freeCell[1].value == 'K'
				&& freeCell[2].value == 'K' && freeCell[3].value == 'K') {
			type("The Game has Ended. You have won!");
			type("Press n for new game.");
		}
	} else {
		type("Illegal command. Press h for help.");
		cout << command[0];
		show = 0;
		command[0] = '\0';
	}
	return command[0];
}

int main() {
    initscr();
    cbreak();
    noecho();
    nl();
    intrflush(stdscr, TRUE);
    keypad(stdscr, TRUE);
    type("\
			F R E E  C E L L  for  L I N U X\r\n\
			0.1 alpha1\r\n\
			by Anupam Srivastava");
	type("(Wed Oct  4 14:21:08 IST 2006) Project started.");
	type("(Wed Oct  4 17:04:45 IST 2006) 0.1alpha1 completed.");
	type("(Thu Oct  5 15:48:32 IST 2006) 0.1alpha2 completed. NCURSES is now a dependency.");
	do {
		generate();
		type("Type h to begin......");
		do {
			if (show) {
				display();
			}
			show = 1;
		}while (makeMove() != 'y');
	}while (!quit);
	endwin();
    type("Freecell for Linux");
    type("Licensed under GNU GPL v 2. Request source code and license terms at anupam.srivastava@gmail.com if not with this binary.");
    return 0;
}
