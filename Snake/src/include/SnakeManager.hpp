#pragma once

#include "GameManager.hpp"
#include "GameResult.hpp"
#include "GamePart.hpp"
#include "ScreenManager.hpp"

#include <memory>

using std::unique_ptr;

class SnakeManager : public GameManager {
 public:
  SnakeManager(unique_ptr<ScreenManager> screenManager);
  virtual ~SnakeManager();
  /** @brief Updates game */
  virtual void updateGame(char direction);
  /** @brief Return Results */
  virtual GameResult getResults();
  /** @brief Returns one of States */
  virtual int getState();

 private:
  /** @brief Manages the screen */
  unique_ptr<ScreenManager> screenManager;

  std::vector<GamePart> parts;
  /**@brief Iterator holding the element including Snake's head */
  std::vector<GamePart>::iterator headIt;

  /**@brief changes position of meals if necessary */
  void mealUpdate();

  /**@brief changes position of traps if necessary */
  void trapUpdate();

  /**@brief rewrites the map */
  void snakeStepForward(char direction);

  /**@brief checks if head isn't colissing with something or if snake was fed
   */
  void updateState(void);

  void setInitialPosition(void);
  /**@brief if collision occurs, returns the iterator of collided element,
   otherwise returns parts.end()
  */
  std::vector<GamePart>::iterator checkForCollision();

  /**@brief Returns iterator of last part including part given in argument, if
   * there is no such part of given type returns parts.end() */
  std::vector<GamePart>::iterator findLastPart(uint8_t partType);
};