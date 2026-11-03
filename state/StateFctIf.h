#pragma once

#include <state/StateIf.h>

class StateFctIf {
public:
    StateFctIf() { }
    virtual ~StateFctIf() { }

    virtual StateIf* build(const StateID& state_id) = 0;
    virtual void dispose(StateIf*& state) = 0;
    virtual StateIf* wakeup(const StateID& state_id) = 0;
    virtual void sleep(StateIf*& state) = 0;
    virtual void resetState(StateIf*& state) = 0;
};
