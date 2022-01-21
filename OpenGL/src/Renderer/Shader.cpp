#include "Shader.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <iostream>

struct Shaders {
    std::string vertexShader;
    std::string fragmentShader;
};

static Shaders importShader(const std::string& filename)
{
    std::ifstream myFile(filename.c_str());
    std::string line;
    Shaders shaders = { "", "" };
    int type = 0;
    while (getline(myFile, line)) {
        if (line.find("#shader") != std::string::npos) {
            if (line.find("vertex") != std::string::npos) {
                type = 1;
            } else if (line.find("fragment") != std::string::npos) {
                type = 2;
            }
        } else {
            if (type == 1) {
                shaders.vertexShader += line + '\n';
            } else if (type == 2) {
                shaders.fragmentShader += line + '\n';
            }
        }
    }
    return shaders;
}

static unsigned int compileShader(unsigned int type, const std::string& source)
{
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result = 0;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
        int length = 0;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);

        std::cout << "Faild to compile shader " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << std::endl;
        std::cout << message << std::endl;

        glDeleteShader(id);
        return 0;
    }

    return id;
}

static unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

Shader::Shader(const std::string& vertexShader, const std::string& fragmentShader)
{
    program_id = createShader(vertexShader, fragmentShader);
}

Shader::~Shader() { glDeleteProgram(program_id); }

void Shader::Bind() { glUseProgram(program_id); }

void Shader::UnBind() { glUseProgram(0); }

void Shader::SetUniformFloat(const std::string& name, const float& value)
{
    auto location = uniforms_locations.find(name);
    int uniform_location = 0;
    if (location == uniforms_locations.end()) {
        uniform_location = glGetUniformLocation(program_id, name.c_str());
        uniforms_locations[name] = uniform_location;
    } else {
        uniform_location = location->second;
    }
    glUniform1f(uniform_location, value);
}

void Shader::SetUniformInt(const std::string& name, const int& value)
{
    auto location = uniforms_locations.find(name);
    int uniform_location = 0;
    if (location == uniforms_locations.end()) {
        uniform_location = glGetUniformLocation(program_id, name.c_str());
        uniforms_locations[name] = uniform_location;
    } else {
        uniform_location = location->second;
    }
    glUniform1i(uniform_location, value);
}

void Shader::SetUniformVec2f(const std::string& name, const glm::vec2& value)
{
    auto location = uniforms_locations.find(name);
    int uniform_location = 0;
    if (location == uniforms_locations.end()) {
        uniform_location = glGetUniformLocation(program_id, name.c_str());
        uniforms_locations[name] = uniform_location;
    } else {
        uniform_location = location->second;
    }
    glUniform2f(uniform_location, value.x, value.y);
}

void Shader::SetUniformVec3f(const std::string& name, const glm::vec3& value)
{
    auto location = uniforms_locations.find(name);
    int uniform_location = 0;
    if (location == uniforms_locations.end()) {
        uniform_location = glGetUniformLocation(program_id, name.c_str());
        uniforms_locations[name] = uniform_location;
    } else {
        uniform_location = location->second;
    }
    glUniform3f(uniform_location, value.x, value.y, value.z);
}

void Shader::SetUniformVec4f(const std::string& name, const glm::vec4& value)
{
    auto location = uniforms_locations.find(name);
    int uniform_location = 0;
    if (location == uniforms_locations.end()) {
        uniform_location = glGetUniformLocation(program_id, name.c_str());
        uniforms_locations[name] = uniform_location;
    } else {
        uniform_location = location->second;
    }
    glUniform4f(uniform_location, value.x, value.y, value.z, value.w);
}