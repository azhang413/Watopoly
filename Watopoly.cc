#include <iostream>
#include <vector>
#include <board.h>
#include <string>
#include <fstream>
#include <sstream>
#include "shuffle.h"
#include "player.h"
#include "board.h"

using namespace std;

class Players

int main(int argc, char* argv[]) {

    const string True{"true"};
    const string False{"false"};
    int numPlayers;
    vector<Players> players;
    string cmd;
    int curTurn = 0;
    vector<int> diceVec{1,2,3,4,5,6};
    Shuffle dice1{diceVec};
    Shuffle dice2{diceVec};

    // setup game
    if (argv[1] == True) {\
        // load game 
        string s;
        ifstream f{agrv[2]};
        getline(f, s);
        numPlayers = stoi(s);
        for (int i = 0; i < numPlayers; ++i) {
            getline(f, s)
            vector<string> line;
            Tokenize(s, line);
            if (line.length() == 6) {
                Player *np = new Player{line[0], stoi(line[3]), stoi(line[4]), stoi(line[2]), line[1], stoi(line[5])};
            }
            else {
                Player *np = new Player{line[0], stoi(line[3]), stoi(line[4]), stoi(line[2]), line[1], 0};
            }
            players.push_back(np);
        }
        theBoard board{players};
        board.init(f);
    } else {
        char chosenPiece;
        string playerName;
        cout << "Welcome to Watopoly! How many players?" << endl;
        cin >> numPlayers;
        for (int i = 0; i < numPlayers; ++i) {
            cout << "Player" << i + 1 << " what is your name?: "<< endl;
            cin >> playerName;
            cout << playerName << " choose a piece: " << endl;
            cin >> chosenPiece;
            Player *np = new Player{playerName, chosenPiece};
            players.push_back{np};
        }
        theBoard board{players};
        board.init();
    }
    if (argv[3] == True) {
        // turn on testing mode
        cout << "testing" << endl;
    }

    // start game
    while (cin >> cmd) {
        cout << board << endl;
        if (cmd == "roll") {
            // implement roll with shuffle
            int steps = dice1.roll() + dice2.roll();
            board.move(players[curTurn], steps);
        } else if (cmd == "next") {
            // pass turn to next player
            ++curTurn;
            if (curTurn == numPlayers) curTurn = 0;
        } else if (cmd == "trade") {
            string tradeTo;
            cin >> tradeTo;
            string give;
            cin >> give;
            string price;
            cin >> price;
            // offer trade
        } else if (cmd == "improve") {
            string property;
            cin >> property;
            string buyorsell;
            cin >> buyorsell;
            // buy or sell improvment for buidling
        } else if (cmd == "mortgage") {
            string property;
            cin >> property;
        } else if (cmd == "unmortgage") {
            string property;
            cin >> property;
        } else if (cmd == "bankrupt") {
            string property;
            cin >> property;
        } else if (cmd == "assets") {
            // display assets
        } else if (cmd == "all") {
            // display assets of all players
        } else if (cmd == "save") {
            string filename;
            cin >> filename;
        }
    }
}