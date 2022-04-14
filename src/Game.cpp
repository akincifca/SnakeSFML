#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics.hpp>

#include "../include/Game.h"
#include "../include/MainMenu.h"

Game::Game() : context_(std::make_shared<Context>()) {
    context_->window->create(sf::VideoMode(1920, 1080), "Snake Game", sf::Style::Close);
    context_->states->Add(std::make_unique<MainMenu>(context_));
}

void Game::Run() {
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Clock clock;
    sf::Time timeSinceLastFrame = sf::Time::Zero;

    while (context_->window->isOpen())
    {
        timeSinceLastFrame += clock.restart();

        while (timeSinceLastFrame > timePerFrame_)
        {
            timeSinceLastFrame -= timePerFrame_;

            context_->states->GetCurrent()->ProcessInput();
            context_->states->GetCurrent()->Update(timePerFrame_);
            context_->states->GetCurrent()->Draw();
        }
    }
}
