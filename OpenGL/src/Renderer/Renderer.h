#pragma once
#include <memory>
class Renderer {
public:
    static std::unique_ptr<Renderer> renderer;
};
