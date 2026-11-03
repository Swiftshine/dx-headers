#pragma once

#include <state/StateID.h>

template <typename T>
class MStateID : public StateID {
public:
    using FunctionPtr = void (T::*)();

public:
    MStateID(FunctionPtr initialize, FunctionPtr execute, FunctionPtr finalize)
        : mInitialize(initialize)
        , mExecute(execute)
        , mFinalize(finalize)
    { }

    ~MStateID() override { }

    void initialize(T& obj) const {
        (obj.*mInitialize)();
    }

    void execute(T& obj) const {
        (obj.*mExecute)();
    }

    void finalize(T& obj) const {
        (obj.*mFinalize)();
    }
    
protected:
    FunctionPtr mInitialize;
    FunctionPtr mExecute;
    FunctionPtr mFinalize;
};
SIZE_ASSERT_TEMPLATED(MStateID, 0x20);

#define DECLARE_STATE_ID(CLASS, NAME)       \
    static MStateID<CLASS> StateID_##NAME;  \
    void initializeState_##NAME();          \
    void executeState_##NAME();             \
    void finalizeState_##NAME();

#define CREATE_STATE_ID(CLASS, NAME)        \
    MStateID<CLASS> CLASS::StateID_##NAME   \
        (&CLASS::initializeState_##NAME,    \
         &CLASS::executeState_##NAME,       \
         &CLASS::finalizeState_##NAME);


#define DECLARE_STATE_ID_VIRTUAL_FUNC_OVERRIDE(CLASS, NAME) \
    static MStateID<CLASS> StateID_##NAME;                  \
    void initializeState_##NAME() override;                 \
    void executeState_##NAME() override;                    \
    void finalizeState_##NAME() override;
