#include "square.h"
#include "player.h"
#include "building.h"
#include "observer.h"

Building* Square::getBuilding() {
    return b;
}

SpecialType Square::checkType() {
    return type;
}

void Square::addPlayer(Player* p) {
    players.emplace_back(p);
    this->notifyObservers();
}

void Square::removePlayer(Player* p) {
    for (auto i = players.begin(); i != players.end(); ++i) {
        if (*i == p) {
            players.erase(i);
            break;
        }
    }
    this->notifyObservers();
}

Square::~Square() {
    delete b;
}

Info Square::getInfo() const{
    Info i{BuildingRow, BuildingCol, PlayerRow, PlayerCol}; // construct without vector.
    for (auto it: this->players) { // adding to vector
        i.players.push_back(it->p); // turn players into character pieces (encapsulation)
    }

    if (type == SpecialType::Academic || type == SpecialType::Residence || type == SpecialType::Gym) {
        i.improvements = b->getImprovements();
    } else {
        i.improvements = -1;
    }
        

    return i;
}

