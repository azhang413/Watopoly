#include <map>
#include <string>
#include <sstream>
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

vector<string> Tokenize(string str) {
    vector<string> out{};
    istringstream iss{str};
    string word;
    while (iss >> word) {
        out.push_back(word);
    }
    return out;
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
            break;
        case 2:
            coords[0] = 51;
            coords[1] = 82;
            coords[2] = 54;
            coords[3] = 82;
            break;
        case 3:
            coords[2] = 52;
            coords[3] = 73;
            break;
        case 4:
            coords[0] = 51;
            coords[1] = 64;
            coords[2] = 54;
            coords[3] = 64;
            break;
        case 5:
            coords[2] = 52;
            coords[3] = 55;
            break;
        case 6:
            coords[2] = 52;
            coords[3] = 46;
            break;
        case 7:
            coords[0] = 51;
            coords[1] = 37;
            coords[2] = 54;
            coords[3] = 37;
            break;
        case 8:
            coords[2] = 53;
            coords[3] = 28;
            break;
        case 9:
            coords[0] = 51;
            coords[1] = 19;
            coords[2] = 54;
            coords[3] = 19;
            break;
        case 10:
            coords[0] = 51;
            coords[1] = 10;
            coords[2] = 54;
            coords[3] = 10;
            break;
        case 11:
            coords[2] = 53;
            coords[3] = 1;
            break;
        case 12:
            coords[0] = 46;
            coords[1] = 1;
            coords[2] = 49;
            coords[3] = 1;
            break;
        case 13:
            coords[2] = 42;
            coords[3] = 1;
            break;
        case 14:
            coords[0] = 36;
            coords[1] = 1;
            coords[2] = 39;
            coords[3] = 1;
            break;
        case 15:
            coords[0] = 31;
            coords[1] = 1;
            coords[2] = 34;
            coords[3] = 1;
            break;
        case 16:
            coords[2] = 27;
            coords[3] = 1;
            break;
        case 17:
            coords[0] = 21;
            coords[1] = 1;
            coords[2] = 24;
            coords[3] = 1;
            break;
        case 18:
            coords[2] = 17;
            coords[3] = 1;
            break;
        case 19:
            coords[0] = 11;
            coords[1] = 1;
            coords[2] = 14;
            coords[3] = 1;
            break;
        case 20:
            coords[0] = 6;
            coords[1] = 1;
            coords[2] = 9;
            coords[3] = 1;
            break;
        case 21:
            coords[2] = 3;
            coords[3] = 1;
            break;
        case 22:
            coords[0] = 1;
            coords[1] = 10;
            coords[2] = 4;
            coords[3] = 10;
            break;
        case 23:
            coords[2] = 3;
            coords[3] = 19;
            break;
        case 24:
            coords[0] = 1;
            coords[1] = 28;
            coords[2] = 4;
            coords[3] = 28;
            break;
        case 25:
            coords[0] = 1;
            coords[1] = 37;
            coords[2] = 4;
            coords[3] = 37;
            break;
        case 26:
            coords[2] = 2;
            coords[3] = 46;
            break;
        case 27:
            coords[0] = 1;
            coords[1] = 55;
            coords[2] = 4;
            coords[3] = 55;
            break;
        case 28:
            coords[0] = 1;
            coords[1] = 64;
            coords[2] = 4;
            coords[3] = 64;
            break;
        case 29:
            coords[2] = 1;
            coords[3] = 73;
            break;
        case 30:
            coords[0] = 1;
            coords[1] = 82;
            coords[2] = 4;
            coords[3] = 82;
            break;
        case 31:
            coords[2] = 3;
            coords[3] = 91;
            break;
        case 32:
            coords[0] = 6;
            coords[1] = 91;
            coords[2] = 8;
            coords[3] = 91;
            break;
        case 33:
            coords[0] = 11;
            coords[1] = 91;
            coords[2] = 14;
            coords[3] = 91;
            break;
        case 34:
            coords[2] = 17;
            coords[3] = 91;
            break;
        case 35:
            coords[0] = 21;
            coords[1] = 91;
            coords[2] = 24;
            coords[3] = 91;
            break;
        case 36:
            coords[2] = 27;
            coords[3] = 91;
            break;
        case 37:
            coords[2] = 33;
            coords[3] = 91;
            break;
        case 38:
            coords[0] = 36;
            coords[1] = 91;
            coords[2] = 39;
            coords[3] = 91;
            break;
        case 39:
            coords[2] = 43;
            coords[3] = 91;
            break;
        case 40:
            coords[0] = 46;
            coords[1] = 91;
            coords[2] = 49;
            coords[3] = 91;
            break;
    }
    return coords;
}


