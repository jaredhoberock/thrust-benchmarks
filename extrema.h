#include <thrust/extrema.h>

template <typename Container,
          typename BinaryPredicate = thrust::less<typename Container::value_type> >
struct MinElement
{
  Container A;
  BinaryPredicate binary_pred;

  template <typename Range>
  MinElement(const Range& X, BinaryPredicate binary_pred = BinaryPredicate())
    : A(X.begin(), X.end()),
      binary_pred(binary_pred)
  {}

  void operator()(void)
  {
    thrust::min_element(A.begin(), A.end(), binary_pred);
  }
  
  void reset(void)
  {
    // nothing to do
  }
};


template <typename Container,
          typename BinaryPredicate = thrust::less<typename Container::value_type> >
struct MaxElement
{
  Container A;
  BinaryPredicate binary_pred;

  template <typename Range>
  MaxElement(const Range& X, BinaryPredicate binary_pred = BinaryPredicate())
    : A(X.begin(), X.end()),
      binary_pred(binary_pred)
  {}

  void operator()(void)
  {
    thrust::max_element(A.begin(), A.end(), binary_pred);
  }
  
  void reset(void)
  {
    // nothing to do
  }
};


template <typename Container,
          typename BinaryPredicate = thrust::less<typename Container::value_type> >
struct MinMaxElement
{
  Container A;
  BinaryPredicate binary_pred;

  template <typename Range>
  MinMaxElement(const Range& X, BinaryPredicate binary_pred = BinaryPredicate())
    : A(X.begin(), X.end()),
      binary_pred(binary_pred)
  {}

  void operator()(void)
  {
    thrust::minmax_element(A.begin(), A.end(), binary_pred);
  }
  
  void reset(void)
  {
    // nothing to do
  }
};

