#pragma once
#include "Core/Core.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <memory>

namespace Logic {
class Input {
public:
    static GLFWwindow* _window;
    static std::shared_ptr<spdlog::logger> logger;

    static bool isKeyPressed(const unsigned int& key);
    static bool isKeyJustPressed(const unsigned int& key);
    static bool isKeyJustReleased(const unsigned int& key);
};
}
