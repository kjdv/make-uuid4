#pragma once

#include <cstdint>
#include <array>

namespace uuid4 {

struct Uuid {
    uint32_t time_low;
    uint16_t time_mid;
    uint16_t time_hi_and_version;
    uint8_t clock_seq_hi_and_reserved;
    uint8_t clock_seq_low;
    uint64_t node;
};

Uuid make_uuid4();

}
