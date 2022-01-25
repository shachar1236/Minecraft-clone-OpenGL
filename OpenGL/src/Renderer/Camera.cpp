#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Camera::Camera(const float& fov, const float& aspect_ratio)
    : proj(glm::perspective(glm::radians(fov), aspect_ratio, 0.1f, 100.0f))
    , view(glm::mat4(1.0f))
    , cameraFront(glm::vec3(0.0f, 0.0f, -1.0f))
    , Entity("Camera")
{
    position = glm::vec3(0.0f, 0.0f, 3.0f);
    recalculateProjectionViewMatrix();
}

void Camera::Setup() { }

void Camera::Update(const float& deltaTime) { }

glm::mat4 Camera::getViewProjectionMatrix() const { return viewProj; }

glm::mat4 Camera::getProjectionMatrix() const { return proj; }

void Camera::setPosition(const glm::vec3& pos)
{
    position = pos;
    recalculateProjectionViewMatrix();
}

void Camera::lookAt(const glm::vec3& front)
{
    cameraFront = front;
    recalculateProjectionViewMatrix();
}

void Camera::recalculateProjectionViewMatrix()
{
    // glm::mat4 transform = glm::translate(glm::mat4(1.0f), position)
    //     * glm::rotate(glm::mat4(1.0f), glm::radians(rotation), glm::vec3(0, 0, 1));
    // glm::mat4 transform = glm::translate(glm::mat4(1.0f), position);

    // view = glm::inverse(transform);
    view = glm::lookAt(position, position + cameraFront, glm::vec3(0.0f, 1.0f, 0.0f));
    viewProj = proj * view;
}
