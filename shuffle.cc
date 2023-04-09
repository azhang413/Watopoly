#include "shuffle.h"
#include<algorithm>
#include <chrono>

using namespace std;

Shuffle::Shuffle(vector<int> v):  v{v} {   
    unsigned gen = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng{gen};
    seed = rng;
}

int Shuffle::roll () {
    std::shuffle( v.begin(), v.end(), seed );
    return v.at(0);
}
