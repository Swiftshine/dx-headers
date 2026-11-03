#pragma once

#include <state/MStateID.h>
#include <state/StateIf.h>

template <typename T>
class MState : public StateIf {
public:
    MState(T& obj)
        : mObject(obj)
        , mStateID(nullptr)
    { }

    const StateID* getID() const override {
        return mStateID;
    }

    void execute() override {
        mStateID->execute();
    }
public:
    T& getObject() const {
        return mObject;
    }

    void setID(const MStateID<T>* state_id) {
        mStateID = state_id;
    }

    void initialize() {
        mStateID->initialize();
    }

    void finalize() {
        mStateID->finalize();
    }
private:
    T& mObject;
    const MStateID<T>* mStateID;    
};
SIZE_ASSERT_TEMPLATED(MState, 0xC);
