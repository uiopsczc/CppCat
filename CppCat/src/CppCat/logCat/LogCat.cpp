#include "CppCatPCH.h"
#include "LogCat.h"


#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"
namespace CppCat
{
  std::shared_ptr<spdlog::logger> LogCat::__logger;
  bool LogCat::__is_inited;
  void LogCat::InitIfNotInited()
  {
    if (__is_inited)
      return;
    __is_inited = true;
    //global setting
    spdlog::set_pattern("%^[%T]: %v%$");

    //instance setting
    __logger = spdlog::stdout_color_mt("CppCat");
    __logger->set_level(spdlog::level::trace);
  }
}

