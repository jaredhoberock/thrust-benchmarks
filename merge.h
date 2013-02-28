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

template <typename Container1,
          typename Container2 = Container1,
          typename Container3 = Container1,
          typename Container4 = Container1,
          typename Container5 = Container1,
          typename Container6 = Container1,
          typename StrictWeakCompare = thrust::less<typename Container1::value_type> >
struct MergeByKey
{
  Container1 keys1;
  Container2 keys2;
  Container3 values1;
  Container4 values2;
  Container5 out_keys;
  Container6 out_values;
  StrictWeakCompare comp;

  template <typename Range1, typename Range2, typename Range3, typename Range4, typename Range5, typename Range6>
  MergeByKey(const Range1& keys1_, const Range2& keys2_,
             const Range3& values1_, const Range4& values2_,
             Range5 &out_keys_, Range6 &out_values_,
             StrictWeakCompare comp_ = StrictWeakCompare())
    : keys1(keys1_.begin(), keys1_.end()),
      keys2(keys2_.begin(), keys2_.end()),
      values1(values1_.begin(), values1_.end()),
      values2(values2_.begin(), values2_.end()),
      out_keys(out_keys_.begin(), out_keys_.end()),
      out_values(out_values_.begin(), out_values_.end()),
      comp(comp_)
  {
    thrust::stable_sort(keys1.begin(), keys1.end(), comp);
    thrust::stable_sort(keys2.begin(), keys2.end(), comp);
  }

  void operator()(void)
  {
    thrust::merge_by_key(keys1.begin(), keys1.end(),
                         keys2.begin(), keys2.end(),
                         values1.begin(), values2.begin(),
                         out_keys.begin(),
                         out_values.begin(),
                         comp);
  }
  
  void reset(void)
  {
    // nothing to do
  }
};

