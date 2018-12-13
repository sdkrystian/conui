// Copyright 2018 Krystian Stasiowski

#include "Console.h"

void console::Clear()
{
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD topleft = {0, 0};
  CONSOLE_SCREEN_BUFFER_INFO screen;
  DWORD written;
  GetConsoleScreenBufferInfo(handle, &screen);
  FillConsoleOutputCharacterA(handle, ' ', screen.dwSize.X * screen.dwSize.Y, topleft, &written);
  FillConsoleOutputAttribute(handle, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, screen.dwSize.X * screen.dwSize.Y, topleft, &written);
  SetConsoleCursorPosition(handle, topleft);
}

void console::ClearLine(unsigned index)
{
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD pos = {0, index};
  CONSOLE_SCREEN_BUFFER_INFO screen;
  DWORD written;
  GetConsoleScreenBufferInfo(handle, &screen);
  FillConsoleOutputCharacterA(handle, ' ', screen.dwSize.X, pos, &written);
  FillConsoleOutputAttribute(handle, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, screen.dwSize.X, pos, &written);
  SetConsoleCursorPosition(handle, pos);
}


void console::ClearAt(unsigned x, unsigned y, unsigned length)
{
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD pos = {x, y};
  CONSOLE_SCREEN_BUFFER_INFO screen;
  DWORD written;
  GetConsoleScreenBufferInfo(handle, &screen);
  FillConsoleOutputCharacterA(handle, ' ', length, pos, &written);
  FillConsoleOutputAttribute(handle, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, length, pos, &written);
  SetConsoleCursorPosition(handle, pos);
}

void console::Resize(unsigned x, unsigned y)
{
  HWND console = GetConsoleWindow();
  RECT rect;
  GetWindowRect(console, &rect);
  MoveWindow(console, rect.left, rect.top, x, y, TRUE);
}

void console::SetCursorPosition(unsigned x, unsigned y)
{
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD pos = {x, y};
  SetConsoleCursorPosition(handle, pos);
}

COORD console::GetCursorPosition()
{
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO screen;
  GetConsoleScreenBufferInfo(handle, &screen);
  return screen.dwCursorPosition;
}

COORD console::GetSize()
{
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO screen;
  GetConsoleScreenBufferInfo(handle, &screen);
  return screen.dwSize;
}

void console::ShowConsoleCursor(bool show)
{
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO info;
  GetConsoleCursorInfo(handle, &info);
  info.bVisible = show;
  SetConsoleCursorInfo(handle, &info);
}

void console::SetTitle(const std::string& title)
{
  SetConsoleTitle(title.c_str());
}

void console::SetColor(Color color)
{
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(handle, static_cast<WORD>(color));
}

void console::SetColor(Color color, Color highlight)
{
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(handle, static_cast<WORD>(color) | (static_cast<WORD>(highlight) << 4));
}

void console::Write(const std::string& text, Color color, Color highlight)
{
  SetColor(color, highlight);
  std::cout << text;
}

void console::WriteAt(unsigned x, unsigned y, const std::string& text)
{
  SetCursorPosition(x, y);
  Write(text);
}

void console::WriteCentered(const std::string& text, Color color, Color highlight)
{
  Write(CenterString(text), color, highlight);
}

void console::WriteAt(unsigned x, unsigned y, const std::string& text, Color color)
{
  SetCursorPosition(x, y);
  Write(text, color);
}

void console::Write(const std::string& text, Color color)
{
  Write(text, color, Color::BLACK);
}

void console::Write(const std::string& text)
{
  Write(text, Color::WHITE);
}

void console::WriteAt(unsigned x, unsigned y, const std::string& text, Color color, Color highlight)
{
  SetCursorPosition(x, y);
  Write(text, color, Color::BLACK);
}

void console::WriteCentered(const std::string& text, Color color)
{
  Write(CenterString(text), color);
}

void console::WriteCentered(const std::string& text)
{
  WriteCentered(text, Color::WHITE);
}

void console::WriteLine(const std::string& text, Color color, Color highlight)
{
  Write(text, color, highlight);
  std::cout << std::endl;
}

void console::WriteLine(const std::string& text, Color color)
{
  WriteLine(text, color, Color::BLACK);
}

void console::WriteLine(const std::string& text)
{
  WriteLine(text, Color::WHITE);
}

void console::WriteLineAt(unsigned x, unsigned y, const std::string& text, Color color, Color highlight)
{
  SetCursorPosition(x, y);
  WriteLine(text, color, highlight);
}

void console::WriteLineAt(unsigned x, unsigned y, const std::string& text)
{
  SetCursorPosition(x, y);
  WriteLine(text);
}

void console::WriteLineCentered(const std::string& text, Color color, Color highlight)
{
  WriteLine(CenterString(text), color, highlight);
}

