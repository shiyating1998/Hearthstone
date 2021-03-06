#include <iostream>
#include <string>
#include <fstream>
#include "Board.h"
#include "Player.h"
using namespace std;

int main(int argc, char *argv[]) {	
	string cmd;
	Board board;	
	// flags for the command line arguements
	bool deck1 = false;
	bool deck2 = false;
	bool testing = false;
	bool init = false;
	// flags for the first turn 
	bool first1 = true;
	bool first2 = true;
	ifstream initFile;
	
	// get the names of the players
	cout << "Name of player 1: ";
	cin >> cmd;
	Player player1{cmd, board};
	cout << endl;

	cout << "Name of player 2: ";
	cin >> cmd;
	Player player2{cmd, board};
	
	Player *playerTurn = &Player1;
	
	// executing the arguements provided to main	
	for (int i = 0; i < argc; i++) {
		// when player 1 has a deck, the next element should be the filename of the deck
		if (argv[i] == "-deck1") {
			player1.initDeck(argv[i+1]);
			deck1 = true;
		}
		// when player 2 has a deck, same situation as -deck1
		if (argv[i] == "-deck2") {
			player2.initDeck(argv[i+1]);
			deck2 = true;
		}
		// when -init arguement is present
		if (argv[i] == "init") {
			initFile.open(argv[i+1]);
			init = true;
		}
		// if the testing argument is present
		if (argv[i] == "-testing") {
			testing = true;
		}
		
	}

	// When the -deck1 or -deck2 arguement is not present,
	// use the default decks
	if (!deck1) {
		player1.initDeck("default.deck");
	}
	if (!deck2) {
		player2.initDeck("default.deck");
	}	

	// recieve commands until the end of the game;
	while (getline(cin, cmd)) {
		// if it's the first turn
		if (!first1 || !first2) {
			playerTurn->turnStart();
			first1 = false;
		}
		// when the player ends their turn
		if (cmd.rfind("end") != string::nopos) {
			if (playerTurn == &player1) {
				playerTurn = &player2;
				first1 = false;
			} else {
				playerTurn = &player1;
				first2 = false; 
			}
		}
		// when the player attacks with a minion
		if (cmd.rfind("attack") != string::nopos) {
			int pos = cmd.rfind("attack") + 6;
			int i = -1;
			int j = -1;
					
			if (cmd.find_first_not_of(" ", pos) != string::npos) {
				pos = cmd.find_first_not_of(" ", pos);
				i = cmd[pos];
				pos++;
			}
			if (cmd.find_first_not_of(" ", pos) != string::npos) {
				j = cmd[cmd.find_first_not_of(" ", pos)];
			}
			// when attacking the opponent
			if (j = -1) {
				playerTurn->attack(i);
			}
			// when attacking an opponent minion 
			else {
				playerTurn->attack(i, j);
			}
		}
		// when the player plays a card on the board 	
		if (cmd.rfine("play") != string::nopos) {
			int pos = cmd.rfind("play") + 4;
			int i = -1;
			int p = -1;
			int t = -1;
		
			// the position of the card to be played from player's hand
			if (cmd.find_first_not_of(" ", pos) != string::npos) {
				pos = cmd.find_first_not_of(" ", pos);
				i = cmd[pos];
				pos++;			
			}
			// which player it is going to affect
			if (cmd.find_first_not_of(" ", pos) != string::npos) {
				pos = cmd.find_first_not_of(" ", pos);
				p = cmd[pos];
				pos++;
			}
			// which card its going to affect
			if (cmd.find_first_not_of(" ", pos) != string::npos) {
				pos = cmd.find_first_not_of(" ", pos);
				// if its going to affect a ritual
				if (cmd[pos] == "r") {
					t = 'r';
				} else {
					t = cmd[pos];
				}
			}
			// when playing a card that has a universal affect
			if (p == -1 && t == -1) {
				playerTurn->placeCard(int i);	
			}
			// when playing a card with a targeted ability 
			else {
				playerTurn ->placeCard(int i, int p, int t);
			}
		}
		// when the player uses a minion's ability
		if (cmd.rfind("use") != string::npos) {
			int pos = cmd.rfind("play") + 4;
			int i = -1;
			int p = -1;
			int t = -1;
		
			// the position of the card to be played from player's hand
			if (cmd.find_first_not_of(" ", pos) != string::npos) {
				pos = cmd.find_first_not_of(" ", pos);
				i = cmd[pos];
				pos++;			
			}
			// which player it is going to affect
			if (cmd.find_first_not_of(" ", pos) != string::npos) {
				pos = cmd.find_first_not_of(" ", pos);
				p = cmd[pos];
				pos++;
			}
			// which card its going to affect
			if (cmd.find_first_not_of(" ", pos) != string::npos) {
				pos = cmd.find_first_not_of(" ", pos);
				t = cmd[pos];
			}
			// when playing a card that has a universal affect
			if (p == -1 && t == -1) {
				playerTurn->use(int i);	
			}
			// when playing a card with a targeted ability 
			else {
				playerTurn->use(int i, int p, int t);
			}
		}
		// when inspecting a player's card
		if (cmd.rfind("inspect") != string::npos) {
			pos = cmd.rfind("inspect") + 7;
			int i = cmd.find_first_not_of(" ", pos);
			playerTurn->inspect(i);
		}
		// when the player displays their hand
		if (cmd.rfind("hand") != string::npos) {
			playerTurn->displayHand();	
		}
		// displays the board
		if (cmd.rfind("board") != string::npos) {
			cout << board;
		}
		// testing options
		if (testing) {
			if (cmd.rfind("draw") != string::npos) {
				playerTurn->draw();	
			}	
			if (cmd.rfind("discard") != string::npos) {
				playerTurn->discard();
			}
		}
		// checks if the game ended yet or not
		if (board.gameEnded();) {
			return 0;
		}
	}	
}
