#pragma once
#include <glm/glm.hpp>
#include <map>
#include <string>

class Shader {
public:
    Shader(const std::string& shaderPath);
    ~Shader();

    void Bind();
    void UnBind();

    void SetUniformFloat(const std::string& name, const float& value);
    void SetUniformInt(const std::string& name, const int& value);

    void SetUniformVec2f(const std::string& name, const glm::vec2& value);
    void SetUniformVec3f(const std::string& name, const glm::vec3& value);
    void SetUniformVec4f(const std::string& name, const glm::vec4& value);

private:
    unsigned int program_id;
    std::map<std::string, int> uniforms_locations;
};
