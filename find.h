#include <thrust/count.h>

template <typename Container,
          typename EqualityComparable = typename Container::value_type>
struct Find
{
  Container A;
  EqualityComparable value;

  template <typename Range>
  Find(const Range& X, EqualityComparable value)
    : A(X.begin(), X.end()),
      value(value)
  {}

  void operator()(void)
  {
    thrust::find(A.begin(), A.end(), value);
  }
};

template <typename Container,
          typename Predicate = thrust::identity<typename Container::value_type> >
struct FindIf
{
  Container A;
  Predicate pred;

  template <typename Range>
  FindIf(const Range& X, Predicate pred = Predicate())
    : A(X.begin(), X.end()),
      pred(pred)
  {}

  void operator()(void)
  {
    thrust::find_if(A.begin(), A.end(), pred);
  }
};

template <typename Container,
          typename Predicate = thrust::identity<typename Container::value_type> >
struct FindIfNot
{
  Container A;
  Predicate pred;

  template <typename Range>
  FindIfNot(const Range& X, Predicate pred = Predicate())
    : A(X.begin(), X.end()),
      pred(pred)
  {}

  void operator()(void)
  {
    thrust::find_if_not(A.begin(), A.end(), pred);
  }
};

