#pragma once
#include "Renderer/DrawObject.h"
#include <string>

namespace Logic {
class Entity {
public:
    unsigned int id;
    std::string name;
    const bool isDrawble = true;
    Entity(std::string name_);
    virtual ~Entity() {};

    virtual void Setup() = 0;
    virtual void Update(const float& deltaTime) = 0;

    virtual DrawObject getDrawObject();

    // called when key is pressed
    virtual void keyEventHandler(const int& key, const int& scancode, const int& action, const int& mods) {};
    // called when key is typed
    virtual void charEventHandler(const unsigned int& codepoint) {};
    // called when mouse moved
    virtual void cursorPositionEventHandler(const double& xpos, const double& ypos) {};
    // called when mouse is pressed
    virtual void mouseButtonEventHandler(const int& button, const int& action, const int& mods) {};
    // called when mouse scroll
    virtual void mouseScollEventHandler(const double& xoffset, const double& yoffset) {};
};
}
