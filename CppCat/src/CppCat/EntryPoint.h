#pragma once

#ifdef CppCat_Platform_Windows

extren CppCat::Application* CppCat::CreateApplication();
int main(int argc, char** argv)
{
  printf("start....\n")
  auto application = CppCat::CreateApplication();
  application->Run();
  delete application;
}
#endif
