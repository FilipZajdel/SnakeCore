#include "../Snake.hpp"

char GameManager::map[MAP_SIZE][MAP_SIZE];
uint8_t GameManager::currentGameState;
GameResult GameManager::results;

GameManager::GameManager() {
  currentGameState = GameManager::GAME_INIT;
}

GameManager::~GameManager() {}

void GameManager::eraseMap() {
  for (uint8_t mapXCoord = 0; mapXCoord < MAP_SIZE; mapXCoord++) {
    for (uint8_t mapYCoord = 0; mapYCoord < MAP_SIZE; mapYCoord++) {
      map[mapXCoord][mapYCoord] = (char)NULL;
    }
  }
}
