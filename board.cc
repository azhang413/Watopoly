#include <map>
#include <string>
#include <fstream>
#include "board.h"
#include "building.h"

using namespace std;

int getInd(vector<string> v, string s) {
    int i = 0;
    for (auto &it : v) {
        if (it == s) return i;
        ++i;
    }
    return -1;
}

void Tokenize(string str, vector<string> &out, const string delim) {
    int start = 0;
    int end = str.find(delim);
    while (end != -1) {
        out.push_back(str.substr(start, end - start));
        start = end + delim.size();
        end = str.find(delim, start);
    }
}

map<string, SpecialType> constructBoard = {
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
    {"GOOSE NESTING", SpecialType::Goose},
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

vector<string> squareOrder {
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
};

theBoard::theBoard(vector<Player*> players): players{players} {
    Display *newDisplay = new Display{};
    td = newDisplay;
}

vector<int> theBoard::calcCoords(int order) {
    vector<int> coords{-1,-1,-1,-1};

    switch(order) {
        case 1: // OSAP
            coords[2] = 53;
            coords[3] = 91;
        case 2:
            coords[0] = 51;
            coords[1] = 82;
            coords[2] = 54;
            coords[3] = 82;
        case 3:
            coords[2] = 52;
            coords[3] = 73;
        case 4:
            coords[0] = 51;
            coords[1] = 64;
            coords[2] = 54;
            coords[3] = 64;
        case 5:
            coords[2] = 52;
            coords[3] = 55;
        case 6:
            coords[2] = 52;
            coords[3] = 46;
        case 7:
            coords[0] = 51;
            coords[1] = 37;
            coords[2] = 54;
            coords[3] = 37;
        case 8:
            coords[2] = 53;
            coords[3] = 28;
        case 9:
            coords[0] = 51;
            coords[1] = 19;
            coords[2] = 54;
            coords[3] = 19;
        case 10:
            coords[0] = 51;
            coords[1] = 10;
            coords[2] = 54;
            coords[3] = 10;
        case 11:
            coords[2] = 53;
            coords[3] = 1;
        case 12:
            coords[0] = 46;
            coords[1] = 1;
            coords[2] = 49;
            coords[3] = 1;
        case 13:
            coords[2] = 42;
            coords[3] = 1;
        case 14:
            coords[0] = 36;
            coords[1] = 1;
            coords[2] = 39;
            coords[3] = 1;
        case 15:
            coords[0] = 31;
            coords[1] = 1;
            coords[2] = 34;
            coords[3] = 1;
        case 16:
            coords[2] = 27;
            coords[3] = 1;
        case 17:
            coords[0] = 21;
            coords[1] = 1;
            coords[2] = 24;
            coords[3] = 1;
        case 18:
            coords[2] = 17;
            coords[3] = 1;
        case 19:
            coords[0] = 11;
            coords[1] = 1;
            coords[2] = 14;
            coords[3] = 1;
        case 20:
            coords[0] = 6;
            coords[1] = 1;
            coords[2] = 9;
            coords[3] = 1;
        case 21:
            coords[2] = 3;
            coords[3] = 1;
        case 22:
            coords[0] = 1;
            coords[1] = 10;
            coords[2] = 4;
            coords[3] = 10;
        case 23:
            coords[2] = 3;
            coords[3] = 19;
        case 24:
            coords[0] = 1;
            coords[1] = 28;
            coords[2] = 4;
            coords[3] = 28;
        case 25:
            coords[0] = 1;
            coords[1] = 37;
            coords[2] = 4;
            coords[3] = 37;
        case 26:
            coords[2] = 2;
            coords[3] = 46;
        case 27:
            coords[0] = 1;
            coords[1] = 55;
            coords[2] = 4;
            coords[3] = 55;
        case 28:
            coords[0] = 1;
            coords[1] = 64;
            coords[2] = 4;
            coords[3] = 64;
        case 29:
            coords[2] = 1;
            coords[3] = 73;
        case 30:
            coords[0] = 1;
            coords[1] = 82;
            coords[2] = 4;
            coords[3] = 82;
        case 31:
            coords[2] = 3;
            coords[3] = 91;
        case 32:
            coords[0] = 6;
            coords[1] = 91;
            coords[2] = 8;
            coords[3] = 91;
        case 33:
            coords[0] = 11;
            coords[1] = 91;
            coords[2] = 14;
            coords[3] = 91;
        case 34:
            coords[2] = 17;
            coords[3] = 91;
        case 35:
            coords[0] = 21;
            coords[1] = 91;
            coords[2] = 24;
            coords[3] = 91;
        case 36:
            coords[2] = 27;
            coords[3] = 91;
        case 37:
            coords[2] = 33;
            coords[3] = 91;
        case 38:
            coords[0] = 36;
            coords[1] = 91;
            coords[2] = 39;
            coords[3] = 91;
        case 39:
            coords[2] = 43;
            coords[3] = 91;
        case 40:
            coords[0] = 46;
            coords[1] = 91;
            coords[2] = 49;
            coords[3] = 91;
    }
    return coords;
}


void theBoard::init(const string & filename, int numPlayers) {
    ifstream f{filename};
    for (int i = 0; i < numPlayers; ++i) {continue;}
    this->init();
    string s;
    vector<string> line;
    while (getline(f, s)) {
        string sq = line[0];
        Tokenize(s, line);
        Square* newSq;
        int ind = getInd(squareOrder, line[0]);
        vector<int> coords = calcCoords(ind + 1);
        if (constructBoard[sq] == SpecialType::Academic) {
            // constructBoard with custom inputs
            Academic *newAc = new Academic{sq, stoi(line[1])};
            newSq = new Square{coords[0], coords[1], coords[2], coords[3], constructBoard[sq], newAc};
        } else if (constructBoard[sq] == SpecialType::Residence) {
            // constructBoard with custom inputs
            Residence *newRes = new Residence(sq);
            newSq = new Square{coords[0], coords[1], coords[2], coords[3], constructBoard[sq], newRes};
        } else if (constructBoard[sq] == SpecialType::Gym) {
            // constructBoard with custom inputs
            Gym *newGym = new Gym(sq);
            newSq = new Square(coords[0], coords[1], coords[2], coords[3], constructBoard[sq], newGym);
        }
        delete this->squares[ind];
        this->squares[ind] = newSq;
    }
}


void theBoard::init() {
    for (size_t i = 0; i < squareOrder.size(); ++i) {
        string sq = squareOrder[i];
        Square * newSq;
        vector<int> coords =  calcCoords(i + 1);
        if (constructBoard[sq] == SpecialType::Academic) {
            Academic *newAc = new Academic(sq);
            newSq = new Square{coords[0], coords[1], coords[2], coords[3], constructBoard[sq], newAc};
        } else if (constructBoard[sq] == SpecialType::Residence) {
            Residence *newRes = new Residence(sq);
            newSq = new Square{coords[0], coords[1], coords[2], coords[3], constructBoard[sq], newRes};
        } else if (constructBoard[sq] == SpecialType::Gym) {
            Gym *newGym = new Gym(sq);
            newSq = new Square(coords[0], coords[1], coords[2], coords[3], constructBoard[sq], newGym);
        } else {
            newSq = new Square(coords[0], coords[1], coords[2], coords[3], constructBoard[sq]);
        }
        this->squares.push_back(newSq);
    }
}

ostream &operator<<(ostream &out, const theBoard &b) {
    out << *b.td;
    return out;
}




