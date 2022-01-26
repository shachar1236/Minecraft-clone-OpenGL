#include "Box.h"
#include "Core/Core.h"
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
    // float positions[] = {
    //     -0.5f, 0.0f, -0.5f, //
    //     -0.5f, 0.0f, 0.5f, // top face
    //     0.5f, 0.0f, 0.5f, //
    //     0.5f, 0.0f, -0.5f, //

    //     -0.5f, 1.0f, -0.5f, //
    //     -0.5f, 1.0f, 0.5f, // bottom face
    //     0.5f, 1.0f, 0.5f, //
    //     0.5f, 1.0f, -0.5f, //

    //     -0.5f, -0.5f, 0.0f, //
    //     -0.5f, 0.5f, 0.0f, // front face
    //     0.5f, 0.5f, 0.0f, //
    //     0.5f, -0.5f, 0.0f, //

    //     -0.5f, -0.5f, 1.0f, //
    //     -0.5f, 0.5f, 1.0f, // hide face
    //     0.5f, 0.5f, 1.0f, //
    //     0.5f, -0.5f, 1.0f, //

    //     0.0f, -0.5f, -0.5f, //
    //     0.0f, -0.5f, 0.5f, //
    //     0.0f, 0.5f, 0.5f, //
    //     0.0f, 0.5f, -0.5f, //

    //     1.0f, -0.5f, -0.5f, //
    //     1.0f, -0.5f, 0.5f, //
    //     1.0f, 0.5f, 0.5f, //
    //     1.0f, 0.5f, -0.5f, //
    // };

    // unsigned int indecis[] = {
    //     0, 1, 2, // first triange
    //     2, 3, 0, // second triange

    //     4, 5, 6, // first triange
    //     6, 7, 4, // second triange

    //     8, 9, 10, // first triange
    //     10, 11, 8, // second triange

    //     12, 13, 14, // first triange
    //     14, 15, 12 // second triange
    // };

    // Vertex positions[8];

    // positions[0] = Vertex(0.5f, 0.5f, 0.5f);
    // positions[1] = Vertex(-0.5f, 0.5f, -0.5f);
    // positions[2] = Vertex(-0.5f, 0.5f, 0.5f);
    // positions[3] = Vertex(0.5f, -0.5f, -0.5f);
    // positions[4] = Vertex(-0.5f, -0.5f, -0.5f);
    // positions[5] = Vertex(0.5f, 0.5f, -0.5f);
    // positions[6] = Vertex(0.5f, -0.5f, 0.5f);
    // positions[7] = Vertex(-0.5f, -0.5f, 0.5f);

    float positions[24] = {
        //
        0.5f, 0.5f, 0.5f, //
        -0.5f, 0.5f, -0.5f, //
        -0.5f, 0.5f, 0.5f, //
        0.5f, -0.5f, -0.5f, //
        -0.5f, -0.5f, -0.5f, //
        0.5f, 0.5f, -0.5f, //
        0.5f, -0.5f, 0.5f, //
        -0.5f, -0.5f, 0.5f //

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

    // float positions[] = {
    //     //
    //     -0.5f, -0.5f, //
    //     0.5f, -0.5f, //
    //     0.5f, 0.5f, //
    //     -0.5f, 0.5f, //
    // };

    // unsigned int indices[6] = {
    //     //
    //     0, 1, 2, //
    //     2, 3, 0 //
    // };

    va = VertexArray::Create();
    va->Bind();

    buffer = VertexBuffer::Create((float*)positions, sizeof(positions), GL_STATIC_DRAW);
    buffer->layout.addElement(BufferElement(3, sizeof(float) * 3, GL_FLOAT, GL_FALSE));

    va->AddVertexBuffer(buffer);

    indexBuffer = IndexBuffer::Create(indices, sizeof(indices), GL_STATIC_DRAW);
    va->SetIndexBuffer(indexBuffer);

    mesh = std::make_shared<Mesh>(Shader::Create("res/shaders/Basic.shader"));

    transform = std::make_shared<Transform>(glm::mat4(1.0f));
    transform->setPosition(glm::vec3(0.0f, 0.0f, 0.0f));
}

void Box::Update(const float& deltaTime)
{
    r += color_jump * deltaTime;
    if (r > 1.0f || r < 0.0f) {
        color_jump *= -1;
    }

    rotation += deltaTime * 20;
    transform->setRotation(rotation, glm::vec3(1.0f));
}

DrawObject Box::getDrawObject() { return { va, mesh, &(*transform) }; }

void Box::cursorPositionEventHandler(const double& xpos, const double& ypos)
{
    // logger->info("Cursor position has changed");
}