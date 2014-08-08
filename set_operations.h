#include <thrust/set_operations.h>

#include <thrust/sort.h>

template <typename Container1,
          typename Container2 = Container1,
          typename Container3 = Container1,
          typename StrictWeakCompare = thrust::less<typename Container1::value_type> >
struct SetDifference
{
  Container1 A;
  Container2 B;
  Container3 C;
  StrictWeakCompare comp;

  template <typename Range1, typename Range2, typename Range3>
  SetDifference(const Range1& X, const Range2& Y, const Range3& Z, StrictWeakCompare comp = StrictWeakCompare())
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
    thrust::set_difference(A.begin(), A.end(), B.begin(), B.end(), C.begin(), comp);
  }
};

template <typename Container1,
          typename Container2 = Container1,
          typename Container3 = Container1,
          typename StrictWeakCompare = thrust::less<typename Container1::value_type> >
struct SetIntersection
{
  Container1 A;
  Container2 B;
  Container3 C;
  StrictWeakCompare comp;

  template <typename Range1, typename Range2, typename Range3>
  SetIntersection(const Range1& X, const Range2& Y, const Range3& Z, StrictWeakCompare comp = StrictWeakCompare())
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
    thrust::set_intersection(A.begin(), A.end(), B.begin(), B.end(), C.begin(), comp);
  }
};

template <typename Container1,
          typename Container2 = Container1,
          typename Container3 = Container1,
          typename StrictWeakCompare = thrust::less<typename Container1::value_type> >
struct SetSymmetricDifference
{
  Container1 A;
  Container2 B;
  Container3 C;
  StrictWeakCompare comp;

  template <typename Range1, typename Range2, typename Range3>
  SetSymmetricDifference(const Range1& X, const Range2& Y, const Range3& Z, StrictWeakCompare comp = StrictWeakCompare())
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
    thrust::set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), C.begin(), comp);
  }
};

template <typename Container1,
          typename Container2 = Container1,
          typename Container3 = Container1,
          typename StrictWeakCompare = thrust::less<typename Container1::value_type> >
struct SetUnion
{
  Container1 A;
  Container2 B;
  Container3 C;
  StrictWeakCompare comp;

  template <typename Range1, typename Range2, typename Range3>
  SetUnion(const Range1& X, const Range2& Y, const Range3& Z, StrictWeakCompare comp = StrictWeakCompare())
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
    thrust::set_union(A.begin(), A.end(), B.begin(), B.end(), C.begin(), comp);
  }
};

