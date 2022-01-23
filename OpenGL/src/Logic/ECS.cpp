#include "ECS.h"

void ECS::Update(const float& deltaTime)
{
    for (auto entity : entities) {
        entity->Update(deltaTime);
    }
}

void ECS::AddEntity(const std::shared_ptr<Entity>& entity) { entities.push_back(entity); }

std::shared_ptr<Entity> ECS::GetEntity(const std::string& name)
{
    auto e = std::find(entities.begin(), entities.end(), name);
    if (e != entities.end()) {
        return (*e);
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
