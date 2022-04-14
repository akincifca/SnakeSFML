#include "../include/StateMng.h"

void Engine::StateMng::Add(std::unique_ptr<State> state) {
    if(!stateStack_.empty()) {
        auto pausable = dynamic_cast<PausableState*>(stateStack_.top().get());
        if(pausable) {
            pausable->Pause();
        }
    }
    stateStack_.push(std::move(state));
    stateStack_.top()->Init();
    auto pausable = dynamic_cast<PausableState*>(state.get());
    if(pausable) {
        pausable->Start();
    }
}

void Engine::StateMng::Replace(std::unique_ptr<State> state) {
    if(!stateStack_.empty()) {
        stateStack_.pop();
    }
    stateStack_.push(std::move(state));
    stateStack_.top()->Init();
    auto pausable = dynamic_cast<PausableState*>(state.get());
    if(pausable) {
        pausable->Start();
    }
}

void Engine::StateMng::Remove() {
    if(!stateStack_.empty()) {
        stateStack_.pop();
        if(!stateStack_.empty()) {
            auto pausable = dynamic_cast<PausableState*>(stateStack_.top().get());
            if(pausable) {
                pausable->Start();
            }
        }
    }
}

std::unique_ptr<Engine::State> &Engine::StateMng::GetCurrent() {
    return stateStack_.top();
}



