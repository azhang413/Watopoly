#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <exception>
#include "shuffle.h"
#include "player.h"
#include "board.h"

using namespace std;

int main(int argc, char* argv[]) {
    bool load = false;
    const string True{"true"};
    const string False{"false"};
    int numPlayers;
    vector<Player*> players;
    string cmd;
    int curTurn = 0;
    vector<int> diceVec{1,2,3,4,5,6};
    Shuffle dice1{diceVec};
    Shuffle dice2{diceVec};

    // setup game
    if (argv[1] == True) {
        // load game 
        load = true;
        string s;
        ifstream f{argv[2]};
        getline(f, s);
        numPlayers = stoi(s);
        for (int i = 0; i < numPlayers; ++i) {
            getline(f, s);
            vector<string> line;
            line = Tokenize(s);
            Player *np;
            string name = line[0];   
            if (line.size() == 6) {
                np = new Player{name, stoi(line[3]), stoi(line[4]), stoi(line[2]), line[1][0], stoi(line[5])};
            }
            else {
                np = new Player{name, stoi(line[3]), stoi(line[4]), stoi(line[2]), line[1][0], 0};
            }
            players.emplace_back(np); 
        }
    } else {
        // new game 
        vector<char> pieces{'G', 'B', 'D', 'P', 'S', '$', 'L', 'T'};
        char chosenPiece;
        string playerName;
        cout << "Welcome to Watopoly! How many players? (max of 8 players)" << endl;
        cin >> numPlayers;
        if (numPlayers > 8 || numPlayers <= 0) { // checks for range, exits if invalid.
            cout << "Invalid Number of Players. Exiting program..." << endl;
            exit(0);
        }
        for (int i = 0; i < numPlayers; ++i) {
            cout << " " << endl;
            cout << "Player " << i + 1 << " what is your name?: "<< endl;
            try {
                cin >> playerName;
                if (cin.eof()) {
                    throw runtime_error("EOF reached");
                }
            } catch (const exception& e) {
                cout << "Invalid Behaviour. Exiting program..." << endl;
                exit(0);
            }
            cout << " " << endl;
            cout << "Hi " << playerName << "! Here are the available 'Pieces' you can pick from:"<< endl;
            for (auto p: pieces) {cout << "[" << p << "] ";}
            cout << endl;
            cout << " " << endl;
            cout << "Please pick a piece: " << endl;
            bool cont = false;
            try {
                while(true) { // checks for valid piece
                    cin >> chosenPiece;
                    if (cin.eof()) {
                        throw runtime_error("EOF reached");
                        break;
                    }
                    for (auto j = pieces.begin(); j != pieces.end(); ++j) {
                        if (*j == chosenPiece) {
                            pieces.erase(j);
                            cont = true;
                            break;
                        }
                    
                    }

                    if (cont) {
                        cout << playerName << " have chosen " << "[" << chosenPiece << "]" << endl;
                        break;
                    } else {
                        cout << " " << endl;
                        cout << "Invalid Selection. " << "Please try again." << endl;
                    }
                }
            } catch (const exception& e) {
                cout << "Invalid Behaviour. Exiting program..." << endl;
                exit(0);
            }
            Player *np = new Player{playerName, chosenPiece};
            players.emplace_back(np);
        }
    }

    if (argv[3] == True) {
        // turn on testing mode
        cout << "testing" << endl;
    }

    theBoard board{players};
     
    if (load) {
        board.init(argv[2], numPlayers);
    } else {
        board.init();
    }
    cout << board;
    // start game
    Building* landedOn = board.move(players[0], 3);
    board.save("out.txt");
    board.mortgage(players[1], "HH");
    board.mortgage(players[0], "EV1");
    board.mortgage(players[1], "PAC");
    board.unmortgage(players[1], "HH");
    board.unmortgage(players[1], "EV1");
    board.unmortgage(players[1], "PAC");
    cout << board;
    /*
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
    */
}