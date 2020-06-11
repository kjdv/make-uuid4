#pragma once

#include <cstdint>
#include <array>
#include <ostream>

namespace uuid4 {

struct Uuid {
    uint64_t
        time_low : 32,
        time_mid : 16,
        time_hi_and_version : 16;
    uint64_t
        clock_seq_hi_and_reserved : 8,
        clock_seq_low : 8,
        node : 48;
};

static_assert(sizeof(Uuid) == 16, "should be 128 bits");

Uuid make_uuid4();

std::ostream &operator<<(std::ostream &out, const Uuid &u);

}
