#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <memory>

struct Transform {
public:
    glm::mat4 transform;
    Transform(const glm::mat4& t)
        : transform(t)
        , position(glm::vec3(0.0f))
        , rotation(glm::vec3(1.0f))
        , rotationAngle(0.0f)
        , scale(glm::vec3(1.0f))
    {
        calculateTransform();
    }

    void setPosition(const glm::vec3& position_)
    {
        position = position_;
        calculateTransform();
    }

    void setRotation(const float& angle, const glm::vec3& rotation_)
    {
        rotation = rotation_;
        rotationAngle = angle;
        calculateTransform();
    }

    void setScale(const glm::vec3& s)
    {
        scale = s;
        calculateTransform();
    }

    void calculateTransform()
    {
        transform = glm::mat4(1.0);
        transform = glm::translate(transform, position);
        transform = glm::rotate(transform, glm::radians(rotationAngle), rotation);
        transform = glm::scale(transform, scale);
    }

private:
    glm::vec3 position;
    glm::vec3 rotation;
    float rotationAngle;
    glm::vec3 scale;
};
