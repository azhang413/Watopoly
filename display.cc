#include "display.h"
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