#include "IndexBuffer.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

IndexBuffer::IndexBuffer(const float* buffer, const unsigned int& size, const unsigned int& usage)
{
    glGenBuffers(1, &id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, buffer, usage);
}

IndexBuffer::~IndexBuffer() { glDeleteBuffers(1, &id); }

void IndexBuffer::Bind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id); }

void IndexBuffer::UnBind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }