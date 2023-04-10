#include "building.h"
#include "shuffle.h" // for gym
#include "player.h"
#include <map>
#include <exception>
#include <iostream> //delete after

using namespace std;

class WTH {
        string m_message;
    public:
        WTH(const string & message) : m_message(message) {} 
        const string message() const {
            return m_message;
        }
};

int Building::getImprovements() const {
    return 0;
}

bool Building::checkOwner(Player * curr) const {
    return owner == curr;
}

void Building::setCost(int cost) {
    this->cost = cost;
}

string Building::getName() const {
    return this->name;
}

string Building::getOwner() const {
    return this->owner->name;
}

int Building::getCost() {
    return this->cost;
}

// Academic

// 2 maps:
// construction
// improvements (for decorator)


// name -> [type,purchase, improvement]
map<string, vector<int>> construct = {
    //A1
    {"AL", {1, 40, 50}},
    {"ML", {1, 60, 50}},
    // A2
    {"ECH", {2, 100, 50}},
    {"PAS", {2, 100, 50}},
    {"HH", {2, 120, 50}},
    // ENG
    {"RCH", {3, 140, 100}},
    {"DWE", {3, 140, 100}},
    {"CPH", {3, 160, 100}},
    // HLTH
    {"LHI", {4, 180, 100}},
    {"BMH", {4, 180, 100}},
    {"OPT", {4, 220, 100}},
    // ENV
    {"EV1", {5, 220, 150}},
    {"EV2", {5, 220, 150}},
    {"EV3", {5, 240, 150}},
    // S1
    {"PHYS", {6, 260, 150}},
    {"B1", {6, 260, 150}},
    {"B2", {6, 280, 150}},
    // S2
    {"EIT", {7, 300, 200}},
    {"ESC", {7, 300, 200}},
    {"C2", {7, 320, 200}},
    // MATH
    {"MC", {8, 350, 200}},
    {"DC", {8, 400, 200}}
};

map<int,Monopoly> intToMono = {
    {1,Monopoly::A1},
    {2,Monopoly::A2},
    {3,Monopoly::ENG},
    {4,Monopoly::HLTH},
    {5,Monopoly::ENV},
    {6,Monopoly::S1},
    {7,Monopoly::S2},
    {8,Monopoly::MATH}
};

map<string, vector<int>> improveMap = {
    //A1
    {"AL", {2, 10, 30,90,160,250}},
    {"ML", {4, 20, 60,180,320,450}},
    // A2
    {"ECH", {6, 30, 90,270,400,550}},
    {"PAS", {6, 30, 90,270,400,550}},
    {"HH", {8, 40, 100,300,450,600}},
    // ENG
    {"RCH", {10, 50, 150,450,625,750}},
    {"DWE", {10, 50, 150,450,625,750}},
    {"CPH", {12, 60, 180,500,700,900}},
    // HLTH
    {"LHI", {14, 70, 200,550,750,960}},
    {"BMH", {14, 70, 200,550,750,960}},
    {"OPT", {16, 80, 220,600,800,1000}},
    // ENV
    {"EV1", {18, 90, 250,700,875,1050}},
    {"EV2", {18, 90, 250,700,875,1050}},
    {"EV3", {20, 100, 300,750,925,1100}},
    // S1
    {"PHYS", {22, 110, 330,800,975,1150}},
    {"B1", {22, 110, 330,800,975,1150}},
    {"B2", {24, 120, 360,850,1025,1200}},
    // S2
    {"EIT", {26, 130, 390,900,1100,1275}},
    {"ESC", {26, 130, 390,900,1100,1275}},
    {"C2", {28, 150, 450,1000,1200,1400}},
    // MATH
    {"MC", {35, 175, 500,1100,1300,1500}},
    {"DC", {50, 200, 600,1400,1700,2000}}
};

int Building::nameToMono(string name) {
    return construct[name][0];
}

void Academic::buyImprovements(int numOfImprovements) { // board checks monopoly
    if ((improvements + numOfImprovements) > 5) {
        throw WTH("Number of Improvements Exceeds 5");
    } else if (owner->money < (numOfImprovements * improveCost)) {
        throw WTH("Cannot Afford Improvements");
    } else {
        improvements += numOfImprovements; // increase improvements
        owner->money -= numOfImprovements * improveCost; // subtract owner's money
        string name = getName(); // gets name of building
        tuition = improveMap[name][improvements]; // update tuition
    }
}

int Academic::getImprovements() const {
    return improvements;
}

Academic::~Academic() {}

void Academic::sellImprovements(int numOfImprovements) { // board checks monopoly
    if (improvements == 0) {
        throw WTH("No Improvements to Sell");
    } else if (improvements < numOfImprovements) {
        throw WTH("Not Enough Improvements Owned");
    } else {
        improvements -= numOfImprovements; // decrease improvements
        owner->money += numOfImprovements * (improveCost/2); // subtract owner's money
        string name = getName(); // gets name of building
        tuition = improveMap[name][improvements]; // update tuition
    }
}

void Academic::setOwner(Player* buyer) {
    owner = buyer; // buyer -> owner
     // adds current residence to owner's list of owned residences
    int index = construct[getName()][0] - 1;
    buyer->acb[index].push_back(this); // put into correct monopoly
}

void Academic::removeOwner() {
    if (owner == nullptr) {return;} // do nothing

    // remove from owner's owned vector 
    int index = construct[getName()][0] - 1;
    for (auto i = owner->acb[index].begin(); i != owner->acb[index].end(); ++i) {
        if (&(**i) == &(*this)) { // found, remove
            owner->acb[index].erase(i);
        }
    }
    // set to nullptrs
    owner = nullptr;
}

int Academic::getCharge() const {
    return tuition; // add to owner's money
}



Academic::Academic (const string name, int improvements) : Building{name}, improvements{improvements} {
    m = intToMono[construct[name][0]]; // const
    this->setCost(construct[name][1]); // const but priv
    improveCost = construct[name][2]; // const
    tuition = improveMap[name][improvements];
}



// Residences

void Residence::setOwner(Player* buyer) {
    Building::owner = buyer; // buyer -> owner
    owner->resb.push_back(this); // adds current residence to owner's list of owned residences
    int setRent = 0; // what rent should be (depends on # of res)
    
    switch(owner->resb.size()) { // for each # of residence, set rent accordingly
        case 1:
            setRent = 25;
            break;
        case 2:
            setRent = 50;
            break;
        case 3:
            setRent = 100;
            break;
        case 4:
            setRent = 200;
            break;
        default:
            setRent = 25;
    }

    for (auto i: owner->resb) { // loops through residence vector and sets rent for each residence
        i->rent = setRent;
    }
}

int Residence::getCharge() const {
    return rent;
}

void Residence::removeOwner() {
    if (owner == nullptr) {return;} // do nothing

    // remove from owner's owned vector 
    for (auto i = owner->resb.begin(); i !=  owner->resb.end(); ++i) {
        if (&(**i) == &(*this)) { // found, remove
             owner->resb.erase(i);
        }
    }
    // set to nullptrs
    owner = nullptr;
}

Residence::Residence(const string name): Building{name, 200} {}

// Gym

void Gym::setOwner(Player* buyer) {
    Building::owner = buyer; // buyer -> owner
    owner->gymb.push_back(this); // adds current gym to owner's owned gyms
    int setMult = 0;

    switch (owner->gymb.size())
    {
    case 1:
        setMult = 4; 
        break;
    
    case 2:
        setMult = 10; 
        break;
    }

    for (auto i: owner->gymb) { // loops through gyms and sets multiplier for each gym
        i->multiplier = setMult;
    }

}

int Gym::getCharge() const {
    vector<int> diceVec{1,2,3,4,5,6};
    Shuffle Dice1{diceVec};
    Shuffle Dice2{diceVec};

    int val1 = Dice1.roll();
    int val2 = Dice2.roll();

    int amount = (val1 + val2) * multiplier;

    return amount;

}

void Gym::removeOwner() {
    if (owner == nullptr) {return;} // do nothing

    // remove from owner's owned vector 
    for (auto i = owner->gymb.begin(); i !=  owner->gymb.end(); ++i) {
        if (&(**i) == &(*this)) { // found, remove
             owner->gymb.erase(i);
        }
    }
    // set to nullptrs
    owner = nullptr;
}

Gym::Gym(const string name): Building{name, 150} {}
