#include <thrust/reverse.h>

template <typename Container,
          typename T = typename Container::value_type>
struct Reverse
{
  Container A, A_copy;

  template <typename Range>
  Reverse(const Range& X)
    : A(X.begin(), X.end()), A_copy(X.begin(), X.end())
  {}

  void operator()(void)
  {
    thrust::reverse(A.begin(), A.end());
  }
  
  void reset(void)
  {
    // restore initial data
    thrust::copy(A_copy.begin(), A_copy.end(), A.begin());
  }
};

template <typename Container1,
          typename Container2 = Container1>
struct ReverseCopy
{
  Container1 A;
  Container2 B;

  template <typename Range1, typename Range2>
  ReverseCopy(const Range1& X, const Range2& Y)
    : A(X.begin(), X.end()),
      B(Y.begin(), Y.end())
  {}

  void operator()(void)
  {
    thrust::reverse_copy(A.begin(), A.end(), B.begin());
  }
};

