#pragma once
#include "Entity.h"
#include <algorithm>
#include <memory>
#include <string>
#include <vector>

namespace Logic {
class ECS {
public:
    static std::vector<std::shared_ptr<Entity>> entities;

    static void Update(const float& deltaTime);

    static void AddEntity(const std::shared_ptr<Entity>& entity);

    static std::shared_ptr<Entity> GetEntity(const std::string& name);
    static std::shared_ptr<Entity> GetEntity(const int& id);

    static int GetNewId();

    static int lastId;
};

}
