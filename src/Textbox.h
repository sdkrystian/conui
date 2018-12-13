#pragma once
#include "Widget.h"
#include "Resizeable.h"
#include "Console.h"

namespace conui
{
  class Textbox : public Widget, public Resizeable
  {
  public:
    std::string text;
    Color text_color;
    Color back_color;

    Textbox(Vector position, Vector size, uint16_t padding, const std::string& txt, Color color_text, Color color_back, bool visible = true, bool selected = false, bool activated = false)
      : Widget(position, visible), Resizeable(size), text_color(color_text), back_color(color_back), text(txt), padding_(padding)
    {
      if (text.size() > ((size.x - padding) * size.y))
        text.resize((size.x - padding) * size.y);
      if (visible)
        Draw();
    }

    void Resize(Vector size) override
    {
      size_ = size;;
      Redraw();
    }
  protected:
    void Draw() override
    {
      for (uint64_t y = 0; y < size_.y; ++y)
      {
        console::SetCursorPosition(position_.x, position_.y + y);
        console::ColorLine(back_color, size_.x);
      }
      std::vector<std::string>&& wrapped = console::WrapText(size_, padding_, text);
      for (int i = 0; i < wrapped.size(); ++i)
      {
        console::WriteLineAt(position_.x + std::round((size_.x - wrapped[i].size()) / 2), position_.y + std::round((size_.y - wrapped.size()) / 2) + i, wrapped[i], text_color, back_color);
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
    uint16_t padding_;
  };
}
