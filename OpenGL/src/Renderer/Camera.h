#pragma once
#include "Core/Core.h"
#include "Logic/Entity.h"
#include <glm/glm.hpp>

class Camera : public Logic::Entity {
public:
    const bool isDrawble = false;

    Camera(const float& fov, const float& aspect_ratio);
    virtual ~Camera() override {};

    virtual void Setup() override;
    virtual void Update(const float& deltaTime);

    glm::mat4 getViewProjectionMatrix() const;
    glm::mat4 getProjectionMatrix() const;
    virtual void setPosition(const glm::vec3& pos);
    virtual void lookAt(const glm::vec3& front);

    void recalculateProjectionViewMatrix();

    virtual void cursorPositionEventHandler(const double& xpos, const double& ypos) override;

private:
    glm::mat4 view;
    glm::mat4 proj;

    glm::mat4 viewProj;

    glm::vec3 position;

    glm::vec3 cameraFront;

    glm::vec3 cameraUp;

    static std::shared_ptr<spdlog::logger> logger;

    // temporery
    bool firstMove = true;
    float pitch;
    float yaw;
    float lastX;
    float lastY;
};
