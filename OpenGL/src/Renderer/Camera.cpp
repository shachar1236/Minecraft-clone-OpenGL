#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(const float& left, const float& right, const float& bottom, const float& top)
    : proj(glm::ortho(left, right, bottom, top, -1.0f, 1.0f))
    , view(glm::mat4(1.0f))
    , Entity("Camera")
{
}

void Camera::Setup() { }

void Camera::Update(const float& deltaTime) { }

glm::mat4 Camera::getViewProjectionMatrix() const { return viewProj; }

void Camera::setPosition(const glm::vec3& pos)
{
    position = pos;
    recalculateProjectionViewMatrix();
}

void Camera::recalculateProjectionViewMatrix() { }
