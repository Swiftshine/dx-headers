#pragma once

#include <state/StateID.h>
#include <state/StateIf.h>
#include <state/StateFctIf.h>

class StateMethod {
public:
    // Address: 0x60818168
    StateMethod(StateFctIf& state_factory, const StateID& state_id);

    // Address: 0x60818198
    StateID* getStateID() const;

    // Address: 0x608181D4
    void executeMethod();

    // Address: deleted
    void finalizeMethod();

    // Address: 0x60818224
    void changeMethod(const StateID& state_id);

public:
    const StateID* getNewStateID() const {
        return mNewStateID;
    }

    StateIf* getState() const {
        return mState;
    }
    
    const StateID* getOldStateID() const {
        return mOldStateID;
    }

protected:
    StateFctIf& mFactory;
    const StateID* mNewStateID;
    StateIf* mState;
    const StateID* mOldStateID;
};
SIZE_ASSERT(StateMethod, 0x10);
