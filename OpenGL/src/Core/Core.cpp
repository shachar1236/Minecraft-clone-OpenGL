#include "Core.h"

namespace Log {

std::shared_ptr<spdlog::logger> createLogger(const std::string name)
{
    spdlog::set_pattern("%^[%T] %n: %v%$");
    std::shared_ptr<spdlog::logger> logger = spdlog::stdout_color_mt(name);
    logger->set_level(spdlog::level::trace);
    return logger;
}

}