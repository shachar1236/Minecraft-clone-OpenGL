#pragma once
#include "Core/Core.h"
#include "Entity.h"
#include <algorithm>
#include <memory>
#include <string>
#include <vector>

namespace Logic {
class ECS {
public:
    static void init(GLFWwindow* window);

    static std::vector<std::shared_ptr<Entity>> entities;

    static void Update(const float& deltaTime);

    static void AddEntity(const std::shared_ptr<Entity>& entity);

    static std::shared_ptr<Entity> GetEntity(const std::string& name);
    static std::shared_ptr<Entity> GetEntity(const int& id);

    static int GetNewId();

    static int lastId;

    // subcribe to events
    static std::vector<std::shared_ptr<Entity>> KeyEventSubscribers;
    static std::vector<std::shared_ptr<Entity>> CharEventSubscribers;
    static std::vector<std::shared_ptr<Entity>> CursorPositionEventSubscribers;
    static std::vector<std::shared_ptr<Entity>> MouseButtonEventSubscribers;
    static std::vector<std::shared_ptr<Entity>> MouseScrollEventSubscribers;

    // event handlers
    static void _key_event_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void _char_event_callback(GLFWwindow* window, unsigned int codepoint);
    static void _cursor_position_event_callback(GLFWwindow* window, double xpos, double ypos);
    static void _mouse_button_event_callback(GLFWwindow* window, int button, int action, int mods);
    static void _mouse_scroll_event_callback(GLFWwindow* window, double xoffset, double yoffset);
};

}
