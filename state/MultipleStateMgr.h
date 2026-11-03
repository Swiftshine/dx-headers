#pragma once

#include <state/MultipleStateMethod.h>
#include <state/StateMgr.h>

template <typename T, template <typename FactoryT> class Factory>
class MultipleStateMgr {
    STATE_MGR_BASE_BODY(MultipleStateMgr, MultipleStateMethod)
public:
    void changeToSubState(const StateID& state_id) {
        mMethod.changeToSubStateMethod(state_id);
    }

    bool isSubState() const {
        mMethod.isSubStateMethod();
    }

    void returnState() {
        mMethod.returnStateMethod();
    }

    void replaceState(const StateID& state_id) {
        mMethod.replaceStateMethod(state_id);
    }

    const StateID* getMainStateID() const {
        return mMethod.getMainStateID();
    }
};
