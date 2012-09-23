#pragma once

#include <tbb/tick_count.h>

struct tbb_timer
{
  tbb::tick_count start;

  tbb_timer()
  {
    restart();
  }

  void restart()
  {
    start = tbb::tick_count::now();
  }

  double elapsed()
  {
    // return msecs
    return (tbb::tick_count::now() - start).seconds() / 1000;
  }
};