void console::WriteLineAt(unsigned x, unsigned y, const std::string& text, Color color)
{
  SetCursorPosition(x, y);
  WriteLine(text, color);
}

void console::WriteLineCentered(const std::string& text, Color color)
{
  WriteLineCentered(text, color, Color::BLACK);
}

void console::WriteLineCentered(const std::string& text)
{
  WriteLineCentered(text, Color::WHITE);
}

void console::WriteList(const std::vector<std::string>& text, Color color, Color highlight)
{
  for (const std::string& s : text)
  {
    WriteLine(s, color, highlight);
  }
}

void console::WriteList(const std::vector<std::string>& text, Color color)
{
  WriteList(text, color, Color::BLACK);
}

void console::WriteList(const std::vector<std::string>& text)
{
  for (const std::string& s : text)
  {
    WriteLine(s, Color::WHITE);
  }
}

void console::WriteListCentered(const std::vector<std::string>& text, Color color, Color highlight)
{
  for (const std::string& s : text)
  {
    WriteLineCentered(s, color, highlight);
  }
}

void console::WriteListCentered(const std::vector<std::string>& text, Color color)
{
  WriteListCentered(text, color, Color::BLACK);
}

void console::WriteListCentered(const std::vector<std::string>& text)
{
  for (const std::string& s : text)
  {
    WriteLineCentered(s, Color::WHITE);
  }
}

void console::ColorLine(Color color, unsigned length)
{
  SetColor(Color::WHITE, color);
  std::string line;
  for (unsigned i = 0; i < length; ++i)
    line += " ";
  std::cout << line;
}

void console::ColorLineCentered(Color color, unsigned length)
{
  SetColor(Color::WHITE, color);
  unsigned x = (GetSize().X - length) / 2;
  std::string line;
  for (unsigned i = 0; i < length; ++i)
    line += " ";
  SetCursorPosition(x, GetCursorPosition().Y);
  std::cout << line;
}

std::string console::ReadLine()
{
  std::string input;
  std::getline(std::cin, input);
  return input;
}

std::string console::ReadLine(Color color)
{
  SetColor(color, Color::BLACK);
  std::string input;
  std::getline(std::cin, input);
  return input;
}

std::string console::ReadLine(Color color, Color highlight)
{
  SetColor(color, highlight);
  std::string input;
  std::getline(std::cin, input);
  return input;
}

std::string console::ReadLinePrompt(const std::string& prompt, Color color)
{
  Write(prompt, color);
  return ReadLine();
}

std::string console::ReadLinePrompt(const std::string& prompt, Color color, Color highlight)
{
  Write(prompt, color, highlight);
  return ReadLine();
}

std::string console::ReadLinePrompt(const std::string& prompt)
{
  Write(prompt);
  return ReadLine();
}

std::string console::ReadLineAt(unsigned x, unsigned y)
{
  SetCursorPosition(x, y);
  return ReadLine();
}

std::string console::ReadLineAt(unsigned x, unsigned y, Color color)
{
  SetCursorPosition(x, y);
  return ReadLine(color);
}

std::string console::ReadLineAt(unsigned x, unsigned y, Color color, Color highlight)
{
  SetCursorPosition(x, y);
  return ReadLine(color, highlight);
}

std::string console::ReadLinePromptAt(unsigned x, unsigned y, const std::string& prompt, Color color)
{
  SetCursorPosition(x, y);
  return ReadLinePrompt(prompt, color);
}

std::string console::ReadLinePromptAt(unsigned x, unsigned y, const std::string& prompt)
{
  SetCursorPosition(x, y);
  return ReadLinePrompt(prompt);
}

std::string console::ReadLinePromptAt(unsigned x, unsigned y, const std::string& prompt, Color color, Color highlight)
{
  SetCursorPosition(x, y);
  return ReadLinePrompt(prompt, color, highlight);
}

std::string console::CenterString(const std::string& str)
{
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO screen;
  int columns;
  GetConsoleScreenBufferInfo(handle, &screen);
  columns = screen.srWindow.Right - screen.srWindow.Left + 1;
  std::string output;
  size_t padding = (columns / 2) - (str.size() / 2);
  for (int i = 0; i < padding; ++i)
  {
    output += ' ';
  }
  return output + str;
}

std::vector<std::string> console::WrapText(conui::Vector size, uint16_t padding, const std::string& text)
{
  std::vector<std::string> output;
  int lines = std::ceil(text.size() / static_cast<float>(size.x - padding));
  int chars_per = std::floor(text.size() / (text.size() / static_cast<float>(size.x - padding)));
  int last_line = text.size() % chars_per;
  int x_index = 0;
  for (int i = 0; i < lines; ++i)
  {
    output.push_back(std::string(text.begin() + x_index, text.begin() + x_index + (((i == lines - 1) && last_line) ? last_line : chars_per)));
    x_index += chars_per;
  }
  return output;
}