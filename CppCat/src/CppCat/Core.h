#pragma once

#ifdef CppCat_Platform_Windows
  #ifdef CppCat_Build_Dll
    #define CppCat_API __declspec(dllexport)
  #else
    #define CppCat_API __declspec(dllimport)
  #endif
#endif
