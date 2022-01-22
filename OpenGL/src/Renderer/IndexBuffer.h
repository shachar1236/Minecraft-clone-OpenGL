#pragma once
#include <memory>
class IndexBuffer {
public:
    IndexBuffer();

    IndexBuffer(const unsigned int* buffer, const unsigned int& size, const unsigned int& usage);
    ~IndexBuffer();

    static std::shared_ptr<IndexBuffer> Create(
        const unsigned int* buffer, const unsigned int& size, const unsigned int& usage);

    void Bind();
    void UnBind();

private:
    unsigned int id;
};
