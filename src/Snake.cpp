
#include "../include/Snake.h"

Snake::Snake() : body_(std::list<sf::Sprite>(4)) {
     head_ = --body_.end();
     tail_ = body_.begin();
}

void Snake::Init(const sf::Texture& texture) {
    float x = 32.f;
    for(auto& part : body_) {
        part.setTexture(texture);
        part.setPosition(x, 32.f);
        x += 32.f;
    }
}

void Snake::Move(const sf::Vector2f& direction) {
    tail_->setPosition(head_->getPosition() + direction);
    head_ = tail_;
    ++tail_;
    if(tail_ == body_.end()) {
        tail_ = body_.begin();
    }
}

bool Snake::IsOn(const sf::Sprite& other) const {
    return false;
}

void Snake::Grow(const sf::Vector2f& direction) {

}

void Snake::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for(auto& part : body_) {
        target.draw(part);
    }
}

