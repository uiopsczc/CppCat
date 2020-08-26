#include <CppCat.h>

class Sandbox:public CppCat::Application
{
public:
  Sandbox()
  {
  }
  ~Sandbox()
  {
  }
};



CppCat::Application* CppCat::CreateApplication()
{
  return new Sandbox();
}