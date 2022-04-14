#include <SFML/Window/Event.hpp>

#include "../include/MainMenu.h"

MainMenu::MainMenu(std::shared_ptr<Context>& context) : context_(context){

}

void MainMenu::Init() {
    context_->assets->AddFont(MAIN_MENU, "../assets/fonts/SquarePeg-Regular.ttf");
    gameTitle_.setFont(context_->assets->GetFont(MAIN_MENU));
    gameTitle_.setString("Snake Game");
    gameTitle_.setCharacterSize(120);
    gameTitle_.setOrigin(gameTitle_.getLocalBounds().width / 2,
                         gameTitle_.getLocalBounds().height / 2);
    gameTitle_.setPosition(context_->window->getSize().x / 2,
                           context_->window->getSize().y / 2);
}

void MainMenu::ProcessInput() {
    sf::Event event;
    while(context_->window->pollEvent(event)) {
        if(event.type == sf::Event::Closed) {
            context_->window->close();
        }
    }
}

void MainMenu::Update(sf::Time deltaTime) {

}

void MainMenu::Draw() {
    context_->window->clear();
    context_->window->draw(gameTitle_);
    context_->window->display();
}