void theBoard::init(const string & filename, int numPlayers) {
    bank = new Player{"BANK", 'W'};
    string s;
    ifstream f{filename};
    getline(f, s);
    for (int i = 0; i < numPlayers; ++i) {
        getline(f, s);
    }
    this->init();
    vector<string> line;
    while (getline(f, s)) {
        line = Tokenize(s);
        string sq = line[0];
        Square* newSq;
        int ind = getInd(squareOrder, line[0]);
        vector<int> coords = calcCoords(ind + 1);
        Player *owner;
        if (line[1] == "BANK") {
            owner = bank;
        } else {
            for (auto p : players) {
                if (p->name == line[1]) {
                    owner = p;
                }
            }
        }
        if (constructBoard[sq] == SpecialType::Academic) {
            // constructBoard with custom inputs
            Academic *newAc = new Academic{sq, stoi(line[2])};
            newAc->setOwner(owner);
            newSq = new Square{coords[0], coords[1], coords[2], coords[3], constructBoard[sq], newAc};
        } else if (constructBoard[sq] == SpecialType::Residence) {
            // constructBoard with custom inputs
            Residence *newRes = new Residence(sq);
            newRes->setOwner(owner);
            newSq = new Square{coords[0], coords[1], coords[2], coords[3], constructBoard[sq], newRes};
        } else if (constructBoard[sq] == SpecialType::Gym) {
            // constructBoard with custom inputs
            Gym *newGym = new Gym(sq);
            newGym->setOwner(owner);
            newSq = new Square(coords[0], coords[1], coords[2], coords[3], constructBoard[sq], newGym);
        }
        delete this->squares[ind];
        newSq->attach(td);
        newSq->notifyObservers();
        this->squares[ind] = newSq;
    }
    for (auto p : players) {
        this->squares[0]->removePlayer(p);
        this->squares[p->square]->addPlayer(p);
    }
}


void theBoard::init() {
    bank = new Player{"BANK", 'W'};
    for (size_t i = 0; i < squareOrder.size(); ++i) {
        string sq = squareOrder[i];
        Square * newSq;
        vector<int> coords =  calcCoords(i + 1);
        if (constructBoard[sq] == SpecialType::Academic) {
            Academic *newAc = new Academic(sq);
            newAc->setOwner(bank);
            newSq = new Square{coords[0], coords[1], coords[2], coords[3], constructBoard[sq], newAc};
        } else if (constructBoard[sq] == SpecialType::Residence) {
            Residence *newRes = new Residence(sq);
            newRes->setOwner(bank);
            newSq = new Square{coords[0], coords[1], coords[2], coords[3], constructBoard[sq], newRes};
        } else if (constructBoard[sq] == SpecialType::Gym) {
            Gym *newGym = new Gym(sq);
            newGym->setOwner(bank);
            newSq = new Square(coords[0], coords[1], coords[2], coords[3], constructBoard[sq], newGym);
        } else {
            newSq = new Square(coords[0], coords[1], coords[2], coords[3], constructBoard[sq]);
        }
        newSq->attach(td);
        this->squares.emplace_back(newSq);
    }
    for (auto p : players) {
        this->squares[0]->addPlayer(p);
    }
    this->squares[0]->notifyObservers();
}

