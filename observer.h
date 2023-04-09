#ifndef __OBSERVER_H__
#define __OBSERVER_H__

template <typename InfoType> class Subject;

template <typename InfoType> class Observer {
    public:
    virtual void notify(Subject<InfoType> &s) = 0;
    virtual ~Observer() {}
};

#endif
