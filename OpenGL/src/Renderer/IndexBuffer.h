#pragma once
class IndexBuffer {
public:
    IndexBuffer(const float* buffer, const unsigned int& size, const unsigned int& usage);
    ~IndexBuffer();

    void Bind();
    void UnBind();

private:
    unsigned int id;
};
