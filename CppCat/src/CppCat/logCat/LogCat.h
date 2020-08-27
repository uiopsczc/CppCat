#pragma once
#include "CppCat/Core.h"

#include "spdlog/spdlog.h"

namespace CppCat
{
  class CppCat_API LogCat
  {
  private:
    static std::shared_ptr<spdlog::logger> __logger;
    static bool __is_inited;
    inline static void InitIfNotInited();
  public:
    inline static std::shared_ptr<spdlog::logger>& GetLogger()
    {
      InitIfNotInited();
      return __logger;
    }
  };
}

#define cppcat_trace(...) ::CppCat::LogCat::GetLogger()->trace(__VA_ARGS__)
#define cppcat_info(...)  ::CppCat::LogCat::GetLogger()->info(__VA_ARGS__)
#define cppcat_warn(...)  ::CppCat::LogCat::GetLogger()->warn(__VA_ARGS__)
#define cppcat_error(...) ::CppCat::LogCat::GetLogger()->error(__VA_ARGS__)
#define cppcat_fatal(...) ::CppCat::LogCat::GetLogger()->fatal(__VA_ARGS__)



