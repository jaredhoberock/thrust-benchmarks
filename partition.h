#include <thrust/partition.h>

template <typename Container,
          typename Predicate = thrust::identity<typename Container::value_type> >
struct Partition
{
  Container A;
  Container B; // copy of initial data
  Predicate pred;

  template <typename Range>
  Partition(const Range& X, Predicate pred = Predicate())
    : A(X.begin(), X.end()),
      B(X.begin(), X.end()),
      pred(pred)
  {}

  void operator()(void)
  {
    thrust::partition(A.begin(), A.end(), pred);
  }
  
  void reset(void)
  {
    // restore initial data
    thrust::copy(B.begin(), B.end(), A.begin());
  }
};


template <typename Container1,
          typename Container2 = Container1,
          typename Container3 = Container1,
          typename Predicate = thrust::identity<typename Container1::value_type> >
struct PartitionCopy
{
  Container1 A;
  Container2 B;
  Container3 C;
  Predicate pred;

  template <typename Range1, typename Range2, typename Range3>
  PartitionCopy(const Range1& X, const Range2& Y, const Range3& Z, Predicate pred = Predicate())
    : A(X.begin(), X.end()),
      B(Y.begin(), Y.end()),
      C(Z.begin(), Z.end()),
      pred(pred)
  {}

  void operator()(void)
  {
    thrust::partition_copy(A.begin(), A.end(), B.begin(), C.begin(), pred);
  }
  
  void reset(void)
  {
    // nothing to do
  }
};


template <typename Container,
          typename Predicate = thrust::identity<typename Container::value_type> >
struct StablePartition
{
  Container A;
  Container B; // copy of initial data
  Predicate pred;

  template <typename Range>
  StablePartition(const Range& X, Predicate pred = Predicate())
    : A(X.begin(), X.end()),
      B(X.begin(), X.end()),
      pred(pred)
  {}

  void operator()(void)
  {
    thrust::stable_partition(A.begin(), A.end(), pred);
  }
  
  void reset(void)
  {
    // restore initial data
    thrust::copy(B.begin(), B.end(), A.begin());
  }
};


template <typename Container1,
          typename Container2 = Container1,
          typename Container3 = Container1,
          typename Predicate = thrust::identity<typename Container1::value_type> >
struct StablePartitionCopy
{
  Container1 A;
  Container2 B;
  Container3 C;
  Predicate pred;

  template <typename Range1, typename Range2, typename Range3>
  StablePartitionCopy(const Range1& X, const Range2& Y, const Range3& Z, Predicate pred = Predicate())
    : A(X.begin(), X.end()),
      B(Y.begin(), Y.end()),
      C(Z.begin(), Z.end()),
      pred(pred)
  {}

  void operator()(void)
  {
    thrust::stable_partition_copy(A.begin(), A.end(), B.begin(), C.begin(), pred);
  }
  
  void reset(void)
  {
    // nothing to do
  }
};


template <typename Container,
          typename Predicate = thrust::identity<typename Container::value_type> >
struct IsPartitioned
{
  Container A;
  Predicate pred;

  template <typename Range>
  IsPartitioned(const Range& X, Predicate pred = Predicate())
    : A(X.begin(), X.end()),
      pred(pred)
  {}

  void operator()(void)
  {
    thrust::is_partitioned(A.begin(), A.end(), pred);
  }
  
  void reset(void)
  {
    // nothing to do
  }
};


template <typename Container,
          typename Predicate = thrust::identity<typename Container::value_type> >
struct PartitionPoint
{
  Container A;
  Predicate pred;

  template <typename Range>
  PartitionPoint(const Range& X, Predicate pred = Predicate())
    : A(X.begin(), X.end()),
      pred(pred)
  {}

  void operator()(void)
  {
    thrust::partition_point(A.begin(), A.end(), pred);
  }
  
  void reset(void)
  {
    // nothing to do
  }
};


// is_partitioned / partition / stable_partition / partition_copy / stable_partition_copy
//template<typename InputIterator , typename OutputIterator1 , typename OutputIterator2 , typename Predicate >
//thrust::pair< OutputIterator1, 
//OutputIterator2 > 	thrust::partition_copy (InputIterator first, InputIterator last, OutputIterator1 out_true, OutputIterator2 out_false, Predicate pred)
//template<typename ForwardIterator , typename Predicate >
//ForwardIterator 	thrust::stable_partition (ForwardIterator first, ForwardIterator last, Predicate pred)
//template<typename InputIterator , typename OutputIterator1 , typename OutputIterator2 , typename Predicate >
//thrust::pair< OutputIterator1, 
//OutputIterator2 > 	thrust::stable_partition_copy (InputIterator first, InputIterator last, OutputIterator1 out_true, OutputIterator2 out_false, Predicate pred)
//template<typename ForwardIterator , typename Predicate >
//ForwardIterator 	thrust::partition_point (ForwardIterator first, ForwardIterator last, Predicate pred)
//template<typename InputIterator , typename Predicate >
//bool 	thrust::is_partitioned (InputIterator first, InputIterator last, Predicate pred)
