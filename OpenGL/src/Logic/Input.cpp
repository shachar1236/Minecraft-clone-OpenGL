#include "Input.h"

namespace Logic {
void Input::init(GLFWwindow* window) { _window = window; }

GLFWwindow* Input::_window = nullptr;
std::shared_ptr<spdlog::logger> Input::logger = Log::createLogger("Input");

bool Input::isKeyPressed(const unsigned int& key)
{
    int ans = glfwGetKey(_window, key);
    // logger->info("Key {0} is {1}", key, ans);
    return ans == GLFW_REPEAT || ans == GLFW_PRESS;
}

bool Input::isKeyJustPressed(const unsigned int& key) { return glfwGetKey(_window, key) == GLFW_PRESS; }

bool Input::isKeyJustReleased(const unsigned int& key) { return glfwGetKey(_window, key) == GLFW_RELEASE; }

}