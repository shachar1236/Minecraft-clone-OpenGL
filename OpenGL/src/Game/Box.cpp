#include "Box.h"
#include "Core/Core.h"
#include "Logic/ECS.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

auto logger = Log::createLogger("Box");

struct Vertex {
    float pos[3];
    float color[3];

    Vertex() { }

    Vertex(float x, float y, float z)
    {
        pos[0] = x;
        pos[1] = y;
        pos[2] = z;

        pos[0] = 1.0f;
        pos[1] = 1.0f;
        pos[2] = 1.0f;
    }
};

void Box::Setup()
{
    float positions[40] = {
        // first 3 - positions, next 2 - texture coordinates
        0.5f, 0.5f, 0.5f, 1.0f, 1.0f, //
        -0.5f, 0.5f, -0.5f, 1.0f, 1.0f, //
        -0.5f, 0.5f, 0.5f, 0.0f, 1.0f, //
        0.5f, -0.5f, -0.5f, 0.0f, 0.0f, //
        -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, //
        0.5f, 0.5f, -0.5f, 0.0f, 1.0f, //
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f, //
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f //

    };

    unsigned int indices[] = { 0, 1, 2, //
        1, 3, 4, //
        5, 6, 3, //
        7, 3, 6, //
        2, 4, 7, //
        0, 7, 6, //
        0, 5, 1, //
        1, 5, 3, //
        5, 0, 6, //
        7, 4, 3, //
        2, 1, 4, //
        0, 2, 7 };

    va = VertexArray::Create();
    va->Bind();

    buffer = VertexBuffer::Create((float*)positions, sizeof(positions), GL_STATIC_DRAW);
    buffer->layout.addElement(BufferElement(3, sizeof(float) * 3, GL_FLOAT, GL_FALSE));
    buffer->layout.addElement(BufferElement(2, sizeof(float) * 2, GL_FLOAT, GL_FALSE));

    va->AddVertexBuffer(buffer);

    indexBuffer = IndexBuffer::Create(indices, sizeof(indices), GL_STATIC_DRAW);
    va->SetIndexBuffer(indexBuffer);

    texture = Texture::Create("res/textures/bedrock.png");
    va->SetTexture(texture);

    mesh = std::make_shared<Mesh>(Shader::Create("res/shaders/Basic.shader"));
    mesh->unifroms_int["ourTexture"] = 0;

    transform = glm::mat4(1.0f);
    transform.setPosition(glm::vec3(0.0f, 0.0f, 0.0f));
    transform.setScale(glm::vec3(1.0f, 1.0f, 1.0f));
}

void Box::Update(const float& deltaTime)
{
    r += color_jump * deltaTime;
    if (r > 1.0f || r < 0.0f) {
        color_jump *= -1;
    }

    rotation += deltaTime * 20;
    // transform->setRotation(rotation, glm::vec3(1.0f));
}

DrawObject Box::getDrawObject() { return { va, mesh, &transform }; }

void Box::cursorPositionEventHandler(const double& xpos, const double& ypos)
{
    // logger->info("Cursor position has changed");
}