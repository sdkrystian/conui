#pragma once

namespace conui
{
  class Interactable
  {
  public:
    Interactable(bool activated) : activated_(activated)
    {

    }

    virtual void Activate(bool activated) = 0;

    bool Activated() const noexcept
    {
      return activated_;
    }
  protected:
    bool activated_;
  };
}