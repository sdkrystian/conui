#pragma once
#include <cstdint>

namespace conui
{
  struct Vector
  {
    Vector(uint64_t x, uint64_t y) : x(x), y(y)
    {

    }

    uint64_t x;
    uint64_t y;
  };
}