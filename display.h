#ifndef DISPLAY_H
#define DISPLAY_H
#include <vector>
#include <fstream>
//#include "observer.h"

class Subject;

class Display : /*public Observer*/ {
        std::vector<std::vector<char>> text;
    public:
        Display();
     //   void notify(Subject &whomFrom) override;
        friend std::ostream &operator<<(std::ostream &out, const Display &dis);
};



#endif