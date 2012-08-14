#include <thrust/generate.h>

template <typename T>
struct default_generate_function
{
  __host__ __device__
  T operator()(void)
  {
    return T();
  }
};

template <typename Container,
          typename UnaryFunction = default_generate_function<typename Container::value_type> >
struct Generate
{
  Container A;
  UnaryFunction unary_op;

  template <typename Range>
  Generate(const Range& X, UnaryFunction unary_op = UnaryFunction())
    : A(X.begin(), X.end()),
      unary_op(unary_op)
  {}

  void operator()(void)
  {
    thrust::generate(A.begin(), A.end(), unary_op);
  }
  
  void reset(void)
  {
    // nothing to do
  }
};

template <typename Container,
          typename UnaryFunction = default_generate_function<typename Container::value_type> >
struct GenerateN
{
  Container A;
  UnaryFunction unary_op;

  template <typename Range>
  GenerateN(const Range& X, UnaryFunction unary_op = UnaryFunction())
    : A(X.begin(), X.end()),
      unary_op(unary_op)
  {}

  void operator()(void)
  {
    thrust::generate_n(A.begin(), A.size(), unary_op);
  }
  
  void reset(void)
  {
    // nothing to do
  }
};

