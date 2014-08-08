#include <thrust/logical.h>

template <typename Container,
          typename Predicate = thrust::identity<typename Container::value_type> >
struct AllOf
{
  Container A;
  Predicate pred;

  template <typename Range>
  AllOf(const Range& X, Predicate pred = Predicate())
    : A(X.begin(), X.end()),
      pred(pred)
  {}

  void operator()(void)
  {
    thrust::all_of(A.begin(), A.end(), pred);
  }
};

template <typename Container,
          typename Predicate = thrust::identity<typename Container::value_type> >
struct AnyOf
{
  Container A;
  Predicate pred;

  template <typename Range>
  AnyOf(const Range& X, Predicate pred = Predicate())
    : A(X.begin(), X.end()),
      pred(pred)
  {}

  void operator()(void)
  {
    thrust::any_of(A.begin(), A.end(), pred);
  }
};

template <typename Container,
          typename Predicate = thrust::identity<typename Container::value_type> >
struct NoneOf
{
  Container A;
  Predicate pred;

  template <typename Range>
  NoneOf(const Range& X, Predicate pred = Predicate())
    : A(X.begin(), X.end()),
      pred(pred)
  {}

  void operator()(void)
  {
    thrust::none_of(A.begin(), A.end(), pred);
  }
};


