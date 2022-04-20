#include <SFML/Window/Event.hpp>

#include "../include/GamePlay.h"

GamePlay::GamePlay(std::shared_ptr<Context>& context)
: context_(context)
{

}

void GamePlay::Init() {
    context_->assets->AddTexture(GRASS, "../assets/textures/grass.png", true);
    context_->assets->AddTexture(WALL, "../assets/textures/wall.png", true);
    context_->assets->AddTexture(FOOD, "../assets/textures/food.png");
    context_->assets->AddTexture(SNAKE, "../assets/textures/snake.png");

    grass_.setTexture(context_->assets->GetTexture(GRASS));
    grass_.setTextureRect(context_->window->getViewport(context_->window->getDefaultView()));
}

void GamePlay::ProcessInput() {
    sf::Event event;
    while (context_->window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            context_->window->close();
        }
    }
}

void GamePlay::Update(sf::Time deltaTime) {

}

void GamePlay::Draw() {
    context_->window->clear();
    context_->window->draw(grass_);
    context_->window->display() ;
}

void GamePlay::Start() {
    State::Start();
}

void GamePlay::Pause() {
    State::Pause();
}

