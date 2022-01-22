#include "VertexArray.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

VertexArray::VertexArray() { glCreateVertexArrays(1, &id); }

VertexArray::~VertexArray() { glDeleteVertexArrays(1, &id); }

void VertexArray::Bind() { glBindVertexArray(id); }

void VertexArray::UnBind() { glBindVertexArray(0); }

void VertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& buffer)
{
    glBindVertexArray(id);
    buffer->Bind();

    auto& elements = buffer->layout.getLayout();
    const unsigned int stride = buffer->layout.getStride();

    for (int i = 0; i < elements.size(); i++) {
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, // index
            elements[i].count, // count
            elements[i].type, // type
            elements[i].normalized, // normalized
            stride, // stride
            (const void*)elements[i].offset);
    }
    vertexBuffers.push_back(buffer);
}

void VertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& buffer)
{
    glBindVertexArray(id);
    buffer->Bind();
    indexBuffer = buffer;
}
