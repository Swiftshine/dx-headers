#pragma once

#include <Types.h>

// vtable Address: 0x60C2A0AC
class StateID {
public:
    static constexpr s32 cNullNumber = -1;
public:
    explicit StateID(s32 number)
        : mNumber(number)
    { }

    virtual ~StateID() { }

    virtual s32 number() const;

public:
    bool isNull() const {
        return mNumber == cNullNumber;
    }

    bool isEqual(const StateID& rhs) const {
        return number() == rhs.number();
    }

    bool operator==(const StateID& rhs) const {
        return isEqual(rhs);
    }

    bool operator!=(const StateID& rhs) const {
        return !isEqual(rhs);
    }

protected:
    s32 mNumber;
};
SIZE_ASSERT(StateID, 0x8);

namespace stateID {
    // Address: 0x60C2A09C
    static const StateID null(StateID::cNullNumber);
}
