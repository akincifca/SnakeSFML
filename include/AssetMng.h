#ifndef SNAKEGAME_ASSETMNG_H
#define SNAKEGAME_ASSETMNG_H

#include <map>
#include <memory>
#include <string>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

namespace Engine{
class AssetMng{
public:
    void AddTexture(int id, const std::string& path, bool repeated = false);
    void AddFont(int id, const std::string& path);

    const sf::Texture& GetTexture(int id) const;
    const sf::Font& GetFont(int id) const;
private:
    std::map<int, std::unique_ptr<sf::Texture>> textures_;
    std::map<int, std::unique_ptr<sf::Font>> fonts_;
};
}

#endif //SNAKEGAME_ASSETMNG_H