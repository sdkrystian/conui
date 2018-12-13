#pragma once
#include "Widget.h"
#include "Console.h"

namespace conui
{
  class Text : public Widget
  {
  public:
    std::string text;
    Color text_color;
    Color back_color;

    Text(Vector position, const std::string& txt, Color color_text, Color color_back, bool visible = true)
      : Widget(position, visible), text_color(color_text), back_color(color_back), text(txt)
    {
      if (visible)
        Draw();
    }
  protected:
    void Draw() override
    {
        console::WriteLineAt(position_.x, position_.y, text, text_color, back_color);
    }

    void Remove() override
    {
      console::SetCursorPosition(position_.x, position_.y);
      console::ColorLine(Color::BLACK, text.size());
    }
  };
}
