#include <SFML/Window/Event.hpp>

#include "../include/MainMenu.h"

MainMenu::MainMenu(std::shared_ptr<Context>& context) : context_(context), m_isPlayButtonSelected(true),
                                                        m_isPlayButtonPressed(false), m_isExitButtonSelected(false),
                                                        m_isExitButtonPressed(false){

}

void MainMenu::Init() {
    context_->assets->AddFont(MAIN_MENU, "../assets/fonts/SquarePeg-Regular.ttf");
    gameTitle_.setFont(context_->assets->GetFont(MAIN_MENU));
    gameTitle_.setString("Snake Game");
    gameTitle_.setCharacterSize(120);
    gameTitle_.setOrigin(gameTitle_.getLocalBounds().width / 2,
                         gameTitle_.getLocalBounds().height / 2);
    gameTitle_.setPosition(context_->window->getSize().x / 2,
                           context_->window->getSize().y / 2 - 200.f);

    // Play Button
    playButton_.setFont(context_->assets->GetFont(MAIN_MENU));
    playButton_.setString("Play");
    playButton_.setOrigin(playButton_.getLocalBounds().width / 2,
                          playButton_.getLocalBounds().height / 2);
    playButton_.setPosition(context_->window->getSize().x / 2,
                            context_->window->getSize().y / 2 - 50.f);
    playButton_.setCharacterSize(80);

    // Exit Button
    exitButton_.setFont(context_->assets->GetFont(MAIN_MENU));
    exitButton_.setString("Exit");
    exitButton_.setOrigin(exitButton_.getLocalBounds().width / 2,
                          exitButton_.getLocalBounds().height / 2);
    exitButton_.setPosition(context_->window->getSize().x / 2,
                             context_->window->getSize().y / 2 + 50.f);
    exitButton_.setCharacterSize(80);
}

void MainMenu::ProcessInput() {
    sf::Event event;
    while (context_->window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            context_->window->close();
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
                case sf::Keyboard::Up:
                {
                    if (!m_isPlayButtonSelected)
                    {
                        m_isPlayButtonSelected = true;
                        m_isExitButtonSelected = false;
                    }
                    break;
                }
                case sf::Keyboard::Down:
                {
                    if (!m_isExitButtonSelected)
                    {
                        m_isPlayButtonSelected = false;
                        m_isExitButtonSelected = true;
                    }
                    break;
                }
                case sf::Keyboard::Return:
                {
                    m_isPlayButtonPressed = false;
                    m_isExitButtonPressed = false;

                    if (m_isPlayButtonSelected)
                    {
                        m_isPlayButtonPressed = true;
                    }
                    else
                    {
                        m_isExitButtonPressed = true;
                    }

                    break;
                }
                default:
                {
                    break;
                }
            }
        }
    }
}

void MainMenu::Update(sf::Time deltaTime) {
    if(m_isPlayButtonSelected)
    {
        playButton_.setFillColor(sf::Color::Black);
        exitButton_.setFillColor(sf::Color::White);
    }
    else
    {
        exitButton_.setFillColor(sf::Color::Black);
        playButton_.setFillColor(sf::Color::White);
    }

    if(m_isPlayButtonPressed)
    {
        //context_->states->Add(std::make_unique<GamePlay>(m_context), true);
    }
    else if(m_isExitButtonPressed)
    {
        context_->window->close();
    }
}

void MainMenu::Draw() {
    context_->window->clear(sf::Color::Blue);
    context_->window->draw(gameTitle_);
    context_->window->draw(playButton_);
    context_->window->draw(exitButton_);
    context_->window->display();
}

