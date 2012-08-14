#include <thrust/merge.h>

#include <thrust/sort.h>

template <typename Container1,
          typename Container2 = Container1,
          typename Container3 = Container1,
          typename StrictWeakCompare = thrust::less<typename Container1::value_type> >
struct Merge
{
  Container1 A;
  Container2 B;
  Container3 C;
  StrictWeakCompare comp;

  template <typename Range1, typename Range2, typename Range3>
  Merge(const Range1& X, const Range2& Y, const Range3& Z, StrictWeakCompare comp = StrictWeakCompare())
    : A(X.begin(), X.end()),
      B(Y.begin(), Y.end()),
      C(Z.begin(), Z.end()),
      comp(comp)
  {
    thrust::stable_sort(A.begin(), A.end(), comp);
    thrust::stable_sort(B.begin(), B.end(), comp);
  }

  void operator()(void)
  {
    thrust::merge(A.begin(), A.end(), B.begin(), B.end(), C.begin(), comp);
  }
  
  void reset(void)
  {
    // nothing to do
  }
};

