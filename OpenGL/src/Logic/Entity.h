#pragma once
#include "ECS.h"
#include "Renderer/DrawObject.h"
#include <string>

class Entity {
public:
    unsigned int id;
    std::string name;
    Entity(std::string name_)
        : name(name_)
    {
        id = ECS::GetNewId();
        Setup();
    }
    virtual ~Entity();

    virtual void Setup() = 0;
    virtual void Update(const float& deltaTime) = 0;

    virtual DrawObject getDrawObject() = 0;

    bool operator==(const Entity& other) { return id == other.id; }
    bool operator==(const int& otherId) { return id == otherId; }
    bool operator==(const std::string& otherName) { return name == otherName; }
};
