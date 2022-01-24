#include "spdlog/fmt/fmt.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"
#include <string>

namespace Log {
std::shared_ptr<spdlog::logger> createLogger(const std::string name);
}