#include <thrust/reduce.h>

template <typename Container,
          typename T = typename Container::value_type,
          typename BinaryFunction = thrust::plus<T> >
struct Reduce
{
  Container A;
  T init;
  BinaryFunction binary_op;

  template <typename Range>
  Reduce(const Range& X, T init = T(0),
         BinaryFunction binary_op = BinaryFunction())
    : A(X.begin(), X.end()),
      init(init),
      binary_op(binary_op)
  {}

  void operator()(void)
  {
    thrust::reduce(A.begin(), A.end(), init, binary_op);
  }
};

template <typename Container1,
          typename Container2 = Container1,
          typename Container3 = Container1,
          typename Container4 = Container2,
          typename BinaryPredicate = thrust::equal_to<typename Container1::value_type>,
          typename BinaryFunction  = thrust::plus<typename Container2::value_type> >
struct ReduceByKey
{
  Container1 A;
  Container2 B;
  Container3 C;
  Container4 D;
  BinaryPredicate binary_pred;
  BinaryFunction binary_op;

  template <typename Range1, typename Range2, typename Range3, typename Range4>
  ReduceByKey(const Range1& X,
              const Range2& Y,
              const Range3& Z,
              const Range4& W,
              BinaryPredicate binary_pred = BinaryPredicate(),
              BinaryFunction binary_op = BinaryFunction())
    : A(X.begin(), X.end()),
      B(Y.begin(), Y.end()),
      C(Z.begin(), Z.end()),
      D(W.begin(), W.end()),
      binary_pred(binary_pred),
      binary_op(binary_op)
  {}

  void operator()(void)
  {
    thrust::reduce_by_key(A.begin(), A.end(), B.begin(), C.begin(), D.begin(), binary_pred, binary_op);
  }
};

