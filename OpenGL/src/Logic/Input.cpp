#include "Input.h"

namespace Logic {

GLFWwindow* Input::_window = nullptr;

bool Input::isKeyPressed(const unsigned int& key) { return glfwGetKey(_window, key) == GLFW_REPEAT; }

bool Input::isKeyJustPressed(const unsigned int& key) { return glfwGetKey(_window, key) == GLFW_PRESS; }

bool Input::isKeyJustReleased(const unsigned int& key) { return glfwGetKey(_window, key) == GLFW_RELEASE; }

}