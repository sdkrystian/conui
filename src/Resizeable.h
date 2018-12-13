#pragma once
#include "Vector.h"

namespace conui
{
  class Resizeable
  {
  public:
    Resizeable(Vector size) : size_(size)
    {

    }

    virtual void Resize(Vector size) = 0;

    Vector Size() const noexcept
    {
      return size_;
    }
  protected:
    Vector size_;
  };
}