#ifndef SNAKEGAME_MAINMENU_H
#define SNAKEGAME_MAINMENU_H

#include <memory>

#include <SFML/Graphics/Text.hpp>

#include "Game.h"
#include "State.h"

class MainMenu : public Engine::State {
public:
    MainMenu(std::shared_ptr<Context>& context);

    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;

private:
    std::shared_ptr<Context> context_;
    sf::Text gameTitle_;
};

#endif //SNAKEGAME_MAINMENU_H