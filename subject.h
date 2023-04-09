#ifndef __SUBJECT_H__
#define __SUBJECT_H__
#include <vector>

template <typename InfoType> class Observer;

template <typename InfoType> class Subject {
    std::vector<Observer<InfoType>*> observers;
    public:
        void attach(Observer *o) { observers.push_back(o); }
        void notifyObservers() { for (auto o: observers) o->notify(*this); }
        virtual InfoType getInfo() const = 0;
        virtual ~Subject() {}
};

#endif
