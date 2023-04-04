#ifndef __SUBJECT_H__
#define __SUBJECT_H__
#include <vector>

class Observer;

Class Subject {
    std::vector<Observer*> observers;
    public:
        void attach(Observer *o) { observers.push_back(o); }
        void notifyObservers() { for (auto o: observers) o->notify(); }
        virtual ~Subject() {}
}
#endif
