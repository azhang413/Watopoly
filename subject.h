#ifndef __SUBJECT_H__
#define __SUBJECT_H__
#include <vector>

template<typename Info> class Observer;

template<typename Info> class Subject {
    std::vector<Observer<Info>*> observers;
    public:
        void attach(Observer<Info>* o);
        void notifyObservers();
        virtual Info getInfo() const = 0;
        virtual ~Subject() {};
};

template<typename Info>
void Subject<Info>::attach(Observer<Info> *o) {
    observers.emplace_back(o);
}

template<typename Info>
void Subject<Info>::notifyObservers() { 
    for (auto &o: observers) o->notify(*this); 
}

#endif
