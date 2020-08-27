#pragma once

#ifdef CppCat_Platform_Windows

extern CppCat::Application* CppCat::CreateApplication();

int main(int argc, char** argv)
{
  cppcat_trace("start...");
  auto application = CppCat::CreateApplication();
  application->Run();
  delete application;
}
#endif
