#include <thrust/sort.h>

template <typename Container,
          typename StrictWeakOrdering = thrust::less<typename Container::value_type> >
struct Sort
{
  Container A, A_copy;
  StrictWeakOrdering comp;

  template <typename Range>
  Sort(const Range& X, StrictWeakOrdering comp = StrictWeakOrdering())
    : A(X.begin(), X.end()), A_copy(X.begin(), X.end()),
      comp(comp)
  {}

  void operator()(void)
  {
    thrust::sort(A.begin(), A.end(), comp);
  }

  void reset(void)
  {
    thrust::copy(A_copy.begin(), A_copy.end(), A.begin());
  }
};

template <typename Container,
          typename StrictWeakOrdering = thrust::less<typename Container::value_type> >
struct StableSort
{
  Container A, A_copy;
  StrictWeakOrdering comp;

  template <typename Range>
  StableSort(const Range& X, StrictWeakOrdering comp = StrictWeakOrdering())
    : A(X.begin(), X.end()), A_copy(X.begin(), X.end()),
      comp(comp)
  {}

  void operator()(void)
  {
    thrust::stable_sort(A.begin(), A.end(), comp);
  }

  void reset(void)
  {
    thrust::copy(A_copy.begin(), A_copy.end(), A.begin());
  }
};

template <typename Container1,
          typename Container2 = Container1,
          typename StrictWeakOrdering = thrust::less<typename Container1::value_type> >
struct SortByKey
{
  Container1 A, A_copy; // keys
  Container2 B, B_copy; // values
  StrictWeakOrdering comp;

  template <typename Range1, typename Range2>
  SortByKey(const Range1& X, const Range2& Y, StrictWeakOrdering comp = StrictWeakOrdering())
    : A(X.begin(), X.end()), A_copy(X.begin(), X.end()),
      B(Y.begin(), Y.end()), B_copy(Y.begin(), Y.end()),
      comp(comp)
  {}

  void operator()(void)
  {
    thrust::sort_by_key(A.begin(), A.end(), B.begin(), comp);
  }

  void reset(void)
  {
    thrust::copy(A_copy.begin(), A_copy.end(), A.begin());
    thrust::copy(B_copy.begin(), B_copy.end(), B.begin());
  }
};

template <typename Container1,
          typename Container2 = Container1,
          typename StrictWeakOrdering = thrust::less<typename Container1::value_type> >
struct StableSortByKey
{
  Container1 A, A_copy; // keys
  Container2 B, B_copy; // values
  StrictWeakOrdering comp;

  template <typename Range1, typename Range2>
  StableSortByKey(const Range1& X, const Range2& Y, StrictWeakOrdering comp = StrictWeakOrdering())
    : A(X.begin(), X.end()), A_copy(X.begin(), X.end()),
      B(Y.begin(), Y.end()), B_copy(Y.begin(), Y.end()),
      comp(comp)
  {}

  void operator()(void)
  {
    thrust::stable_sort_by_key(A.begin(), A.end(), B.begin(), comp);
  }

  void reset(void)
  {
    thrust::copy(A_copy.begin(), A_copy.end(), A.begin());
    thrust::copy(B_copy.begin(), B_copy.end(), B.begin());
  }
};


template <typename Container,
          typename StrictWeakOrdering = thrust::less<typename Container::value_type> >
struct IsSorted
{
  Container A;
  StrictWeakOrdering comp;

  template <typename Range>
  IsSorted(const Range& X, StrictWeakOrdering comp = StrictWeakOrdering())
    : A(X.begin(), X.end()),
      comp(comp)
  {}

  void operator()(void)
  {
    thrust::is_sorted(A.begin(), A.end(), comp);
  }

  void reset(void)
  {
    // nothing to do
  }
};

template <typename Container,
          typename StrictWeakOrdering = thrust::less<typename Container::value_type> >
struct IsSortedUntil
{
  Container A;
  StrictWeakOrdering comp;

  template <typename Range>
  IsSortedUntil(const Range& X, StrictWeakOrdering comp = StrictWeakOrdering())
    : A(X.begin(), X.end()),
      comp(comp)
  {}

  void operator()(void)
  {
    thrust::is_sorted_until(A.begin(), A.end(), comp);
  }

  void reset(void)
  {
    // nothing to do
  }
};

