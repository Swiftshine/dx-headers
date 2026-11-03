#pragma once

using u32 = unsigned int;
using s32 = signed int;
using u16 = unsigned short;
using s16 = signed short;
using u8  = unsigned char;
using s8  = signed char;
using f32 = float;
static_assert(sizeof(f32) == 4);

#define SIZE_ASSERT(C, S) \
    static_assert(sizeof(C) == S, #C " size mismatch")

#define SIZE_ASSERT_TEMPLATED_HELPER(C, S, CNT) \
    namespace { struct Dummy_##CNT {}; } \
    SIZE_ASSERT(C<Dummy_##CNT>, S)

#define SIZE_ASSERT_TEMPLATED_IMPL(C, S, CNT) \
    SIZE_ASSERT_TEMPLATED_HELPER(C, S, CNT)

#define SIZE_ASSERT_TEMPLATED(C, S) \
    SIZE_ASSERT_TEMPLATED_IMPL(C, S, __COUNTER__)
