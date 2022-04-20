#include <SFML/Window/Event.hpp>

#include "../include/GamePlay.h"

GamePlay::GamePlay(std::shared_ptr<Context>& context)
:
context_(context),
snakeDirection_({32.f, 0.f}),
elapsedTime_(sf::Time::Zero)
{

}

void GamePlay::Init() {
    context_->assets->AddTexture(GRASS, "../assets/textures/grass.png", true);
    context_->assets->AddTexture(WALL, "../assets/textures/wall.png", true);
    context_->assets->AddTexture(FOOD, "../assets/textures/food.png");
    context_->assets->AddTexture(SNAKE, "../assets/textures/snake.png");

    grass_.setTexture(context_->assets->GetTexture(GRASS));
    grass_.setTextureRect(context_->window->getViewport(context_->window->getDefaultView()));

    for(auto& wall : walls_) {
        wall.setTexture(context_->assets->GetTexture(WALL));
    }

    walls_[0].setTextureRect({0, 0, static_cast<int>(context_->window->getSize().x), 32});
    walls_[1].setTextureRect({0, 0 , static_cast<int>(context_->window->getSize().x), 32});
    walls_[1].setPosition(0, static_cast<float>(context_->window->getSize().y) - 32);
    walls_[2].setTextureRect({0, 0 , 32, static_cast<int>(context_->window->getSize().y)});
    walls_[3].setTextureRect({0, 0 , 32, static_cast<int>(context_->window->getSize().y)});
    walls_[3].setPosition(static_cast<float>(context_->window->getSize().x) - 32, 0);

    food_.setTexture(context_->assets->GetTexture(FOOD));
    food_.setPosition(static_cast<float>(context_->window->getSize().x) / 2,
                       static_cast<float>(context_->window->getSize().y) / 2);

    snake_.Init(context_->assets->GetTexture(SNAKE));
}

void GamePlay::ProcessInput() {
    sf::Event event;
    while (context_->window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            context_->window->close();
        } else if(event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::Up:
                    snakeDirection_ = {0.f, -32.f};
                    break;
                case sf::Keyboard::Down:
                    snakeDirection_ = {0.f, 32.f};
                    break;
                case sf::Keyboard::Left:
                    snakeDirection_ = {-32.f, 0.f};
                    break;
                case sf::Keyboard::Right:
                    snakeDirection_ = {32.f, 0.f};
                    break;
                default:
                    break;
            }
        }
    }
}

void GamePlay::Update(sf::Time deltaTime) {
    elapsedTime_ += deltaTime;

    if(elapsedTime_.asSeconds() > 0.1) {
        snake_.Move(snakeDirection_);
        elapsedTime_ = sf::Time::Zero;
    }
}

void GamePlay::Draw() {
    context_->window->clear();
    context_->window->draw(grass_);
    context_->window->draw(food_);
    context_->window->draw(snake_);
    for(auto& wall : walls_) {
        context_->window->draw(wall);
    }
    context_->window->display() ;
}

void GamePlay::Start() {
    State::Start();
}

void GamePlay::Pause() {
    State::Pause();
}

