#include <thrust/sequence.h>

template <typename Container>
struct Sequence
{
  Container A;

  template <typename Range>
  Sequence(const Range& X)
    : A(X.begin(), X.end())
  {}

  void operator()(void)
  {
    thrust::sequence(A.begin(), A.end());
  }
  
  void reset(void)
  {
    // nothing to do
  }
};

