#include "Mesh.h"

Mesh::Mesh(std::shared_ptr<Shader> shader_)
    : shader(shader_)
{
}

void Mesh::set_uniforms()
{
    for (auto unifrom : unifroms_float) {
        shader->SetUniformFloat(unifrom.first, unifrom.second);
    }

    for (auto unifrom : unifroms_int) {
        shader->SetUniformInt(unifrom.first, unifrom.second);
    }

    for (auto unifrom : unifroms_vec2) {
        shader->SetUniformVec2f(unifrom.first, unifrom.second);
    }

    for (auto unifrom : unifroms_vec3) {
        shader->SetUniformVec3f(unifrom.first, unifrom.second);
    }

    for (auto unifrom : unifroms_vec4) {
        shader->SetUniformVec4f(unifrom.first, unifrom.second);
    }
}

void Mesh::set_uniforms_and_shader()
{
    shader->Bind();
    set_uniforms();
}
