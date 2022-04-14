#ifndef SNAKEGAME_STATE_H
#define SNAKEGAME_STATE_H

#include <SFML/System/Time.hpp>

namespace Engine {

class State {
public:
    virtual ~State() {}

    virtual void Init() = 0;
    virtual void ProcessInput() = 0;
    virtual void Update(sf::Time deltaTime) = 0;
    virtual void Draw() = 0;
};

class PausableState : public State {
public:
    virtual ~PausableState() {}

    virtual void Pause() = 0;
    virtual void Start() = 0;
};

}

#endif //SNAKEGAME_STATE_H
