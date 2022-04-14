#ifndef SNAKEGAME_STATEMNG_H
#define SNAKEGAME_STATEMNG_H

#include <memory>
#include <stack>

#include "State.h"

namespace Engine {
class StateMng {
public:
    void Add(std::unique_ptr<State> state);
    void Replace(std::unique_ptr<State> state);
    void Remove();
    std::unique_ptr<State>& GetCurrent();
private:
    std::stack<std::unique_ptr<State>> stateStack_;
};
}

#endif //SNAKEGAME_STATEMNG_H