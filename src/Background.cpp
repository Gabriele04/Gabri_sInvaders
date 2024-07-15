#include <stdexcept>
#include "../include/Background.h"

Background::Background(const std::string &pathFile, float scale) {
    if (!texture.loadFromFile(pathFile)) {
        throw std::runtime_error("Failed to load texture from file: " + pathFile);
    }
    texture.setSmooth(true);
    setTexture(texture);
    setScale(scale, scale);
}