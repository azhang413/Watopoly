#include "display.h"
#include "square.h"
#include "player.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;


Display::Display() {
    string s;
    fstream fin{"thedisplayboard.txt"};
    while (getline(fin, s)) {
        vector<char> vc;
        for (char c : s) {
            vc.emplace_back(c);
        }
        text.emplace_back(vc);
    }
}

ostream &operator<<(ostream &out, const Display &dis){
    for (auto vc : dis.text) {
        for (char c : vc) {
            out << c;
        }
        out << endl;
    }
    return out;
}


 void Display::notify(Subject<Info> &s) {
    int r = s.getInfo().PlayerRow;
    int c = s.getInfo().PlayerCol;
    vector<char> players = s.getInfo().players;
    int length = players.size();
    
    for (int i = 0; i < 8; ++i) {
        if (i < length) {
            this->text[r][c + i] = players[i];
        } else { 
            this->text[r][c + i] = ' ';
        }
    }
    if (s.getInfo().BuildingCol != -1 && s.getInfo().BuildingRow != -1) {
        for (int k = 0; k < 5; ++k) {
            if (k < s.getInfo().improvements) {
                this->text[s.getInfo().BuildingRow][s.getInfo().BuildingCol + k] = 'I';
            } else {
                this->text[s.getInfo().BuildingRow][s.getInfo().BuildingCol + k] = ' ';
            }
            
        }
    }
 }

