#include <benchmark/benchmark.h>
#include <uuid4.h>

namespace uuid4 {
namespace {

void bm_generate(benchmark::State& state)
{
    for(auto _ : state)
        make_uuid4();
}

BENCHMARK(bm_generate);

} // namespace
} // namespace uuid4

BENCHMARK_MAIN();
