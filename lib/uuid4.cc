#include <algorithm>
#include <fmt/format.h>
#include <random>
#include <uuid4.h>

namespace uuid4 {
namespace {

std::random_device generator;

} // namespace

Uuid make_uuid4()
{
    Uuid u;

    std::generate_n(reinterpret_cast<unsigned*>(&u),
                    sizeof(Uuid) / sizeof(unsigned),
                    [] { return generator(); });

    u.time_hi_and_version &= ~((1 << 15) | (1 << 13) | (1 << 12));
    u.time_hi_and_version |= 1 << 14;

    u.clock_seq_hi_and_reserved &= ~(1 << 6);
    u.clock_seq_hi_and_reserved |= 1 << 7;

    return u;
}

std::ostream& operator<<(std::ostream& out, const Uuid& u)
{
    using fmt::format;

    return out
           << format("{:08x}-{:04x}-{:04x}-{:02x}{:02x}-{:012x}",
                     u.time_low,
                     u.time_mid,
                     u.time_hi_and_version,
                     u.clock_seq_hi_and_reserved,
                     u.clock_seq_low,
                     u.node);
}

} // namespace uuid4
