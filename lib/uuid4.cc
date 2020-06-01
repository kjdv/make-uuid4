#include <uuid4.h>
#include <random>

namespace uuid4 {
namespace {

std::random_device device;
std::mt19937 generator(device());

std::uniform_int_distribution<uint8_t> distribute8;
std::uniform_int_distribution<uint16_t> distribute16;
std::uniform_int_distribution<uint32_t> distribute32;
std::uniform_int_distribution<uint64_t> distribute64;


}

Uuid make_uuid4()
{
    return Uuid{
        distribute32(generator),
        distribute16(generator),
        static_cast<uint16_t>((4 << 12) | (distribute16(generator) >> 4)),
        static_cast<uint8_t>((2 << 6) | (distribute8(generator) >> 2)),
        distribute8(generator),
        distribute64(generator),
    };
}

}
