#include <thrust/gather.h>

template <typename Container1,
          typename Container2 = Container1,
          typename Container3 = Container2>
struct Gather
{
  Container1 A; // map
  Container2 B; // source
  Container3 C; // output

  template <typename Range1, typename Range2, typename Range3>
  Gather(const Range1& X, const Range2& Y, const Range3& Z)
    : A(X.begin(), X.end()),
      B(Y.begin(), Y.end()),
      C(Z.begin(), Z.end())
  {}

  void operator()(void)
  {
    thrust::gather(A.begin(), A.end(), B.begin(), C.begin());
  }
  
  void reset(void)
  {
    // nothing to do
  }
};

template <typename Container1,
          typename Container2 = Container1,
          typename Container3 = Container1,
          typename Container4 = Container2,
          typename Predicate = thrust::identity<typename Container2::value_type> >
struct GatherIf
{
  Container1 A; // map
  Container2 B; // stencil
  Container3 C; // source
  Container4 D; // output
  Predicate pred;

  template <typename Range1, typename Range2, typename Range3, typename Range4>
  GatherIf(const Range1& X, const Range2& Y, const Range3& Z, const Range4& W, Predicate pred = Predicate())
    : A(X.begin(), X.end()),
      B(Y.begin(), Y.end()),
      C(Z.begin(), Z.end()),
      D(W.begin(), W.end()),
      pred(pred)
  {}

  void operator()(void)
  {
    thrust::gather_if(A.begin(), A.end(), B.begin(), C.begin(), D.begin(), pred);
  }
  
  void reset(void)
  {
    // nothing to do
  }
};

