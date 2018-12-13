#pragma once
#include <type_traits>
#include "Vector.h"

namespace conui
{
  class Widget
  {
  public:
    Widget(Vector position, bool visible) : position_(position), visible_(visible)
    {
      
    }

    virtual ~Widget()
    {

    }

    virtual void Draw() = 0;
    virtual void Remove() = 0;

    template<typename T>
    bool HasBehavior()
    {
      return (dynamic_cast<T*>(this));
    }

    void Show(bool show)
    {
      if ((show && visible_) || (!show && !visible_))
        return;
      visible_ = show;
      if (show)
      {
        Draw();
      }
      else
      {
        Remove();
      }
    }

    void Redraw()
    {
      if (visible_)
      {
        Remove();
        Draw();
      }
    }
    
    virtual void Move(Vector position)
    {
      position_ = position;
      Redraw();
    }

    Vector Position() const noexcept
    {
      return position_;
    }

    bool Visible() const noexcept
    {
      return visible_;
    }
  protected:
    Vector position_;
    bool visible_;
  };
}