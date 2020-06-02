#include <gtest/gtest.h>
#include <regex>
#include <set>
#include <sstream>
#include <tuple>
#include <uuid4.h>

namespace uuid4 {
namespace {

struct UuidCompare
{
  bool operator()(const Uuid a, const Uuid b) const
  {
    return std::tie(a.time_low, a.time_mid, a.time_hi_and_version, a.clock_seq_hi_and_reserved, a.clock_seq_low, a.node1) <
           std::tie(b.time_low, b.time_mid, b.time_hi_and_version, b.clock_seq_hi_and_reserved, b.clock_seq_low, b.node1);
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
  auto n = 100;

  std::set<Uuid, UuidCompare> seen;

  for(auto i = 0; i < n; ++i)
  {
    auto u = make_uuid4();
    ASSERT_EQ(seen.end(), seen.find(u));
    seen.insert(u);
  }
}

TEST(MakeUuid4, Print)
{
  Uuid u{
      1,
      2,
      3,
      4,
      5,
      6,
      7};

  std::ostringstream s;
  s << u;

  EXPECT_EQ("00000001-0002-0003-0405-000000060007", s.str());
}

TEST(MakeUuid4, PrintMatchesPatter)
{
  auto             n = 100;
  const std::regex re("^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$");

  for(auto i = 0; i < n; ++i)
  {
    auto u = make_uuid4();

    std::ostringstream s;
    s << u;

    EXPECT_TRUE(std::regex_match(s.str(), re));
  }
}

} // namespace
} // namespace uuid4
