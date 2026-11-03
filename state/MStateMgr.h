#pragma once

#include <state/MStateFct.h>
#include <state/StateMgr.h>

template <typename T>
class MStateMgr : public StateMgr<T, MStateFct> {
public:
    MStateMgr(T& obj, const StateID& state_id = stateID::null)
        : StateMgr<T, MStateFct>(obj, state_id)
    { }

    ~MStateMgr() override { }
};
