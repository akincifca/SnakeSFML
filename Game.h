#ifndef SNAKEGAME_GAME_H
#define SNAKEGAME_GAME_H

#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>

#include "AssetMng.h"
#include "StateMng.h"

enum AssetId {
    MAIN_MENU = 0,
};

struct Context {
    std::unique_ptr<Engine::AssetMng> assets;
    std::unique_ptr<Engine::StateMng> states;
    std::unique_ptr<sf::RenderWindow> window;

    Context() {
        assets = std::make_unique<Engine::AssetMng>();
        states = std::make_unique<Engine::StateMng>();
        window = std::make_unique<sf::RenderWindow>();
    }
};

class Game {
public:
    Game();
    void Run();
private:
    std::shared_ptr<Context> context_;
    const sf::Time timePerFrame_ {sf::seconds(1.f / 60.f)};
};

#endif //SNAKEGAME_GAME_H