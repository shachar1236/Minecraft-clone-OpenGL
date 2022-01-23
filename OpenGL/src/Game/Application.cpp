#include "Box.h"
#include "Logic/ECS.h"
#include "Logic/Entity.h"
#include "Renderer/IndexBuffer.h"
#include "Renderer/Shader.h"
#include "Renderer/VertexArray.h"
#include "Renderer/VertexBuffer.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <glm/glm.hpp>
#include <iostream>
#include <memory>
#include <string>

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    // setting v sync on
    glfwSwapInterval(1);

    if (glewInit() != GLEW_OK) {
        return -1;
    }

    std::shared_ptr<Box> box = std::make_shared<Box>("box1");
    Logic::ECS::AddEntity(box);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        Logic::ECS::Update(1);

        DrawObject boxDraw = box->getDrawObject();
        boxDraw.mesh->set_uniforms_and_shader();
        boxDraw.vertexArray->Bind();

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    // deleting the shader
    // glDeleteProgram(shader);

    glfwTerminate();
    return 0;
}
