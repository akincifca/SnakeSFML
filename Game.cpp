#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics.hpp>

#include "Game.h"

Game::Game() : context_(std::make_shared<Context>()) {
    context_->window->create(sf::VideoMode(640, 352), "Snake Game", sf::Style::Close);
    // context_->states->Add(std::make_unique<MainMenu>(m_context));
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

            sf::Event event;
            while(context_->window->pollEvent(event)) {
                if(event.type == sf::Event::Closed) {
                    context_->window->close();
                }
            }

            context_->window->clear();
            context_->window->draw(shape);
            context_->window->display();
        }
    }
}
