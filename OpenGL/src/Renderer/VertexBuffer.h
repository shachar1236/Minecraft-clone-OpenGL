#pragma once
#include <vector>
class VertexBuffer {
public:
    VertexBuffer(const float* buffer, const unsigned int& size, const unsigned int& usage);
    ~VertexBuffer();

    void Bind();
    void UnBind();

    BufferLayout layout;

private:
    unsigned int id;
};

struct BufferElement {
    unsigned int count; // count of data
    unsigned int size; // size of data in bytes
    unsigned int type; // OpenGL type
    unsigned int normalized; // OpenGL bool
    unsigned int offset;

    BufferElement(unsigned int count_, unsigned int size_, unsigned int type_, unsigned int normalized_)
        : count(count_)
        , size(size_)
        , type(type_)
        , normalized(normalized_)
    {
    }
};

struct BufferLayout {
    BufferLayout();

    void addElement(const BufferElement& element)
    {
        // element.offset = stride;
        elements.push_back(element);
        elements[elements.size() - 1].offset = stride;
        stride += element.size;
    }

    const std::vector<BufferElement>& getLayout() const { return elements; }

    unsigned int getStride() const { return stride; }

private:
    std::vector<BufferElement> elements;
    unsigned int stride;
};