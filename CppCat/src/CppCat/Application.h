#pragma once
#include "Core.h"
namespace CppCat
{
  class CppCat_API Application
  {
  public:
    Application();
    virtual ~Application();

    void Run();
  };

  Application* CreateApplication();
}

