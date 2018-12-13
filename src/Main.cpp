#include <iostream>
#include <typeinfo>
#include "Console.h"
#include "Widget.h"
#include "Selectable.h"
#include "Interactable.h"
#include "Rectangle.h"
#include "Button.h"
#include "Textbox.h"
#include "Text.h"
#include "Dropdown.h"

int main()
{ 
  console::ShowConsoleCursor(false);
  conui::Button button1({0, 1}, {8, 4},  0, "Button", "selected", "activated", Color::AQUA, Color::LIGHT_GREEN, Color::LIGHT_PURPLE, Color::WHITE, Color::BRIGHT_WHITE, []() { }, []() {}, true);
  conui::Rectangle rectangle({0, 1}, {5, 8}, Color::LIGHT_AQUA, false);
  conui::Button button2({0, 1}, {8, 4}, 0, "Button", "selected", "activated", Color::LIGHT_BLUE, Color::LIGHT_GREEN, Color::LIGHT_PURPLE, Color::WHITE, Color::BRIGHT_WHITE, []() {}, []() {}, false);
  conui::Text text({0, 1}, "Text", Color::BRIGHT_WHITE, Color::LIGHT_GREEN, false);
  conui::Textbox textbox({0, 1}, {4, 4}, 0, "Textbox", Color::AQUA, Color::LIGHT_RED, false);
  conui::Dropdown dropdown({1, 1}, {8, 4}, {0, 0}, 0, std::vector<conui::Widget*>{ &button1, &rectangle, &button2, &text, &textbox }, "Dropdown", "selected", "activated", Color::AQUA, Color::LIGHT_GREEN, Color::LIGHT_PURPLE, Color::WHITE, Color::BRIGHT_WHITE, true, false, true);
  //while (true)
  //{
  //  if (std::cin.get())
  //  {
  //    if (button1.Selected())
  //    {
  //      if (button1.Activated())
  //      {
  //        button1.Activate(false);
  //        button1.Select(false);
  //      }
  //      else
  //      {
  //        button1.Activate(true);
  //      }
  //    }
  //    else
  //    {
  //      button1.Select(true);
  //    }
  //  }
  //}
  while (true)
  {
    if (std::cin.get())
    {
      if (dropdown.Selected())
      {
        if (dropdown.Activated())
        {
          dropdown.Activate(false);
          dropdown.Select(false);
        }
        else
        {
          dropdown.Activate(true);
        }
      }
      else
      {
        dropdown.Select(true);
      }
    }
  }
  std::cin.ignore();
  return 0;
}