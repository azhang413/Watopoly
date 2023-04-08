#include <iostream>
#include <vector>
#include <board.h>
#include <string>
#include <fstream>
#include <sstream>
#include "shuffle.h"
#include "player.h"
using namespace std;

class Players

int main(int argc, char* argv[]) {

    const string True{"true"};
    const string False{"false"};
    const string delim{" "};
    int numPlayers;
    vector<Player*> players;
    theBoard board{};
    string cmd;
    int curTurn = 0;
    vector<int> diceVec{1,2,3,4,5,6};
    Shuffle dice1{diceVec};
    Shuffle dice2{diceVec};

    // setup game
    if (argv[1] == True) {
        string s;
        ifstream f{argv[2]};
        getline(f, s);
        istringstream iss{s};
        iss >> numPlayers;
        for (int i = 0; i < numPlayers; ++i) {
            vector<string> line;
            getline(f, s);
            istringstream iss{s};
            while ()
            if (line[4] == "10") { // if player is in the time line
                Player *pp = new Player{line[3], line[4], line[2], line[1], line[5]};
            } else {
                Player *pp = new Player{line[3], line[4], line[2], line[1], 0};
            }
            players.push_back(pp);
        }
        board.players = players;

        while (getline(f, s)) {
            vector<string> line;
            tokenize(s, delim, lime); // seperate line by spaces
            string bd = line[0];
            if (bd == "AL") {
                // set building owners
                board.squares[1].b->setOwner(line[1]);
            } 
            // repeat for other buildings
        }        
    } else {
        char chosenPiece;
        cout << "Welcome to Watopoly! How many players?" << endl;
        cin >> numPlayers;
        for (int i = 0; i < numPlayers; ++i) {
            cout << "Player" << i + 1 << " choose a piece: "<< endl;
            cin >> chosenPiece;
            Player *np = new Player{chosenPiece};
            players.push_back{np};
        }
    }
    if (argv[3] == True) {
        // turn on testing mode
        cout << "testing" << endl;
    }

    // start game
    while (cin >> cmd) {
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