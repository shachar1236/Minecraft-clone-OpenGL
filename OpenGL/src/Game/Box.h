#pragma once
#include "Logic/Entity.h"
#include "Renderer/DrawObject.h"

class Box : public Logic::Entity {
public:
    // graphics stuff
    std::shared_ptr<VertexArray> va;
    std::shared_ptr<Mesh> mesh;
    std::shared_ptr<VertexBuffer> buffer;
    std::shared_ptr<IndexBuffer> indexBuffer;
    std::shared_ptr<Transform> transform;

    float r = 0;
    float color_jump = 0.01f;

    Box(const std::string& name)
        : Logic::Entity(name) {
            // Setup();
        };
    virtual void Setup() override;
    virtual void Update(const float& deltaTime) override;

    virtual DrawObject getDrawObject() override;
};
