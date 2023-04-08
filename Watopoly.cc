#include<iostream>
#include<vector>
#include<board.h>
#include <string>
#include <fstream>
using namespace std;

class Players

int main(int argc, char* argv[]) {

    const string True{"true"};
    const string False{"false"};
    const string delim{" "};
    int numPlayers;
    vector<Player*> players;
    theBoard board{};

    if (argv[1] == True) {
        string s;
        ifstream f{argv[2]};
        getline(f, numPlayers);
        for (int i = 0; i < numPlayers; ++i) {
            vector<string> line;
            getline(f, s);
            tokenize(s, delim, line); // seperate line by spaces
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
                board.squares[1].b->setOwner(line[1]);
            } // repeat for other buildings
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
        cout << "testing" << endl;
    }
}