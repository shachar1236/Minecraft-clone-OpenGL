#include "Camera.h"
#include "Logic/ECS.h"
#include "Logic/Input.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

std::shared_ptr<spdlog::logger> Camera::logger = Log::createLogger("Camera");

Camera::Camera(const float& fov, const float& aspect_ratio)
    : proj(glm::perspective(glm::radians(fov), aspect_ratio, 0.1f, 100.0f))
    , view(glm::mat4(1.0f))
    , cameraFront(glm::vec3(0.0f, 0.0f, -1.0f))
    , cameraUp(glm::vec3(0.0f, 1.0f, 0.0f))
    , pitch(0.0f)
    , yaw(-90.0f)
    , lastX(0.0f)
    , lastY(0.0f)
    , Entity("Camera")
{
    position = glm::vec3(0.0f, 0.0f, 3.0f);
    recalculateProjectionViewMatrix();
}

void Camera::Setup() { Logic::ECS::CursorPositionEventSubscribers.push_back(shared_from_this()); }

void Camera::Update(const float& deltaTime)
{
    const float speed = 4.0f;
    if (Logic::Input::isKeyPressed(GLFW_KEY_W)) {
        position += deltaTime * speed * cameraFront;
        // logger->info("Moving forward");
    } else if (Logic::Input::isKeyPressed(GLFW_KEY_S)) {
        position -= deltaTime * speed * cameraFront;
    } else if (Logic::Input::isKeyPressed(GLFW_KEY_A)) {
        position -= glm::normalize(glm::cross(cameraFront, cameraUp)) * speed * deltaTime;
    } else if (Logic::Input::isKeyPressed(GLFW_KEY_D)) {
        position += glm::normalize(glm::cross(cameraFront, cameraUp)) * speed * deltaTime;
    }
    recalculateProjectionViewMatrix();
}

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
    view = glm::lookAt(position, position + cameraFront, cameraUp);
    viewProj = proj * view;
}

void Camera::cursorPositionEventHandler(const double& xpos, const double& ypos)
{
    if (firstMove) {
        lastX = xpos;
        lastY = ypos;
        firstMove = false;
    }

    float offsetX = xpos - lastX;
    float offsetY = lastY - ypos;

    lastX = xpos;
    lastY = ypos;

    const float sensitivity = 0.1f;
    offsetX *= sensitivity;
    offsetY *= sensitivity;

    yaw += offsetX;
    pitch += offsetY;

    if (pitch > 89.0f) {
        pitch = 89.0f;
    } else if (pitch < -89.0f) {
        pitch = -89.0f;
    }

    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

    cameraFront = glm::normalize(direction);
}
