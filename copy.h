#include <thrust/copy.h>

template <typename Container1,
          typename Container2 = Container1>
struct Copy
{
  Container1 A;
  Container2 B;

  template <typename Range1, typename Range2>
  Copy(const Range1& X, const Range2& Y)
    : A(X.begin(), X.end()), B(Y.begin(), Y.end())
  {}

  void operator()(void)
  {
    thrust::copy(A.begin(), A.end(), B.begin());
  }

  void reset(void)
  {
    // nothing to do
  }
};

template <typename Container1,
          typename Container2 = Container1>
struct CopyN
{
  Container1 A;
  Container2 B;

  template <typename Range1, typename Range2>
  CopyN(const Range1& X, const Range2& Y)
    : A(X.begin(), X.end()), B(Y.begin(), Y.end())
  {}

  void operator()(void)
  {
    thrust::copy_n(A.begin(), A.size(), B.begin());
  }

  void reset(void)
  {
    // nothing to do
  }
};

template <typename Container1,
          typename Container2 = Container1,
          typename Container3 = Container1,
          typename Predicate = thrust::identity<typename Container1::value_type> >
struct CopyIf
{
  Container1 A; // values
  Container2 B; // stencil
  Container3 C; // output
  Predicate pred;

  template <typename Range1, typename Range2, typename Range3>
  CopyIf(const Range1& X, const Range2& Y, const Range3& Z, Predicate pred = Predicate())
    : A(X.begin(), X.end()),
      B(Y.begin(), Y.end()),
      C(Z.begin(), Z.end()),
      pred(pred)
  {}

  void operator()(void)
  {
    thrust::copy_if(A.begin(), A.end(), B.begin(), C.begin(), pred);
  }
  
  void reset(void)
  {
    // nothing to do
  }
};