Building* theBoard::move(Player* p, int steps) {
    squares[p->square]->removePlayer(p);
    p->square += steps;
    squares[p->square]->addPlayer(p);
    return squares[p->square]->getBuilding();
}

void theBoard::save(string file) {
    ofstream f{file};
    f << players.size() << "\n";
    for (auto p : players) {
        f << p->name << " " << p->p << " " << p->timsCups << " " << p->money << " " << p->square << " " << p->place << "\n";
    }
    for (auto s : squares) {
        SpecialType curType = s->checkType();
        if (curType == SpecialType::Academic || curType == SpecialType::Residence || curType == SpecialType::Gym) {
            Building* curB = s->getBuilding();
            f << curB->getName() << " " << curB->getOwner() << " " << curB->getImprovements() << "\n";
        }
    }
    f.close();
}

void theBoard::trade(Player* cur, Player *other, string give, string receive) {
    // check data type for each one
    int int1 = 0;
    int int2 = 0;

    stringstream check1{give};
    stringstream check2{receive};

    bool isBuilding1 = false;
    bool isBuilding2 = false;

    if (!(check1 >> int1)) {isBuilding1 = true;} // use string give
    if (!(check2 >> int2)) {isBuilding2 = true;} // use string receive

    // cases:
    // string int
    // string string
    // int string

    // if int int abort (edge case)

    bool building4money = false; 
    bool money4building = false;
    bool building4building = false;

    // Error Checking

    if ((isBuilding1== false) && (isBuilding2 == false)) {
        cout << "Trade Unsuccessful. Error: 'money -> money' invalid trade" << endl;
        return; // exit 
    } else if (isBuilding1 && !(isBuilding2)) { // building -> money: use give and int2
        // check enough money from other
        // check building belongs to cur
        // then check improvements
        // Keep track of offer.
        bool funds = false;
        bool ownsBuilding = false;
        bool noImprovements = false; // if false, abort

        if (other->money >= int2) { // other's money
            funds = true;
        } else {
            cout << "Trade Unsuccessful. Error: '" << other->name << ".money < receive' - "<< other->name << " does not have enough funds." << endl;
            return; // exit
        }

        // check if cur owns building
        // get index from squareorder (input in name) -> check if -1
        // squares[index].getbuilding->checkowner(curr) -> if true check improvements. 

        int buildingSquare = getInd(squareOrder, give);

        if (buildingSquare == -1) { // invalid building name
            cout << "Trade Unsuccessul. Building not found." << endl;
            return;
        }
        // buiding found 

        ownsBuilding = squares[buildingSquare]->getBuilding()->checkOwner(cur); // determines if owned or not.

        if (ownsBuilding) { // if owned then yes, if not abort
            cout << "Building is Owned by " << cur->name << "." << endl;
        } else {
            cout << "Trade Unsuccessful. Error: 'cur is not owner' - " << cur->name << " is not the owner of this building." << endl;
            return;
        }

        if (squares[buildingSquare]->getBuilding()->getImprovements() == 0) {
            noImprovements = true;
        } else {
            cout << "Trade Unsuccessful. Error: 'building improvements > 0' - Building cannot have any improvements." << endl;
            return;
        }

        if (noImprovements && ownsBuilding && funds) {
            cout << "Trade Sent Successfully" << endl;
            building4money = true; // give and int2 are valid 
        } else {
            cout << "Trade Unsuccessful. Error: 'Unknown' Something went wrong. Please try again." << endl;
            return; // exit
        }

    } else if (!(isBuilding1) && isBuilding2) { // money -> building: use int1 and receive
        // check enough money from cur
        // check building belongs to other
        // then check improvements
        // Keep track of offer.
        bool funds = false;
        bool ownsBuilding = false;
        bool noImprovements = false; // if false, abort

        if (cur->money >= int1) { // other's money
            funds = true;
        } else {
            cout << "Trade Unsuccessful. Error: '" << cur->name << ".money < give' - "<< cur->name << " does not have enough funds." << endl;
            return; // exit
        }

        // check if other owns building
        // get index from squareorder (input in name) -> check if -1
        // squares[index].getbuilding->checkowner(curr) -> if true check improvements. 

        int buildingSquare = getInd(squareOrder, receive);

        if (buildingSquare == -1) { // invalid building name
            cout << "Trade Unsuccessul. Building not found." << endl;
            return;
        }
        // buiding found 

        ownsBuilding = squares[buildingSquare]->getBuilding()->checkOwner(other); // determines if owned or not.

        if (ownsBuilding) { // if owned then yes, if not abort
            cout << "Building is Owned by " << other->name << "." << endl;
        } else {
            cout << "Trade Unsuccessful. Error: 'other is not owner' - " << other->name << " is not the owner of this building." << endl;
            return;
        }

        if (squares[buildingSquare]->getBuilding()->getImprovements() == 0) {
            noImprovements = true;
        } else {
            cout << "Trade Unsuccessful. Error: 'building improvements > 0' - Building cannot have any improvements." << endl;
            return;
        }

        if (noImprovements && ownsBuilding && funds) {
            cout << "Trade Sent Successfully" << endl;
            money4building = true; // give and int2 are valid 
        } else {
            cout << "Trade Unsuccessful. Error: 'Unknown' Something went wrong. Please try again." << endl;
            return; // exit
        }

    } else if ((isBuilding1== true) && (isBuilding2 == true)) { // building -> building: use give and receive
        // check enough money from cur
        // check building belongs to other
        // then check improvements
        // Keep track of offer.
        bool ownsBuilding1 = false;
        bool ownsBuilding2 = false;
        bool noImprovements1 = false; // if false, abort
        bool noImprovements2 = false; // if false, abort

        // check if cur owns building
        // get index from squareorder (input in name) -> check if -1
        // squares[index].getbuilding->checkowner(curr) -> if true check improvements. 

        int buildingSquare1 = getInd(squareOrder, give);

        if (buildingSquare1 == -1) { // invalid building name
            cout << "Trade Unsuccessul Building not found." << endl;
            return;
        }
        // buiding found 

        ownsBuilding1 = squares[buildingSquare1]->getBuilding()->checkOwner(cur); // determines if owned or not.

        if (ownsBuilding1) { // if owned then yes, if not abort
            cout << "Building is Owned by " << cur->name << "." << endl;
        } else {
            cout << "Trade Unsuccessful. Error: 'cur is not owner' - " << cur->name << " is not the owner of this building." << endl;
            return;
        }

        if (squares[buildingSquare1]->getBuilding()->getImprovements() == 0) {
            noImprovements1 = true;
        } else {
            cout << "Trade Unsuccessful. Error: 'building improvements > 0' - Building cannot have any improvements." << endl;
            return;
        }

        // now we check other's building (receive)

        int buildingSquare2 = getInd(squareOrder, receive);

        if (buildingSquare2 == -1) { // invalid building name
            cout << "Trade Unsuccessul Building not found." << endl;
            return;
        }
        // buiding found 

        ownsBuilding2 = squares[buildingSquare2]->getBuilding()->checkOwner(other); // determines if owned or not.

        if (ownsBuilding2) { // if owned then yes, if not abort
            cout << "Building is Owned by " << other->name << "." << endl;
        } else {
            cout << "Trade Unsuccessful. Error: 'cur is not owner' - " << other->name << " is not the owner of this building." << endl;
            return;
        }

        if (squares[buildingSquare2]->getBuilding()->getImprovements() == 0) {
            noImprovements2 = true;
        } else {
            cout << "Trade Unsuccessful. Error: 'building improvements > 0' - Building cannot have any improvements." << endl;
            return;
        }

        if ((ownsBuilding1 == true) && (ownsBuilding2 == true) && (noImprovements1 == true) && (noImprovements2 == true)) {
            cout << "Trade Sent Successfully" << endl;
            building4building = true; // receive and give are valid 
        } else {
            cout << "Trade Unsuccessful. Error: 'Unknown' Something went wrong. Please try again." << endl;
            return; // exit
        }
        
        
    } else { // invalid input or some other error
        cout << "Trade Unsuccessful. Error: 'Unknown' Something went wrong. Please try again." << endl;
        return; // exit
    }

    // this means successful trade sent, prompt for answer from receiver 

    cout << "Does " << other->name << " accept this trade? (enter 'accept' or 'reject')" << endl;
    string response;
    
    try { // EOF check
        while(true) { // checks for valid piece
            cin >> response;
            if (cin.eof()) {
                throw runtime_error("EOF reached");
                break;
            }

            if (response == "accept") {

                if (building4money) {
                    // exchanging money
                    other->money -= int2; 
                    cur->money += int2;

                    // detaching building from cur
                    int buildingSquare = getInd(squareOrder, give);
                    squares[buildingSquare]->getBuilding()->removeOwner(); // removing old owner;
                    cout << "Removed Owner" << endl;
                    squares[buildingSquare]->getBuilding()->setOwner(other);
                    cout << "Updated Owner" << endl;

                    // done
                    cout << "Trade Successful! Ending Trade." << endl;
                } else if (money4building) {
                    // exchanging money
                    other->money += int1; 
                    cur->money -= int1;

                    // detaching building from other
                    int buildingSquare = getInd(squareOrder, receive);
                    squares[buildingSquare]->getBuilding()->removeOwner(); // removing old owner;
                    cout << "Removed Owner" << endl;
                    squares[buildingSquare]->getBuilding()->setOwner(cur);
                    cout << "Updated Owner" << endl;

                    // done
                    cout << "Trade Successful! Ending Trade." << endl;
                } else if (building4building) {
                    // detaching building from cur
                    int buildingSquare1 = getInd(squareOrder, give);
                    squares[buildingSquare1]->getBuilding()->removeOwner(); // removing old owner;
                    cout << "Removed Owner" << endl;
                    squares[buildingSquare1]->getBuilding()->setOwner(other);
                    cout << "Updated Owner" << endl;

                     // detaching building from other
                    int buildingSquare2 = getInd(squareOrder, receive);
                    squares[buildingSquare2]->getBuilding()->removeOwner(); // removing old owner;
                    cout << "Removed Owner" << endl;
                    squares[buildingSquare2]->getBuilding()->setOwner(cur);
                    cout << "Updated Owner" << endl;

                     // done
                    cout << "Trade Successful! Ending Trade." << endl;
                } else {
                    cout << "Trade Unsuccessful. Error: 'Unknown' Something went wrong. Please try again." << endl;
                }

                return;
            } else if (response == "reject") {
                cout << other->name << " has rejected your trade. Ending Trade." << endl;
                return;
            } else {
                cout << "Please enter either 'accept' or 'reject'." << endl;
            }
        }
    } catch (const exception& e) {
        cout << "EOF encountered. Trade Unsucessful" << endl;
        return;
    }
}

