#pragma once

#include <state/MState.h>
#include <state/StateFctIf.h>

template <typename T>
class MStateFct : public StateFctIf {
public:
    MStateFct(T& obj)
        : mState(obj)
    { }

    ~MStateFct() override { }

    StateIf* build(const StateID& state_id) override {
        mState.setID(static_cast<const MStateID<T>*>(&state_id));
        mState.initialize();
        return &mState;
    }

    void dispose(StateIf*& state) override {
        mState.finalize();
        mState.setID(nullptr);
        state = nullptr;
    }

    StateIf* wakeup(const StateID& state_id) override {
        mState.setID(static_cast<const MStateID<T>*>(&state_id));
        return &mState;
    }

    void sleep(StateIf*& state) override {
        mState.setID(nullptr);
        state = nullptr;
    }

    void resetState(StateIf*& state) override {
        static_cast<MState<T>*>(state)->initialize();
    }

private:
    MState<T> mState;
};
