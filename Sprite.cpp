//
// Created by gab on 7/12/24.
//

#include <stdexcept>
#include "Sprite.h"

Sprite::Sprite(const std::string &pathFile, float scale) {
    if (!texture.loadFromFile(pathFile)) {
        throw std::runtime_error("Failed to load texture from file: " + pathFile);
    }
    texture.setSmooth(true);
    setTexture(texture);
    setScale(scale, scale);
}
