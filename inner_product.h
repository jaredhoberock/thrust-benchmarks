#include <thrust/inner_product.h>

template <typename Container1,
          typename Container2 = Container1,
          typename T = typename Container1::value_type,
          typename BinaryFunction1 = thrust::plus<T>,
          typename BinaryFunction2 = thrust::multiplies<T> >
struct InnerProduct
{
  Container1 A;
  Container2 B;
  T value;
  BinaryFunction1 binary_op1;
  BinaryFunction2 binary_op2;

  template <typename Range1, typename Range2>
  InnerProduct(const Range1& X, const Range2& Y, T value = T(0), BinaryFunction1 binary_op1 = BinaryFunction1(), BinaryFunction2 binary_op2 = BinaryFunction2())
    : A(X.begin(), X.end()),
      B(Y.begin(), Y.end()),
      value(value),
      binary_op1(binary_op1),
      binary_op2(binary_op2)
  {}

  void operator()(void)
  {
    thrust::inner_product(A.begin(), A.end(), B.begin(), value, binary_op1, binary_op2);
  }
  
  void reset(void)
  {
    // nothing to do
  }
};

