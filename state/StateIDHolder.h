#pragma once

#include <Types.h>

class StateID;

// Unofficial name
class StateIDHolder {
public:
    StateIDHolder() {
        reset();
    }

    void set(const StateID*state_id) {
        mStateID = state_id;
    }

    void reset() {
        mStateID = nullptr;
    }

    bool isSet() const {
        return mStateID != nullptr;
    }

    const StateID* get() const {
        return mStateID;
    }
private:
    const StateID* mStateID;
};
SIZE_ASSERT(StateIDHolder, 4);
