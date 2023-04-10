#ifndef __SUBJECT_H__
#define __SUBJECT_H__
#include <vector>

template<typename Info> class Observer;

template<typename Info> class Subject {
    std::vector<Observer*> observers;
    public:
        void attach(Observer *o) { observers.push_back(o); }
        void notifyObservers() { for (auto o: observers) o->notify(*this); }
        virtual Info getInfo() const = 0;
};

#endif
