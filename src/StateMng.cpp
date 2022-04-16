#include "../include/StateMng.h"

void Engine::StateMng::Add(std::unique_ptr<State> state) {
    if(!stateStack_.empty()) {
        stateStack_.top()->Pause();
    }
    stateStack_.push(std::move(state));
    stateStack_.top()->Init();
    stateStack_.top()->Start();
}

void Engine::StateMng::Replace(std::unique_ptr<State> state) {
    if(!stateStack_.empty()) {
        stateStack_.pop();
    }
    stateStack_.push(std::move(state));
    stateStack_.top()->Init();
    stateStack_.top()->Start();

}

void Engine::StateMng::Remove() {
    if(!stateStack_.empty()) {
        stateStack_.pop();
        if(!stateStack_.empty()) {
            stateStack_.top()->Start();
        }
    }
}

std::unique_ptr<Engine::State> &Engine::StateMng::GetCurrent() {
    return stateStack_.top();
}



