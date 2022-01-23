#pragma once
#include <glm/glm.hpp>
#include <memory>

struct Transform {
public:
    Transform(const glm::mat4& t)
        : transform(t)
    {
    }
    glm::mat4 transform;

    void setPosition(glm::vec3 position);
    void setRotation(glm::vec3 rotation);
};
