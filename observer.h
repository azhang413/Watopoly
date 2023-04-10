#ifndef __OBSERVER_H__
#define __OBSERVER_H__

template<typename Info> class Subject;

template<typename Info> class Observer {
    public:
    virtual void notify(Subject<Info> &s) = 0;
    virtual ~Observer() {}
};

#endif
