#include <thrust/equal.h>

template <typename Container1,
          typename Container2 = Container1,
          typename BinaryPredicate = thrust::equal_to<typename Container1::value_type> >
struct Equal
{
  Container1 A;
  Container2 B;
  BinaryPredicate binary_pred;

  template <typename Range1, typename Range2>
  Equal(const Range1& X, const Range2& Y,
        BinaryPredicate binary_pred = BinaryPredicate())
    : A(X.begin(), X.end()),
      B(Y.begin(), Y.end()),
      binary_pred(binary_pred)
  {}

  void operator()(void)
  {
    thrust::equal(A.begin(), A.end(), B.begin(), binary_pred);
  }
  
  void reset(void)
  {
    // nothing to do
  }
};

