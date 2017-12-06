#include <cinttypes>
#include "enum_flag.h"

enum class e0 : int8_t {
    e00 = 1,
    e01,
    e02 = 4,
};
template<> struct is_flag<e0> :std::true_type{};

enum e1 {
    e10 = 1,
    e11,
    e12 = 4,
};
template<> struct is_flag<e1> :std::true_type{};

int main() {
    e0 e = e0::e00;
    e &= e0::e02;
    e |= ~e0::e01;
    static_assert(test_flag(e0::e00 & ~e0::e01), "e0");
    static_assert(e1::e10 & ~e1::e11, "e1");
}

