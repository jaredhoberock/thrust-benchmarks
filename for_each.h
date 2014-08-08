#include <thrust/for_each.h>

struct default_for_each_function
{
  template <typename T>
  __host__ __device__
  void operator()(T& x)
  {
    x = T();
  }
};

template <typename Container,
          typename UnaryFunction = default_for_each_function>
struct ForEach
{
  Container A;
  UnaryFunction unary_op;

  template <typename Range>
  ForEach(const Range& X, UnaryFunction unary_op = UnaryFunction())
    : A(X.begin(), X.end()),
      unary_op(unary_op)
  {}

  void operator()(void)
  {
    thrust::for_each(A.begin(), A.end(), unary_op);
  }
};

