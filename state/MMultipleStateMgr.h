#pragma once

#include <state/MultipleStateMgr.h>
#include <state/MStateFct.h>

template <typename T>
class MMultipleStateMgr : public MultipleStateMgr<T, MStateFct> {
public:
    MMultipleStateMgr(T& obj, const StateID& state_id = stateID::null)
        : MultipleStateMgr<T, MStateFct>(obj, state_id)
    { }

    ~MMultipleStateMgr() override { };
};
