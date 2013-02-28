#include <thrust/tabulate.h>
#include <thrust/functional.h>

template <typename Container,
          typename UnaryFunction = thrust::negate<typename Container::value_type> >
struct Tabulate
{
  Container A;
  UnaryFunction unary_op;

  template <typename Range>
  Tabulate(const Range& X,
           UnaryFunction unary_op = UnaryFunction())
    : A(X.begin(), X.end()),
      unary_op(unary_op)
  {}

  void operator()(void)
  {
    thrust::tabulate(A.begin(), A.end(), unary_op);
  }
  
  void reset(void)
  {
    // nothing to do
  }
};


