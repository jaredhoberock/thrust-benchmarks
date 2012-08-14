#include <thrust/host_vector.h>
#include <thrust/device_vector.h>

#include <string>
#include <iostream>
#include <cassert>

#include "cuda_timer.h"
#include "random.h"
#include <unittest/unittest.h>

// Algos
#include "adjacent_difference.h"
#include "binary_search.h"
#include "copy.h"
#include "count.h"
#include "equal.h"
#include "extrema.h"
#include "fill.h"
#include "find.h"
#include "for_each.h"
#include "gather.h"
#include "generate.h"
#include "inner_product.h"
#include "logical.h"
#include "merge.h"
#include "mismatch.h"
#include "partition.h"
#include "reduce.h"
#include "remove.h"
#include "replace.h"
#include "reverse.h"
#include "scan.h"
#include "scatter.h"
#include "sequence.h"
#include "set_operations.h"
#include "sort.h"
#include "swap.h"
#include "transform.h"
#include "transform_reduce.h"
#include "transform_scan.h"
#include "uninitialized_copy.h"
#include "uninitialized_fill.h"
#include "unique.h"

template <typename Vector>
void filter(Vector& times)
{
  // XXX the filter could drop outliers, select the median, etc.

  typedef typename Vector::value_type T;

  T average_time = thrust::reduce(times.begin(), times.end()) / (T) times.size();
  times.resize(1);
  times[0] = average_time;
}

template <typename Test, typename Vector>
void report(Test& test, Vector& times)
{
  std::string test_name = unittest::type_name<Test>();

  if (test_name.find("<") != std::string::npos)
  {
    test_name.resize(test_name.find("<"));
  }

  std::cout << test_name << ", ";
  for (size_t i = 0; i < times.size(); i++)
    std::cout << times[i] << ", ";
  std::cout << "\n";
}


template <typename Test>
void benchmark(Test& test, size_t iterations = 20)
{
  // run one iteration (warm up)
  test();

  test.reset();
  
  thrust::host_vector<double> times(iterations);

  for (size_t i = 0; i < iterations; i++)
  {
    cuda_timer timer;

    test();
    
    times[i] = timer.elapsed();

    test.reset();
  }

  filter(times);

  report(test, times);
};


