#pragma once
#include <memory>
class IndexBuffer {
public:
    IndexBuffer(const float* buffer, const unsigned int& size, const unsigned int& usage);
    ~IndexBuffer();

    std::shared_ptr<IndexBuffer> Create(const float* buffer, const unsigned int& size, const unsigned int& usage);

    void Bind();
    void UnBind();

private:
    unsigned int id;
};
