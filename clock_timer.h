#pragma once

#include <ctime>

struct clock_timer
{
  std::clock_t start;

  clock_timer()
    : start(std::clock())
  {}

  void restart()
  {
    start = std::clock();
  }

  double elapsed()
  {
    return (std::clock() - start) * epsilon();
  }

  double epsilon()
  {
    // return msecs
    return (1.0 / CLOCKS_PER_SEC) / 1000;
  }
};