void theBoard::mortgage(Player* cur, string b) {
    int buildingSquare = getInd(squareOrder, b);
    if (buildingSquare == -1) {
        cout << "Building not found" << endl;
        return;
    }
    Building* building = squares[buildingSquare]->getBuilding();
    if (building->getImprovements() != 0) {
        cout << "Buildings with Improvements cannot be mortgaged, please sell all Improvements first" << endl;
    } else if (!building->checkOwner(cur)) {
        cout << "You do not own this Building." << endl;
    } else {
        building->mortgaged = true;
        cur->money += building->getCost() * 0.5;
    }
}

void theBoard::unmortgage(Player* cur, string b) {
    int buildingSquare = getInd(squareOrder, b);
    if (buildingSquare == -1) {
        cout << "Building not found" << endl;
        return;
    }
    Building* building = squares[buildingSquare]->getBuilding();
    if (!building->checkOwner(cur)) {
        cout << "You do not own this Building." << endl;
    } else if (!building->mortgaged) {
        cout << "This Building is not mortgaged." << endl;
    } else if (building->getCost() * 0.6 > cur->money) {
        cout << "You do not have enough money to unmortgage this Building." << endl;
    } else {
        building->mortgaged = false;
        cur->money -= building->getCost() * 0.6;
    }
}

