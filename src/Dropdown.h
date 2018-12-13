#pragma once
#include <vector>
#include "Widget.h"
#include "Selectable.h"
#include "Interactable.h"
#include "Resizeable.h"
#include"Console.h"

namespace conui
{
  class Dropdown : public Widget, public Selectable, public Interactable, public Resizeable
  {
  public:
    std::string normal_text;
    std::string selected_text;
    std::string activated_text;

    Dropdown(Vector position, Vector size, Vector offset, uint16_t padding, const std::vector<Widget*>& elements, const std::string& text_normal, const std::string& text_selected, const std::string& text_activated, Color text_color_normal, Color text_color_selected, Color text_color_activated, Color back_color_normal, Color back_color_selected, bool visible = true, bool selected = false, bool activated = false)
      : Widget(position, visible), Interactable(activated), Selectable(selected), Resizeable(size), text_color_normal_(text_color_normal), text_color_selected_(text_color_selected), text_color_activated_(text_color_activated), back_color_normal_(back_color_normal), back_color_selected_(back_color_selected), normal_text(text_normal), selected_text(text_selected), activated_text(text_activated), padding_(padding), offset_(offset), elements_(elements)
    {
      int max_text_size = (size.x - padding) * size.y;
      if (normal_text.size() > max_text_size)
        normal_text.resize(max_text_size);
      if (selected_text.size() > max_text_size)
        selected_text.resize(max_text_size);
      if (activated_text.size() > max_text_size)
        activated_text.resize(max_text_size);
      for (int i = 0; i < elements_.size(); ++i)
        elements_[i]->Move({position_.x + elements_[i]->Position().x, (i ? elements_[i - 1]->HasBehavior<Resizeable>() ? elements_[i - 1]->Position().y + dynamic_cast<Resizeable*>(elements_[i - 1])->Size().y : elements_[i - 1]->Position().y + 1 : position_.y + size_.y) + elements_[i]->Position().y});
      if (visible)
        Draw();
    }

    size_t GetSelectedIndex()
    {
      return selected_;
    }

    void SetSelectedIndex(size_t n)
    {
      selected_index_ = n % selected_index_ + 1;
    }

    void Resize(Vector size) override
    {
      size_ = size;;
      Redraw();
    }

    void Select(bool selected) override
    {
      if ((selected && selected_) || (!selected && !selected_))
        return;
      selected_ = selected;
      Redraw();
    }

    void Activate(bool activated) override
    {
      if ((activated && activated_) || (!activated && !activated_))
        return;
      Remove();
      activated_ = activated;
      Draw();
    }
  protected:
    void Draw() override
    {
      Color back_color = selected_ ? back_color_selected_ : back_color_normal_;
      Color text_color = activated_ ? text_color_activated_ : selected_ ? text_color_selected_ : text_color_normal_;
      std::string& text = activated_ ? activated_text : selected_ ? selected_text : normal_text;
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
      if (activated_)
        for (Widget* w : elements_)
          w->Draw();
    }

    void Remove() override
    {
      for (uint64_t y = 0; y < size_.y; ++y)
      {
        console::SetCursorPosition(position_.x, position_.y + y);
        console::ColorLine(Color::BLACK, size_.x);
      }
      if (activated_)
        for (Widget* w : elements_)
          w->Remove();
    }
  private:
    template<typename T>
    T& GetElementAs(size_t elem)
    {
      if (!elements_[elem]->HasBehavior<T>())
        throw std::bad_cast();
      return *dynamic_cast<T*>(elements_[elem]);
    }

    std::vector<Widget*> elements_;
    size_t selected_index_;
    Vector offset_;
    uint16_t padding_;
    Color text_color_normal_;
    Color text_color_selected_;
    Color text_color_activated_;
    Color back_color_normal_;
    Color back_color_selected_;
  };
}