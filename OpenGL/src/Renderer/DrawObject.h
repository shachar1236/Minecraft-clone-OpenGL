#pragma once
#include "Mesh.h"
#include "Transform.h"
#include "VertexArray.h"
#include <memory>

struct DrawObject {
public:
    std::shared_ptr<VertexArray> vertexArray;
    std::shared_ptr<Mesh> mesh;
    std::shared_ptr<Mesh> transform;
};
