
#include "../include/AssetMng.h"

void Engine::AssetMng::AddTexture(int id, const std::string& path, bool repeated) {
    auto texture = std::make_unique<sf::Texture>();

    if(texture->loadFromFile(path)) {
        texture->setRepeated(repeated);
        textures_[id] = std::move(texture);
    }
}

void Engine::AssetMng::AddFont(int id, const std::string &path) {
    auto font = std::make_unique<sf::Font>();

    if(font->loadFromFile(path)) {
        fonts_[id] = std::move(font);
    }
}

const sf::Texture& Engine::AssetMng::GetTexture(int id) const {
    return *textures_.at(id).get();
}

const sf::Font& Engine::AssetMng::GetFont(int id) const {
    return *fonts_.at(id).get();
}

