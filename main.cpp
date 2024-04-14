#include <vector>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include "topk.h"

int main()
{
	const std::vector<int> v{1,2,6,7,8,3,1,3,4,1,12,4,5,15,3,561,6,1,614,34,4,53,1,2};
	// const std::vector<int> v{1,2,6,7,8};
	constexpr auto k = 5;
	std::vector<int> vtop_base = base::topk(begin(v), end(v), k);
	std::vector<int> vtop_opt = opt::topk(begin(v), end(v), k);

	fmt::print("{}\n", v);
	fmt::print("{}\n", vtop_base);
	fmt::print("{}\n", vtop_opt);
	return 0;
}