void theBoard::assets(Player* cur) {
    cout << cur->name << "'s assets:" << endl;
    cout << "Money: " << cur->money << endl;
    cout << "Tims Cups: " << cur->timsCups << endl;
    cout << "Owned Buildings: ";
    for (size_t i = 0; i < cur->acb.size(); ++i) {
        for (auto ac : cur->acb[i]) {
            if (!ac->mortgaged) cout << ac->getName() << " ";
        }
    }
    for (auto res : cur->resb) {
        if (!res->mortgaged) cout << res->getName() << " ";
    }
    for (auto gym : cur->gymb) {
        if (!gym->mortgaged) cout << gym->getName() << " ";
    }
    cout << endl;
}

void theBoard::all() {
    for (auto p : players) {
        this->assets(p);
    }
}

/* void theBoard::bankrupt(Player* cur, Player* owed) {
    // if possible replace the money exchanges with charge functions
    if (owed == bank) {
        cur->money = 0;
        for (size_t i = 0; i < cur->acb.size(); ++i) {
            for (auto ac : cur->acb[i]) {
                ac->mortgaged = false;
                ac->setOwner(bank);
                this->auction(ac);
            }
        }
        for (auto res : cur->resb) {
            res->mortgaged = false;
            res->setOwner(bank);
            this->auction(res);
        }
        for (auto gym : cur->gymb) {
            gym->mortgaged = false;
            gym->setOwner(bank);
            this->auction(gym);
        }
    } else {
        owed->money += cur->money;
        cur->money = 0;
        for (size_t i = 0; i < cur->acb.size(); ++i) {
            for (auto ac : cur->acb[i]) {
                if (ac->mortgaged) {
                    owed->money -= ac->getCost() * 0.1;
                    cout << "Would you like to unmortgage ";
                    cout << ac->getName() << "? {y / n}" << endl;
                    string resp;
                    cin >> resp;
                    if (resp == "y") {
                        owed->money -= ac->getCost() * 0.5;
                        ac->mortgaged = true;
                    }
                }
                ac->setOwner(owed);
                this->auction(ac);
            }
        }
        for (auto res : cur->resb) {
            if (res->mortgaged) {
                owed->money -= res->getCost() * 0.1;
                cout << "Would you like to unmortgage ";
                cout << res->getName() << "? {y / n}" << endl;
                string resp;
                cin >> resp;
                if (resp == "y") {
                    owed->money -= res->getCost() * 0.5;
                    res->mortgaged = true;
                }
            }
            res->setOwner(owed);
            this->auction(res);
        }
        for (auto gym : cur->gymb) {
            if (gym->mortgaged) {
                cout << "Would you like to unmortgage ";
                cout << gym->getName() << "? {y / n}" << endl;
                string resp;
                cin >> resp;
                if (resp == "y") {
                    owed->money -= gym->getCost() * 0.5;
                    gym->mortgaged = true;
                }
                owed->money -= gym->getCost() * 0.1;
            }
            gym->setOwner(owed);
            this->auction(gym);
        }
    }
} */

ostream &operator<<(ostream &out, const theBoard &b) {
    out << *b.td;
    return out;
}




