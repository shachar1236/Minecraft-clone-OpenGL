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
};
}
