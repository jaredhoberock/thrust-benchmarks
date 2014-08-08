#include <thrust/binary_search.h>
#include <thrust/sort.h>

template <typename Container1,
          typename Container2 = Container1,
          typename Container3 = Container1,
          typename StrictWeakOrdering = thrust::less<typename Container1::value_type> >
struct LowerBound
{
  Container1 A; // haystack
  Container2 B; // needles
  Container3 C; // positions
  StrictWeakOrdering comp;

  template <typename Range1, typename Range2, typename Range3>
  LowerBound(const Range1& X, const Range2& Y, const Range3& Z,
             StrictWeakOrdering comp = StrictWeakOrdering())
    : A(X.begin(), X.end()),
      B(Y.begin(), Y.end()),
      C(Z.begin(), Z.end()),
      comp(comp)
  {
    thrust::stable_sort(A.begin(), A.end(), comp);  
  }

  void operator()(void)
  {
    thrust::lower_bound(A.begin(), A.end(), B.begin(), B.end(), C.begin(), comp);
  }
};

template <typename Container1,
          typename Container2 = Container1,
          typename Container3 = Container1,
          typename StrictWeakOrdering = thrust::less<typename Container1::value_type> >
struct UpperBound
{
  Container1 A; // haystack
  Container2 B; // needles
  Container3 C; // positions
  StrictWeakOrdering comp;

  template <typename Range1, typename Range2, typename Range3>
  UpperBound(const Range1& X, const Range2& Y, const Range3& Z,
             StrictWeakOrdering comp = StrictWeakOrdering())
    : A(X.begin(), X.end()),
      B(Y.begin(), Y.end()),
      C(Z.begin(), Z.end()),
      comp(comp)
  {
    thrust::stable_sort(A.begin(), A.end(), comp);  
  }

  void operator()(void)
  {
    thrust::upper_bound(A.begin(), A.end(), B.begin(), B.end(), C.begin(), comp);
  }
};

template <typename Container1,
          typename Container2 = Container1,
          typename Container3 = Container1,
          typename StrictWeakOrdering = thrust::less<typename Container1::value_type> >
struct BinarySearch
{
  Container1 A; // haystack
  Container2 B; // needles
  Container3 C; // booleans
  StrictWeakOrdering comp;

  template <typename Range1, typename Range2, typename Range3>
  BinarySearch(const Range1& X, const Range2& Y, const Range3& Z,
               StrictWeakOrdering comp = StrictWeakOrdering())
    : A(X.begin(), X.end()),
      B(Y.begin(), Y.end()),
      C(Z.begin(), Z.end()),
      comp(comp)
  {
    thrust::stable_sort(A.begin(), A.end(), comp);  
  }

  void operator()(void)
  {
    thrust::binary_search(A.begin(), A.end(), B.begin(), B.end(), C.begin(), comp);
  }
};


