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
    int i = 0;
    int j = 0;

    for (char plyr : s.getInfo().players) {
        if (j == 8) { 
            j = 0;
            ++i;
        }
        text[r + i][c + j] = plyr;
        ++j;
    }
    if (s.getInfo().BuildingCol != -1 && s.getInfo().BuildingRow != -1) {
        for (int k=0; k < s.getInfo().improvements; ++k) {
            text[s.getInfo().BuildingRow][s.getInfo().BuildingCol] = 'I';
        }
    }
 }

