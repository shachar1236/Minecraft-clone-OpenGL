#include "ECS.h"

using namespace Logic;

std::vector<std::shared_ptr<Entity>> ECS::KeyEventSubscribers = std::vector<std::shared_ptr<Entity>>();
std::vector<std::shared_ptr<Entity>> ECS::CharEventSubscribers = std::vector<std::shared_ptr<Entity>>();
std::vector<std::shared_ptr<Entity>> ECS::CursorPositionEventSubscribers = std::vector<std::shared_ptr<Entity>>();
std::vector<std::shared_ptr<Entity>> ECS::MouseButtonEventSubscribers = std::vector<std::shared_ptr<Entity>>();
std::vector<std::shared_ptr<Entity>> ECS::MouseScrollEventSubscribers = std::vector<std::shared_ptr<Entity>>();

std::vector<std::shared_ptr<Entity>> ECS::entities = std::vector<std::shared_ptr<Entity>>();
int ECS::lastId = -1;

void ECS::init(GLFWwindow* window)
{
    glfwSetKeyCallback(window, _key_event_callback);
    glfwSetCharCallback(window, _char_event_callback);
    glfwSetCursorPosCallback(window, _cursor_position_event_callback);
    glfwSetMouseButtonCallback(window, _mouse_button_event_callback);
    glfwSetScrollCallback(window, _mouse_scroll_event_callback);
}

void ECS::Update(const float& deltaTime)
{
    for (auto entity : entities) {
        entity->Update(deltaTime);
    }
}

void ECS::AddEntity(const std::shared_ptr<Entity>& entity)
{
    entity->Setup();
    entities.push_back(entity);
}

std::shared_ptr<Entity> ECS::GetEntity(const std::string& name)
{
    for (auto& entity : entities) {
        if (entity->name == name) {
            return entity;
        }
    }
    return 0;
}

std::shared_ptr<Entity> ECS::GetEntity(const int& id)
{
    int index = entities.size() - 1;
    if (id < index) {
        index = id;
    }

    int jump = 1;
    while (true) {
        std::shared_ptr<Entity> e = entities[index];
        if (e->id == id) {
            return e;
        } else if (e->id > id) {
            jump = -1;
        } else if (e->id < id) {
            jump = 1;
        }
        index += jump;
    }
}

int ECS::GetNewId()
{
    ECS::lastId++;
    return ECS::lastId;
}

void ECS::_key_event_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    for (auto& eventReciver : KeyEventSubscribers) {
        eventReciver->keyEventHandler(key, scancode, action, mods);
    }
}

void ECS::_char_event_callback(GLFWwindow* window, unsigned int codepoint)
{
    for (auto& eventReciver : CharEventSubscribers) {
        eventReciver->charEventHandler(codepoint);
    }
}

void ECS::_cursor_position_event_callback(GLFWwindow* window, double xpos, double ypos)
{
    for (auto& eventReciver : CursorPositionEventSubscribers) {
        eventReciver->cursorPositionEventHandler(xpos, ypos);
    }
}

void ECS::_mouse_button_event_callback(GLFWwindow* window, int button, int action, int mods)
{
    for (auto& eventReciver : MouseButtonEventSubscribers) {
        eventReciver->mouseButtonEventHandler(button, action, mods);
    }
}

void ECS::_mouse_scroll_event_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    for (auto& eventReciver : MouseScrollEventSubscribers) {
        eventReciver->mouseScollEventHandler(xoffset, yoffset);
    }
}
