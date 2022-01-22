#pragma once
#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include <memory>
#include <vector>

class VertexArray {
public:
    VertexArray();
    ~VertexArray();

    void Bind();
    void UnBind();

    void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& buffer);

    void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& buffer);

private:
    unsigned int id;
    std::shared_ptr<IndexBuffer> indexBuffer;
    std::vector<std::shared_ptr<VertexBuffer>> vertexBuffers;
};
