#pragma once

#include <state/StateMethod.h>
#include <state/StateIDHolder.h>

class MultipleStateMethod : public StateMethod {
public:
    // Address: 0x60818290
    void changeToSubStateMethod(const StateID& state_id);
    
public:
    bool isSubStateMethod() const {
        return mMain.isSet();
    }

    void returnStateMethod() {
        mOldStateID = mState->getID();
        mFactory.dispose(mState);
        const StateID& main_state_id = *(mMain.get());
        mMain.reset();
        mState = mFactory.build(main_state_id);
    }

    void replaceStateMethod(const StateID& state_id) {
        mFactory.dispose(mState);
        mState = mFactory.build(state_id);
    }

    const StateID* getMainStateID() const {
        const StateID* state_id = mMain.get();
        if (state_id == nullptr) {
            state_id = getStateID();
        }
        return state_id;
    }

private:
    StateIDHolder mMain;
};
SIZE_ASSERT(MultipleStateMethod, 0x14);
