#include "VertexBuffer.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

VertexBuffer::VertexBuffer(const float* buffer, const unsigned int& size, const unsigned int& usage)
{
    glGenBuffers(1, &id);
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, size, buffer, usage);
}

VertexBuffer::~VertexBuffer() { glDeleteBuffers(1, &id); }

void VertexBuffer::Bind() { glBindBuffer(GL_ARRAY_BUFFER, id); }

void VertexBuffer::UnBind() { glBindBuffer(GL_ARRAY_BUFFER, 0); }

std::shared_ptr<VertexBuffer> VertexBuffer::Create(
    const float* buffer, const unsigned int& size, const unsigned int& usage)
{
    return std::make_shared<VertexBuffer>(buffer, size, usage);
}