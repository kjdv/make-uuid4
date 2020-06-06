#include <fmt/format.h>
#include <random>
#include <uuid4.h>

namespace uuid4 {
namespace {

std::random_device generator;

template <typename T = std::random_device::result_type>
T random()
{
    static_assert(sizeof(T) <= sizeof(std::random_device::result_type), "T too large");
    return static_cast<T>(generator());
}

} // namespace

Uuid make_uuid4()
{
    return Uuid{
        random<uint32_t>(),
        random<uint16_t>(),
        static_cast<uint16_t>((random() & ~((1 << 15) | (1 << 13) | (1 << 12))) | (1 << 14)),
        static_cast<uint8_t>((random() & ~(1 << 6)) | (1 << 7)),
        random<uint8_t>(),
        random<uint32_t>(),
        random<uint16_t>(),
    };
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
