#pragma once

using u32 = unsigned int;
using s32 = signed int;
using u16 = unsigned short;
using s16 = signed short;
using u8  = unsigned char;
using s8  = signed char;
using f32 = float;
static_assert(sizeof(f32) == 4);

// Making this a macro to account for potential 64-bit support
#define SIZE_ASSERT(C, S) \
    static_assert(sizeof(C) == S, #C " size mismatch")
