#pragma once

#include "SnakeConfig.hpp"

/** @brief Abstract class for the output */
class ScreenManager {
 public:
  virtual ~ScreenManager(){};
  /** @brief This method updated the screen by given array of characters
   * representing objects in game */
  virtual void updateScreen(char map[MAP_SIZE][MAP_SIZE]) = 0;
};