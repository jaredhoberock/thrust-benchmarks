#include <thrust/transform_reduce.h>

template <typename Container,
          typename UnaryFunction = thrust::negate<typename Container::value_type>,
          typename T = typename Container::value_type,
          typename BinaryFunction = thrust::plus<T> >
struct TransformReduce
{
  Container A;
  UnaryFunction unary_op;
  T init;
  BinaryFunction binary_op;

  template <typename Range>
  TransformReduce(const Range& X, UnaryFunction unary_op = UnaryFunction(), T init = T(0), BinaryFunction binary_op = BinaryFunction())
    : A(X.begin(), X.end()),
      unary_op(unary_op),
      init(init),
      binary_op(binary_op)
  {}

  void operator()(void)
  {
    thrust::transform_reduce(A.begin(), A.end(), unary_op, init, binary_op);
  }
};


