#pragma once

#include <cstdint>
#include <vector>

#include "GameResult.hpp"
#include "SnakeConfig.hpp"

using std::vector;

class GameManager {
 public:
  GameManager();
  virtual ~GameManager();
  virtual void updateGame(char direction) = 0;
  virtual GameResult getResults() = 0;
  virtual int getState() = 0;
  enum gameStates { GAME_RUNNING, GAME_OVER, GAME_INIT };
 protected:

  static char map[MAP_SIZE][MAP_SIZE];
  static uint8_t currentGameState;
  static GameResult results;

  void eraseMap();
};