int main(void)
{
  size_t N = 16 << 20;

  typedef thrust::device_vector<int>     Vector;
  typedef testing::random_integers<int>  RandomIntegers;
  typedef testing::random_integers<bool> RandomBooleans;
  
  RandomIntegers A(N, 123);
  RandomIntegers B(N, 234);
  RandomIntegers C(N, 345);
  RandomBooleans D(N, 456);
  Vector         T(N, 1);
  Vector         F(N, 0);
  Vector         S(N); thrust::sequence(S.begin(), S.end());
  Vector         U(2*N, 0);

  thrust::identity<int> I;


  { AdjacentDifference<Vector>     temp(A,B);       benchmark(temp); } // adjacent_difference
  { LowerBound<Vector>             temp(A,B,C);     benchmark(temp); } // binary_search
  { UpperBound<Vector>             temp(A,B,C);     benchmark(temp); }
  { BinarySearch<Vector>           temp(A,B,C);     benchmark(temp); }
  { Copy<Vector>                   temp(A,B);       benchmark(temp); } // copy
  { CopyN<Vector>                  temp(A,B);       benchmark(temp); }
  { CopyIf<Vector>                 temp(A,D,B);     benchmark(temp); }
  { Count<Vector>                  temp(D);         benchmark(temp); } // count
  { CountIf<Vector>                temp(D);         benchmark(temp); }
  { Equal<Vector>                  temp(A,A);       benchmark(temp); } // equal
  { MinElement<Vector>             temp(A);         benchmark(temp); } // extrema
  { MaxElement<Vector>             temp(A);         benchmark(temp); }
  { MinMaxElement<Vector>          temp(A);         benchmark(temp); }
  { Fill<Vector>                   temp(A);         benchmark(temp); } // fill
  { FillN<Vector>                  temp(A);         benchmark(temp); }
  { Find<Vector>                   temp(F,1);       benchmark(temp); } // find
  { FindIf<Vector>                 temp(F);         benchmark(temp); }
  { FindIfNot<Vector>              temp(T);         benchmark(temp); }
  { ForEach<Vector>                temp(A);         benchmark(temp); } // for_each
  { Gather<Vector>                 temp(S,A,B);     benchmark(temp); } // gather
  { GatherIf<Vector>               temp(S,D,A,B);   benchmark(temp); }
  { Generate<Vector>               temp(A);         benchmark(temp); } // generate
  { GenerateN<Vector>              temp(A);         benchmark(temp); }
  { InnerProduct<Vector>           temp(A,B);       benchmark(temp); } // inner_product
  { AllOf<Vector>                  temp(T);         benchmark(temp); } // logical
  { AnyOf<Vector>                  temp(F);         benchmark(temp); }
  { NoneOf<Vector>                 temp(F);         benchmark(temp); }
  { Merge<Vector>                  temp(A,B,U);     benchmark(temp); } // merge
  { Mismatch<Vector>               temp(A,A);       benchmark(temp); } // mismatch
  { Partition<Vector>              temp(A);         benchmark(temp); } // partition
  { PartitionCopy<Vector>          temp(D,A,B);     benchmark(temp); }
  { StablePartition<Vector>        temp(A);         benchmark(temp); }
  { StablePartitionCopy<Vector>    temp(D,A,B);     benchmark(temp); }
  { IsPartitioned<Vector>          temp(T);         benchmark(temp); }
  { PartitionPoint<Vector>         temp(T);         benchmark(temp); }
  { Reduce<Vector>                 temp(A);         benchmark(temp); } // reduce
  { ReduceByKey<Vector>            temp(D,A,B,C);   benchmark(temp); }
  { Remove<Vector>                 temp(D,0);       benchmark(temp); } // remove
  { RemoveCopy<Vector>             temp(D,A,0);     benchmark(temp); }
  { RemoveIf<Vector>               temp(A,D);       benchmark(temp); }
  { RemoveCopyIf<Vector>           temp(A,D,B);     benchmark(temp); }
  { Replace<Vector>                temp(D,0,2);     benchmark(temp); } // replace
  { ReplaceCopy<Vector>            temp(D,A,0,2);   benchmark(temp); }
  { ReplaceIf<Vector>              temp(A,D,I,0);   benchmark(temp); }
  { ReplaceCopyIf<Vector>          temp(A,D,B,I,0); benchmark(temp); }
  { Reverse<Vector>                temp(A);         benchmark(temp); }
  { ReverseCopy<Vector>            temp(A,B);       benchmark(temp); }
  { InclusiveScan<Vector>          temp(A,B);       benchmark(temp); }
  { ExclusiveScan<Vector>          temp(A,B);       benchmark(temp); }
  { InclusiveScanByKey<Vector>     temp(D,A,B);     benchmark(temp); }
  { ExclusiveScanByKey<Vector>     temp(D,A,B);     benchmark(temp); }
  { Scatter<Vector>                temp(A,S,B);     benchmark(temp); } // scatter
  { ScatterIf<Vector>              temp(A,S,D,B);   benchmark(temp); }
  { Sequence<Vector>               temp(A);         benchmark(temp); } // sequence
  { SetDifference<Vector>          temp(A,B,U);     benchmark(temp); } // set_operations
  { SetIntersection<Vector>        temp(A,B,U);     benchmark(temp); }
  { SetSymmetricDifference<Vector> temp(A,B,U);     benchmark(temp); }
  { SetUnion<Vector>               temp(A,B,U);     benchmark(temp); }
  { Sort<Vector>                   temp(A);         benchmark(temp); } // sort
  { SortByKey<Vector>              temp(A,B);       benchmark(temp); }
  { StableSort<Vector>             temp(A);         benchmark(temp); }
  { StableSortByKey<Vector>        temp(A,B);       benchmark(temp); }
  { IsSorted<Vector>               temp(S);         benchmark(temp); }
  { IsSortedUntil<Vector>          temp(S);         benchmark(temp); }
  { SwapRanges<Vector>             temp(A,B);       benchmark(temp); } // swap
  { UnaryTransform<Vector>         temp(A,B);       benchmark(temp); } // transform
  { BinaryTransform<Vector>        temp(A,B,C);     benchmark(temp); }
  { UnaryTransformIf<Vector>       temp(A,D,B);     benchmark(temp); }
  { BinaryTransformIf<Vector>      temp(A,B,D,C);   benchmark(temp); }
  { TransformReduce<Vector>        temp(A);         benchmark(temp); } // transform_reduce
  { TransformInclusiveScan<Vector> temp(A,B);       benchmark(temp); } // transform_scan
  { TransformExclusiveScan<Vector> temp(A,B);       benchmark(temp); }
  { UninitializedCopy<Vector>      temp(A,B);       benchmark(temp); } // uninitialized_copy
  { UninitializedFill<Vector>      temp(A);         benchmark(temp); } // fill
  { UninitializedFillN<Vector>     temp(A);         benchmark(temp); }
  { Unique<Vector>                 temp(D);         benchmark(temp); } // unique
  { UniqueCopy<Vector>             temp(D,A);       benchmark(temp); }
  { UniqueByKey<Vector>            temp(D,A);       benchmark(temp); }
  { UniqueByKeyCopy<Vector>        temp(D,A,B,C);   benchmark(temp); }

  // host<->device copy

  return 0;
}

