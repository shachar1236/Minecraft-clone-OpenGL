#pragma once
#include <glm/glm.hpp>
#include <memory>

struct Transfrom {
public:
    glm::mat4 transform;

    void setPosition(glm::vec3 position);
    void setRotation(glm::vec3 rotation);
};
