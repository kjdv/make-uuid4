#include <fmt/format.h>
#include <random>
#include <uuid4.h>

namespace uuid4 {
namespace {

std::random_device generator;

template <typename T>
T random() {
    static_assert(sizeof(T) <= sizeof(std::random_device::result_type), "T too large");
    return static_cast<T>(generator());
}

}

Uuid make_uuid4()
{
    Uuid u{
        random<uint32_t>(),
        random<uint16_t>(),
        random<uint16_t>(),
        random<uint8_t>(),
        random<uint8_t>(),
        random<uint32_t>(),
        random<uint16_t>(),
    };

    u.clock_seq_hi_and_reserved &= ~(1 << 6);
    u.clock_seq_hi_and_reserved |= 1 << 7;

    u.time_hi_and_version &= ~((1 << 15) | (1 << 13) | (1 << 12));
    u.time_hi_and_version |= 1 << 14;

    return u;
}

std::ostream& operator<<(std::ostream& out, const Uuid& u)
{
    using fmt::format;

    return out
           << format("{:08x}-{:04x}-{:04x}-{:02x}{:02x}-{:08x}{:04x}",
                     u.time_low,
                     u.time_mid,
                     u.time_hi_and_version,
                     u.clock_seq_hi_and_reserved,
                     u.clock_seq_low,
                     u.node1,
                     u.node2);
}

} // namespace uuid4
