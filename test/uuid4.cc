#include <gtest/gtest.h>
#include <set>
#include <tuple>
#include <uuid4.h>

namespace uuid4 {
namespace {

struct UuidCompare
{
  bool operator()(const Uuid a, const Uuid b) const
  {
    return std::tie(a.time_low, a.time_mid, a.time_hi_and_version, a.clock_seq_hi_and_reserved, a.clock_seq_low, a.node) <
           std::tie(b.time_low, b.time_mid, b.time_hi_and_version, b.clock_seq_hi_and_reserved, b.clock_seq_low, b.node);
  }
};


TEST(MakeUuid4, SetsUuid4Bits)
{
  auto u = make_uuid4();

  // Per https://tools.ietf.org/html/rfc4122.html:
  //
  // * Set the two most significant bits (bits 6 and 7) of the
  //   clock_seq_hi_and_reserved to zero and one, respectively.
  // * Set the four most significant bits (bits 12 through 15) of the
  //   time_hi_and_version field to the 4-bit version number from
  //   Section 4.1.3. (

  EXPECT_EQ(2, u.clock_seq_hi_and_reserved >> 6);
  EXPECT_EQ(4, u.time_hi_and_version >> 12);
}

TEST(MakeUuid4, ResultsAreRandom)
{
  auto n = 1000;

  std::set<Uuid, UuidCompare> seen;

  for(auto i = 0; i < n; ++i)
  {
    auto u = make_uuid4();
    ASSERT_EQ(seen.end(), seen.find(u));
    seen.insert(u);
  }
}

} // namespace
} // namespace uuid4
