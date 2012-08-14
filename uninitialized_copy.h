#include <thrust/uninitialized_copy.h>

template <typename Container1,
          typename Container2 = Container1>
struct UninitializedCopy
{
  Container1 A;
  Container2 B;

  template <typename Range1, typename Range2>
  UninitializedCopy(const Range1& X, const Range2& Y)
    : A(X.begin(), X.end()), B(Y.begin(), Y.end())
  {}

  void operator()(void)
  {
    thrust::uninitialized_copy(A.begin(), A.end(), B.begin());
  }

  void reset(void)
  {
    // nothing to do
  }
};

