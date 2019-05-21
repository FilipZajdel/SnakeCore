#pragma once

#include "src/include/GamePart.hpp"
#include "src/include/GameResult.hpp"
#include "src/include/ScreenManager.hpp"
#include "src/include/SnakeConfig.hpp"
#include "src/include/SnakeManager.hpp"

/**
 * Usage:
 *
 * 1. implement your screen manager class
 *
    int main() {
    SnakeManager* snakeManager{
        std::move(unique_ptr<ScreenManager>{new YourScreenManager{}})};

    char ch = 'w';

    gameManager->updateGame(ch);

    for (uint8_t it = 0; ch != 'q'; it++) {
        std::cin >> ch;
        gameManager->updateGame(ch);
    }
    }
 */