#include <thrust/swap.h>

template <typename Container1,
          typename Container2 = Container1>
struct SwapRanges
{
  Container1 A;
  Container2 B;

  template <typename Range1, typename Range2>
  SwapRanges(const Range1& X, const Range2& Y)
    : A(X.begin(), X.end()),
      B(Y.begin(), Y.end())
  {}

  void operator()(void)
  {
    thrust::swap_ranges(A.begin(), A.end(), B.begin());
  }
};

