#include <thrust/transform.h>

template <typename Container1,
          typename Container2 = Container1,
          typename UnaryFunction = thrust::negate<typename Container1::value_type> >
struct UnaryTransform
{
  Container1 A;
  Container2 B;
  UnaryFunction unary_op;

  template <typename Range1, typename Range2>
  UnaryTransform(const Range1& X, const Range2& Y,
                 UnaryFunction unary_op = UnaryFunction())
    : A(X.begin(), X.end()),
      B(Y.begin(), Y.end()),
      unary_op(unary_op)
  {}

  void operator()(void)
  {
    thrust::transform(A.begin(), A.end(), B.begin(), unary_op);
  }
};

template <typename Container1,
          typename Container2 = Container1,
          typename Container3 = Container1,
          typename Predicate = thrust::identity<typename Container2::value_type>,
          typename UnaryFunction = thrust::negate<typename Container1::value_type> >
struct UnaryTransformIf
{
  Container1 A; // input
  Container2 B; // stencil
  Container3 C; // output
  Predicate pred;
  UnaryFunction unary_op;

  template <typename Range1, typename Range2, typename Range3>
  UnaryTransformIf(const Range1& X, const Range2& Y, const Range3& Z,
                   Predicate pred = Predicate(),
                   UnaryFunction unary_op = UnaryFunction())
    : A(X.begin(), X.end()),
      B(Y.begin(), Y.end()),
      C(Z.begin(), Z.end()),
      pred(pred),
      unary_op(unary_op)
  {}

  void operator()(void)
  {
    thrust::transform_if(A.begin(), A.end(), B.begin(), C.begin(), unary_op, pred);
  }
};


template <typename Container1,
          typename Container2 = Container1,
          typename Container3 = Container1,
          typename BinaryFunction = thrust::plus<typename Container1::value_type> >
struct BinaryTransform
{
  Container1 A;
  Container2 B;
  Container3 C;
  BinaryFunction binary_op;

  template <typename Range1, typename Range2, typename Range3>
  BinaryTransform(const Range1& X, const Range2& Y, const Range3& Z,
                  BinaryFunction binary_op = BinaryFunction())
    : A(X.begin(), X.end()),
      B(Y.begin(), Y.end()),
      C(Z.begin(), Z.end()),
      binary_op(binary_op)
  {}

  void operator()(void)
  {
    thrust::transform(A.begin(), A.end(), B.begin(), C.begin(), binary_op);
  }
};


template <typename Container1,
          typename Container2 = Container1,
          typename Container3 = Container1,
          typename Container4 = Container1,
          typename Predicate = thrust::identity<typename Container2::value_type>,
          typename BinaryFunction = thrust::plus<typename Container1::value_type> >
struct BinaryTransformIf
{
  Container1 A; // input
  Container2 B; // input
  Container3 C; // stencil
  Container4 D; // output
  Predicate pred;
  BinaryFunction binary_op;

  template <typename Range1, typename Range2, typename Range3, typename Range4>
  BinaryTransformIf(const Range1& X, const Range2& Y, const Range3& Z, const Range4& W,
                    Predicate pred = Predicate(),
                    BinaryFunction binary_op = BinaryFunction())
    : A(X.begin(), X.end()),
      B(Y.begin(), Y.end()),
      C(Z.begin(), Z.end()),
      D(W.begin(), W.end()),
      pred(pred),
      binary_op(binary_op)
  {}

  void operator()(void)
  {
    thrust::transform_if(A.begin(), A.end(), B.begin(), C.begin(), D.begin(), binary_op, pred);
  }
};


