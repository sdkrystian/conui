#pragma once
#include <string>
#include "Widget.h"
#include "Resizeable.h"
#include "Console.h"

namespace conui
{
  class Rectangle : public Widget, public Resizeable
  {
  public:
    Rectangle(Vector position, Vector size, Color color, bool visible = true) : Widget(position, visible), Resizeable(size), color_(color)
    {
      if (visible)
        Draw();
    }
    
    void Resize(Vector size) override
    {
      size_ = size;
      Redraw();
    }
  protected:
    void Draw() override
    {
      for (uint64_t y = 0; y < size_.y; ++y)
      {
        console::SetCursorPosition(position_.x, position_.y + y);
        console::ColorLine(color_, size_.x);
      }
    }

    void Remove() override
    {
      for (uint64_t y = 0; y < size_.y; ++y)
      {
        console::SetCursorPosition(position_.x, position_.y + y);
        console::ColorLine(Color::BLACK, size_.x);
      }
    }
  private:
    Color color_;
  };
}