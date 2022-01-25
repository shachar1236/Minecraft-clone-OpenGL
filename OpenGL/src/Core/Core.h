#include "spdlog/fmt/fmt.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

namespace Log {
std::shared_ptr<spdlog::logger> createLogger(const std::string name);
}