#include "Box.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

void Box::Setup()
{
    float positions[] = {
        -0.5f, -0.5f, //
        -0.5f, 0.5f, //
        0.5f, 0.5f, //
        0.5f, -0.5f, //
    };

    unsigned int indecis[] = {
        0, 1, 2, // first triange
        2, 3, 0 // second triange
    };

    va = VertexArray::Create();
    va->Bind();

    buffer = VertexBuffer::Create(positions, 8 * sizeof(float), GL_STATIC_DRAW);
    buffer->layout.addElement(BufferElement(2, sizeof(float) * 2, GL_FLOAT, GL_FALSE));

    va->AddVertexBuffer(buffer);

    indexBuffer = IndexBuffer::Create(indecis, 6 * sizeof(float), GL_STATIC_DRAW);
    va->SetIndexBuffer(indexBuffer);

    mesh = std::make_shared<Mesh>(Shader::Create("res/shaders/Basic.shader"));

    transform = std::make_shared<Transform>(glm::mat4(1.0f));
}

void Box::Update(const float& deltaTime)
{
    r += color_jump * deltaTime;
    if (r > 1.0f || r < 0.0f) {
        color_jump *= -1;
    }
    mesh->unifroms_vec4["u_Color"] = glm::vec4(r, 0.8f, 0.4f, 1.0f);
}

DrawObject Box::getDrawObject() { return { va, mesh, &(*transform) }; }
