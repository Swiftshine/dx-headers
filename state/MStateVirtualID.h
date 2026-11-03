#pragma once

#include <state/MStateID.h>

template <typename T>
class MStateVirtualID : public MStateID<T> {
public:
    using FunctionPtr = MStateID<T>::FunctionPtr;

public:
    MStateVirtualID(FunctionPtr initialize, FunctionPtr execute, FunctionPtr finalize, const StateID& super_id)
        : MStateID<T>(initialize, execute, finalize)
        , mSuperID(&super_id)
    { }

    ~MStateVirtualID() override { }

    s32 number() const override {
        if (!mSuperID->isNull()) {
            return mSuperID->number();
        }

        return this->mNumber;
    }

public:
    const StateID* getSuperID() const {
        return mSuperID;
    }

protected:
    const StateID* mSuperID;
};

#define DECLARE_STATE_VIRTUAL_ID_BASE(CLASS, NAME)          \
    static MStateVirtualID<CLASS> StateID_##NAME;           \
    virtual void initializeState_##NAME();                  \
    virtual void executeState_##NAME();                     \
    virtual void finalizeState_##NAME();

#define DECLARE_STATE_VIRTUAL_ID_OVERRIDE(CLASS, NAME)      \
    static MStateVirtualID<CLASS> StateID_##NAME;           \
    void initializeState_##NAME() override;                 \
    void executeState_##NAME() override;                    \
    void finalizeState_##NAME() override;

#define CREATE_STATE_VIRTUAL_ID_BASE(CLASS, NAME)           \
    MStateVirtualID<CLASS> CLASS::StateID_##NAME            \
        (&CLASS::initializeState_##NAME,                    \
         &CLASS::executeState_##NAME,                       \
         &CLASS::finalizeState_##NAME,                      \
         StateID::cNull);

#define CREATE_STATE_VIRTUAL_ID_OVERRIDE(CLASS, BASE, NAME) \
    MStateVirtualID<CLASS> CLASS::StateID_##NAME            \
        (&CLASS::initializeState_##NAME,                    \
         &CLASS::executeState_##NAME,                       \
         &CLASS::finalizeState_##NAME,                      \
         BASE::StateID_##NAME);
