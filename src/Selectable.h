#pragma once

namespace conui
{
  class Selectable
  {
  public:
    Selectable(bool selected) : selected_(selected)
    {

    }

    virtual void Select(bool selected) = 0;

    bool Selected() const noexcept
    {
      return selected_; 
    }
  protected:
    bool selected_;
  };
}