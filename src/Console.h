// Copyright 2018 Krystian Stasiowski

#pragma once
#include <windows.h>
#include <string>
#include <vector>
#include <iostream>
#include "Vector.h"

enum class Color
{
  BLACK = 0,
  BLUE = 1,
  GREEN = 2,
  AQUA = 3,
  RED = 4,
  PURPLE = 5,
  YELLOW = 6,
  WHITE = 7,
  GRAY = 8,
  LIGHT_BLUE = 9,
  LIGHT_GREEN = 10,
  LIGHT_AQUA = 11,
  LIGHT_RED = 12,
  LIGHT_PURPLE = 13,
  LIGHT_YELLOW = 14,
  BRIGHT_WHITE = 15
};

namespace console
{
   void Clear();
   void ClearLine(unsigned index);
   void ClearAt(unsigned x, unsigned y, unsigned length);
   void Resize(unsigned x, unsigned y);
   void SetCursorPosition(unsigned x, unsigned y);
   COORD GetCursorPosition();
   COORD GetSize();
   void ShowConsoleCursor(bool show);
   void SetTitle(const std::string& title);
   void SetColor(Color color);
   void SetColor(Color color, Color highlight);
   void Write(const std::string& text, Color color, Color highlight);
   void Write(const std::string& text, Color color);
   void Write(const std::string& text);
   void WriteAt(unsigned x, unsigned y, const std::string& text, Color color, Color highlight);
   void WriteAt(unsigned x, unsigned y, const std::string& text, Color color);
   void WriteAt(unsigned x, unsigned y, const std::string& text);
   void WriteCentered(const std::string& text, Color color, Color highlight);
   void WriteCentered(const std::string& text, Color color);
   void WriteCentered(const std::string& text);
   void WriteLine(const std::string& text, Color color, Color highlight);
   void WriteLine(const std::string& text, Color color);
   void WriteLine(const std::string& text);
   void WriteLineAt(unsigned x, unsigned y, const std::string& text, Color color, Color highlight);
   void WriteLineAt(unsigned x, unsigned y, const std::string& text, Color color);
   void WriteLineAt(unsigned x, unsigned y, const std::string& text);
   void WriteLineCentered(const std::string& text, Color color, Color highlight);
   void WriteLineCentered(const std::string& text, Color color);
   void WriteLineCentered(const std::string& text);
   void WriteList(const std::vector<std::string>& text, Color color, Color highlight);
   void WriteList(const std::vector<std::string>& text, Color color);
   void WriteList(const std::vector<std::string>& text);
   void WriteListCentered(const std::vector<std::string>& text, Color color, Color highlight);
   void WriteListCentered(const std::vector<std::string>& text, Color color);
   void WriteListCentered(const std::vector<std::string>& text);
   void ColorLine(Color color, unsigned length);
   void ColorLineCentered(Color color, unsigned length);
   std::string ReadLine();
   std::string ReadLine(Color color);
   std::string ReadLine(Color color, Color highlight);
   std::string ReadLinePrompt(const std::string& prompt, Color color);
   std::string ReadLinePrompt(const std::string& prompt);
   std::string ReadLinePrompt(const std::string& prompt, Color color, Color highlight);
   std::string ReadLineAt(unsigned x, unsigned y);
   std::string ReadLineAt(unsigned x, unsigned y, Color color);
   std::string ReadLineAt(unsigned x, unsigned y, Color color, Color highlight);
   std::string ReadLinePromptAt(unsigned x, unsigned y, const std::string& prompt, Color color);
   std::string ReadLinePromptAt(unsigned x, unsigned y, const std::string& prompt);
   std::string ReadLinePromptAt(unsigned x, unsigned y, const std::string& prompt, Color color, Color highlight);
   std::string CenterString(const std::string& str);
   std::vector<std::string> WrapText(conui::Vector size, uint16_t padding, const std::string& text);
};