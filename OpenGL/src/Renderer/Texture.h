#pragma once
#include "Core/Core.h"
#include "Libraris/stb_image/stb_image.h"
#include <string>

class Texture {
public:
    Texture() { }

    Texture(const std::string& path);
    ~Texture();

    static std::shared_ptr<Texture> Create(const std::string& path);

    void Bind(const unsigned int& slot = 0) const;
    void UnBind() const;

    int getWidth() const;
    int getHeight() const;

private:
    unsigned int id;

    int width;
    int height;
};
