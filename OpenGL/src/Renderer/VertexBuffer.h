#pragma once
class VertexBuffer {
public:
    VertexBuffer(const float* buffer, const unsigned int& size, const unsigned int& usage);
    ~VertexBuffer();

    void Bind();
    void UnBind();

private:
    unsigned int id;
};
