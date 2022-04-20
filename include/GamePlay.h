#ifndef SNAKEGAME_GAMEPLAY_H
#define SNAKEGAME_GAMEPLAY_H

#include <array>
#include <memory>

#include <SFML/Graphics/Sprite.hpp>

#include "Game.h"
#include "State.h"
#include "Snake.h"

class GamePlay : public Engine::State {
public:
    GamePlay(std::shared_ptr<Context>& context);

    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;

    void Start() override;
    void Pause() override;
private:
    std::shared_ptr<Context> context_;
    sf::Sprite grass_;
    sf::Sprite food_;
    std::array<sf::Sprite, 4> walls_;
    Snake snake_;
    sf::Vector2f snakeDirection_;
    sf::Time elapsedTime_;
};

#endif //SNAKEGAME_GAMEPLAY_H