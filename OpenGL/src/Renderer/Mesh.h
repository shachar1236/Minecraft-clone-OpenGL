#pragma once
#include "Shader.h"
#include <glm/glm.hpp>
#include <memory>
#include <string>
#include <unordered_map>

struct Mesh {
public:
    std::unordered_map<std::string, float> unifroms_float;
    std::unordered_map<std::string, int> unifroms_int;
    std::unordered_map<std::string, glm::vec2> unifroms_vec2;
    std::unordered_map<std::string, glm::vec3> unifroms_vec3;
    std::unordered_map<std::string, glm::vec4> unifroms_vec4;

    std::shared_ptr<Shader> shader;

    Mesh(std::shared_ptr<Shader> shader_);

    void set_uniforms();
    void set_uniforms_and_shader();
};
