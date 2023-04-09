#ifndef DISPLAY_H
#define DISPLAY_H
#include <vector>
#include <fstream>
#include "observer.h"
#include "info.h"

class Square;

class Display : public Observer<Info> {
        std::vector<std::vector<char>> text;
    public:
        Display();
        void notify(Subject<Info> &s) override;
        friend std::ostream &operator<<(std::ostream &out, const Display &dis);
};





#endif
