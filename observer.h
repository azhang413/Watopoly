#ifndef __OBSERVER_H__
#define __OBSERVER_H__

class Observer {
    virtual void notify() = 0;
    void ~Observer() {}
}

#endif