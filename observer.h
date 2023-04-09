#ifndef __OBSERVER_H__
#define __OBSERVER_H__

class Square;

class Observer {
    public:
    virtual void notify() = 0;
    virtual ~Observer() {}
};

#endif
