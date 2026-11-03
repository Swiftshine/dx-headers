#pragma once

#include <Types.h>

class StateID;

class StateIf {
public:
    StateIf() { }
    virtual ~StateIf() { }

    virtual const StateID* getID() const = 0;
    virtual void execute() = 0;
};
