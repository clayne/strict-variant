#include "bench_api.hpp"
#include "bench_framework.hpp"
#include <experimental/variant.hpp>

static constexpr uint32_t num_variants{NUM_VARIANTS};
static constexpr uint32_t seq_length{SEQ_LENGTH};
static constexpr uint32_t repeat_num{REPEAT_NUM};
static constexpr uint32_t rng_seed{RNG_SEED};

struct visitor_applier {
  template <typename T>
  uint32_t operator()(T && t) const {
    return std::experimental::visit(benchmark::visitor{}, std::forward<T>(t));
  }
};

int
main() {
  benchmark::run_benchmark<std::experimental::variant, num_variants, seq_length, repeat_num,
                           visitor_applier>("std::experimental::variant", rng_seed);
}
