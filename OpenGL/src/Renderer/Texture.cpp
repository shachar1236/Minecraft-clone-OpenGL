#include "Texture.h"
#include "Core/Core.h"

static auto logger = Log::createLogger("Texture");

Texture::Texture(const std::string& path)
{
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);

    glTexParameteri(
        GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace
    // it with your own image path.
    int channels = 0;
    unsigned char* data = stbi_load(path.c_str(), &width, &height, &channels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        logger->error("Couldn't load texture image!");
    }
    stbi_image_free(data);
}

Texture::~Texture() { glDeleteTextures(1, &id); }

std::shared_ptr<Texture> Texture::Create(const std::string& path)
{
    std::shared_ptr<Texture> t;
    t.reset(new Texture(path));
    return t;
}

void Texture::Bind(const unsigned int& slot) const
{
    glActiveTexture(slot);
    glBindTexture(GL_TEXTURE_2D, id);
}

void Texture::UnBind() const { glBindTexture(GL_TEXTURE_2D, 0); }
