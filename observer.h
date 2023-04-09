#ifndef __OBSERVER_H__
#define __OBSERVER_H__

class Square;

class Observer {
    public:
        virtual void notify(Square * sq) = 0;
        ~Observer();
};

#endif