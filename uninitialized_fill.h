#include <thrust/uninitialized_fill.h>

template <typename Container,
          typename T = typename Container::value_type>
struct UninitializedFill
{
  Container A;
  T value;

  template <typename Range>
  UninitializedFill(const Range& X, T value = T())
    : A(X.begin(), X.end()),
      value(value)
  {}

  void operator()(void)
  {
    thrust::uninitialized_fill(A.begin(), A.end(), value);
  }
  
  void reset(void)
  {
    // nothing to do
  }
};

template <typename Container,
          typename T = typename Container::value_type>
struct UninitializedFillN
{
  Container A;
  T value;

  template <typename Range>
  UninitializedFillN(const Range& X, T value = T())
    : A(X.begin(), X.end()),
      value(value)
  {}

  void operator()(void)
  {
    thrust::uninitialized_fill_n(A.begin(), A.size(), value);
  }
  
  void reset(void)
  {
    // nothing to do
  }
};

