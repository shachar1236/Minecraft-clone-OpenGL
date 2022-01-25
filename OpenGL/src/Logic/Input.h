#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Logic {
class Input {
public:
    static GLFWwindow* _window;

    static bool isKeyPressed(const unsigned int& key);
    static bool isKeyJustPressed(const unsigned int& key);
    static bool isKeyJustReleased(const unsigned int& key);
};
}
