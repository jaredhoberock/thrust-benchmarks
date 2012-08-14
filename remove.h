#include <thrust/remove.h>

template <typename Container,
          typename T = typename Container::value_type>
struct Remove
{
  Container A;
  Container B; // copy of initial data
  T value;

  template <typename Range>
  Remove(const Range& X, T value)
    : A(X.begin(), X.end()),
      B(X.begin(), X.end()),
      value(value)
  {}

  void operator()(void)
  {
    thrust::remove(A.begin(), A.end(), value);
  }
  
  void reset(void)
  {
    // restore initial data
    thrust::copy(B.begin(), B.end(), A.begin());
  }
};

template <typename Container1,
          typename Container2 = Container1,
          typename T = typename Container1::value_type>
struct RemoveCopy
{
  Container1 A;
  Container2 B;
  T value;

  template <typename Range1, typename Range2>
  RemoveCopy(const Range1& X, const Range2& Y, T value)
    : A(X.begin(), X.end()),
      B(Y.begin(), Y.end()),
      value(value)
  {}

  void operator()(void)
  {
    thrust::remove_copy(A.begin(), A.end(), B.begin(), value);
  }
  
  void reset(void)
  {
    // restore initial data
    thrust::copy(B.begin(), B.end(), A.begin());
  }
};

template <typename Container1,
          typename Container2 = Container1,
          typename Predicate = thrust::identity<typename Container2::value_type> >
struct RemoveIf
{
  Container1 A, A_copy;
  Container2 B;
  Predicate pred;

  template <typename Range1, typename Range2>
  RemoveIf(const Range1& X, const Range2& Y, Predicate pred = Predicate())
    : A(X.begin(), X.end()), A_copy(X.begin(), X.end()),
      B(Y.begin(), Y.end()),
      pred(pred)
  {}

  void operator()(void)
  {
    thrust::remove_if(A.begin(), A.end(), B.begin(), pred);
  }
  
  void reset(void)
  {
    // restore initial data
    thrust::copy(A_copy.begin(), A_copy.end(), A.begin());
  }
};


template <typename Container1,
          typename Container2 = Container1,
          typename Container3 = Container1,
          typename Predicate = thrust::identity<typename Container2::value_type> >
struct RemoveCopyIf
{
  Container1 A, A_copy;
  Container2 B;
  Container3 C;
  Predicate pred;

  template <typename Range1, typename Range2, typename Range3>
  RemoveCopyIf(const Range1& X, const Range2& Y, const Range3& Z, Predicate pred = Predicate())
    : A(X.begin(), X.end()), A_copy(X.begin(), X.end()),
      B(Y.begin(), Y.end()),
      C(Z.begin(), Z.end()),
      pred(pred)
  {}

  void operator()(void)
  {
    thrust::remove_copy_if(A.begin(), A.end(), B.begin(), C.begin(), pred);
  }
  
  void reset(void)
  {
    // restore initial data
    thrust::copy(A_copy.begin(), A_copy.end(), A.begin());
  }
};

