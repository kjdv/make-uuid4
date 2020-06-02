#pragma once

#include <cstdint>
#include <array>
#include <ostream>

namespace uuid4 {

struct Uuid {
    uint32_t time_low;
    uint16_t time_mid;
    uint16_t time_hi_and_version;
    uint8_t clock_seq_hi_and_reserved;
    uint8_t clock_seq_low;
    uint32_t node1;
    uint16_t node2;
};

Uuid make_uuid4();

std::ostream &operator<<(std::ostream &out, const Uuid &u);

}
