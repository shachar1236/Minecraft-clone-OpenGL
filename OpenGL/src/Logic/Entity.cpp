#include "Entity.h"
#include "ECS.h"

namespace Logic {
Entity::Entity(std::string name_)
    : name(name_)
{
    id = ECS::GetNewId();
    // Setup();
}

DrawObject Entity::getDrawObject() { return { nullptr, nullptr, nullptr }; }
}