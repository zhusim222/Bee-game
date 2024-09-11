// Subject.h
#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
class Observer;
class Obstacle;

class Subject {
public:
    virtual ~Subject() {}
    virtual void attach(Observer* observer);
    virtual void detach(Observer* observer);
    virtual void notify(Observer* observer);
};

#endif  // SUBJECT_H