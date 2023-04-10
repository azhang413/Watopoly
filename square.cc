#include "square.h"
#include "player.h"
#include "building.h"

Building* Square::getBuilding() {
    return b;
}

SpecialType Square::checkType() {
    return type;
}

Square::~Square() {
    delete b;
}

Info Square::getInfo() const{
    Info i{BuildingRow, BuildingCol, PlayerRow, PlayerCol}; // construct without vector.
    for (auto it: this->players) { // adding to vector
        i.players.push_back(it->p); // turn players into character pieces (encapsulation)
    }

    i.improvements = b->getImprovements();

    return i;
}

