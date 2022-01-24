#pragma once
#include "Logic/Entity.h"
#include <glm/glm.hpp>

class Camera : public Logic::Entity {
public:
    const bool isDrawble = false;

    Camera(const float& left, const float& right, const float& bottom, const float& top);
    virtual ~Camera() override {};

    virtual void Setup() override;
    virtual void Update(const float& deltaTime);

    glm::mat4 getViewProjectionMatrix() const;
    virtual void setPosition(const glm::vec3& pos);

    void recalculateProjectionViewMatrix();

private:
    glm::mat4 view;
    glm::mat4 proj;

    glm::mat4 viewProj;

    glm::vec3 position;
};
