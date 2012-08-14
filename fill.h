#include <thrust/fill.h>

template <typename Container,
          typename T = typename Container::value_type>
struct Fill
{
  Container A;
  T value;

  template <typename Range>
  Fill(const Range& X, T value = T())
    : A(X.begin(), X.end()),
      value(value)
  {}

  void operator()(void)
  {
    thrust::fill(A.begin(), A.end(), value);
  }
  
  void reset(void)
  {
    // nothing to do
  }
};

template <typename Container,
          typename T = typename Container::value_type>
struct FillN
{
  Container A;
  T value;

  template <typename Range>
  FillN(const Range& X, T value = T())
    : A(X.begin(), X.end()),
      value(value)
  {}

  void operator()(void)
  {
    thrust::fill_n(A.begin(), A.size(), value);
  }
  
  void reset(void)
  {
    // nothing to do
  }
};

