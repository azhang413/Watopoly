#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include "board.h"
#include "square.h"
#include "display.h"

using namespace std;

int getInd(vector<string> v, string s) {
    auto it = find(v.begin(), v.end(), s);
    if (it != v.end()) 
    {
        int index = it - v.begin();
        return index;
    }
    else {
        return -1;
    }
}

void Tokenize(string str, vector<string> &out, const string delim = " ") {
    int start = 0;
    int end = str.find(delim);
    while (end != -1) {
        out.push_back(str.substr(start, end - start));
        start = end + delim.size();
        end = str.find(delim, start);
    }
}

const map<string, SpecialType> construct = {
    {"COLLECT OSAP", SpecialType::Osap},
    {"AL", SpecialType::Academic},
    {"SLC", SpecialType::SLC},
    {"ML", SpecialType::Academic},
    {"TUITION", SpecialType::Tuition},
    {"MKV", SpecialType::Residence},
    {"ECH", SpecialType::Academic},
    {"NEEDLES HALL", SpecialType::NH},
    {"PAS", SpecialType::Academic},
    {"HH", SpecialType::Academic},
    {"DC TIMS LINE", SpecialType::TimsLine},
    {"RCH", SpecialType::Academic},
    {"PAC", SpecialType::Gym},
    {"DWE", SpecialType::Academic},
    {"CPH", SpecialType::Academic},
    {"UWP", SpecialType::Residence},
    {"LHI", SpecialType::Academic},
    {"SLC", SpecialType::SLC},
    {"BMH", SpecialType::Academic},
    {"OPT", SpecialType::Academic},
    {"Goose Nesting", SpecialType::Goose},
    {"EV1", SpecialType::Academic},
    {"NEEDLES HALL", SpecialType::NH},
    {"EV2", SpecialType::Academic},
    {"EV3", SpecialType::Academic},
    {"V1", SpecialType::Residence},
    {"PHYS", SpecialType::Academic},
    {"B1", SpecialType::Academic},
    {"CIF", SpecialType::Gym},
    {"B2", SpecialType::Academic},
    {"GO TO TIMS", SpecialType::GoToTims},
    {"EIT", SpecialType::Academic},
    {"ESC", SpecialType::Academic},
    {"SLC", SpecialType::SLC},
    {"C2", SpecialType::Academic},
    {"REV", SpecialType::Residence},
    {"NEEDLES HALL", SpecialType::NH},
    {"MC", SpecialType::Academic},
    {"COOP FEE", SpecialType::Coop},
    {"DC", SpecialType::Academic}
};

const vector<string> squareOrder{
    "COLLECT OSAP",
    "AL",
    "SLC",
    "ML",
    "TUITION",
    "MKV",
    "ECH",
    "NEEDLES HALL",
    "PAS",
    "HH",
    "DC TIMS LINE",
    "RCH",
    "PAC",
    "DWE",
    "CPH",
    "UWP",
    "LHI",
    "SLC",
    "BMH",
    "OPT",
    "GOOSE NESTING",
    "EV1",
    "NEEDLES HALL",
    "EV2",
    "EV3",
    "V1",
    "PHYS",
    "B1",
    "B2",
    "CIF",
    "B2",
    "GO TO TIMS",
    "EIT",
    "ESC",
    "SLC",
    "C2",
    "REV",
    "NEEDLES HALL",
    "MC",
    "COOP FEE",
    "DC"
}

theBoard::theBoard(vector<Player> players): players{players} {
    Display *newDisplay = new Display{};
    td = newDisplay;
}

void theBoard::init(ifstream f) {
    this->init();
    string s;
    vector<string> line;
    while (getline(f, s)) {
        Tokenize(s, line);
        int ind = getInd(squareOrder, line[0]);
        if (construct[sq] == SpecialType::Academic) {
            // construct with custom inputs
            Academic *newAc = new Academic(sw);
            Square *newSq = new Square{construct[sq], newAc};
        } else if (construct[sq] == SpecialType::Residence) {
            // construct with custom inputs
            Residence *newRes = new Residence(sq);
            Square *newSq = new Square{construct[sq], newRes};
        } else if (construct[sq] == SpecialType::Gym) {
            // construct with custom inputs
            Gym *newGym = new Gym(sq);
            Square *newSq = new Square(construct[sq], newGym);
        }
        delete this->squares[ind];
        this->squares[ind] = newSq;
    }
}

void theBoard::init() {
    for (auto sq : squareOrder) {
        if (construct[sq] == SpecialType::Academic) {
            Academic *newAc = new Academic(sw);
            Square *newSq = new Square{construct[sq], newAc};
        } else if (construct[sq] == SpecialType::Residence) {
            Residence *newRes = new Residence(sq);
            Square *newSq = new Square{construct[sq], newRes};
        } else if (construct[sq] == SpecialType::Gym) {
            Gym *newGym = new Gym(sq);
            Square *newSq = new Square(construct[sq], newGym);
        } else {
            Square *newSq = new Square(construct[sq]);
        }
        this->squares.push_back(newSq);
    }
}

ostream &operator<<(ostream &out, const theBoard &b) {
    out << *b.td;
}




