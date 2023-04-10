#ifndef __SHUFFLE_H__
#define __SHUFFLE_H__
#include<vector>
#include<random>

// if no seed is given, must generate random seed for each call

class Shuffle { // Dice.roll() (constant vector in main)
    private:
        std::vector<int> v; // 
        std::default_random_engine seed; 
    public:
        Shuffle(std::vector<int> v, std::default_random_engine seed): v{v}, seed{seed} {}
        Shuffle(std::vector<int> v); // if no random seed, generate
        int roll();
        
};

#endif