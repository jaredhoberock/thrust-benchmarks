#include <thrust/count.h>

template <typename Container,
          typename EqualityComparable = typename Container::value_type>
struct Count
{
  Container A;
  EqualityComparable value;

  template <typename Range>
  Count(const Range& X, EqualityComparable value = EqualityComparable())
    : A(X.begin(), X.end()),
      value(value)
  {}

  void operator()(void)
  {
    thrust::count(A.begin(), A.end(), value);
  }
  
  void reset(void)
  {
    // nothing to do
  }
};

template <typename Container,
          typename Predicate = thrust::identity<typename Container::value_type> >
struct CountIf
{
  Container A;
  Predicate pred;

  template <typename Range>
  CountIf(const Range& X, Predicate pred = Predicate())
    : A(X.begin(), X.end()),
      pred(pred)
  {}

  void operator()(void)
  {
    thrust::count_if(A.begin(), A.end(), pred);
  }
  
  void reset(void)
  {
    // nothing to do
  }
};

