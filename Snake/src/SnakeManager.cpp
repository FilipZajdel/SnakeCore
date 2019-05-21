#include "../Snake.hpp"

#include <memory>
#include <iostream>

using std::unique_ptr;

// SnakeManager class implementation
SnakeManager::SnakeManager(unique_ptr <ScreenManager> screenManager) {
  srand(time(NULL));

  this->screenManager = std::move(screenManager);

  // Default index for head
  for (uint8_t snakePartIdx = INIT_SNAKE_PARTS_NR; snakePartIdx > 0;
       snakePartIdx--) {
    // sets snake vertically from middle of the map
    parts.push_back(GamePart((MAP_SIZE / 2), (MAP_SIZE / 2) - snakePartIdx,
                             GamePart::SNAKE_PART));
  }

  parts.push_back(GamePart(0, 0, GamePart::SNAKE_MEAL));
  parts.push_back(GamePart(0, 0, GamePart::SNAKE_TRAP));
  for (int xCoordinate = 0; xCoordinate < MAP_SIZE; xCoordinate++) {
    for (int yCoordinate = 0; yCoordinate < MAP_SIZE; yCoordinate++) {
      if ((0 == xCoordinate || (MAP_SIZE - 1) == xCoordinate ||
           0 == yCoordinate || (MAP_SIZE - 1) == yCoordinate)) {
        parts.push_back(GamePart(xCoordinate, yCoordinate, GamePart::WALL));
      }
    }
  }

  results.addNewResult(POINTS_NAME);
  results.addNewResult(MEALS_NAME);
  results.addNewResult(TRAPS_NAME);

  headIt = parts.begin();
}

SnakeManager::~SnakeManager() {}

void SnakeManager::updateGame(char direction) {
  DEBUG_LOG((int)currentGameState);
  switch (currentGameState) {
    case GAME_INIT:
      setInitialPosition();
      updateState();
      break;
    case GAME_RUNNING:
      snakeStepForward(direction);
      updateState();
      if(GAME_OVER == currentGameState){
        updateGame('w');
        return;
      }
      break;
    case GAME_OVER:
      break;
  }

  screenManager->updateScreen(map);
}

void SnakeManager::setInitialPosition() {
  /// @todo function to generate random positions
  for (auto& part : parts) {
    if (GamePart::SNAKE_MEAL == part.getPartType()) {
      part.setRandomCoordinates();
    }
  }
}

void SnakeManager::snakeStepForward(char direction) {
  bool lastSnakePart = true;
  std::vector<GamePart>::reverse_iterator previousSnakePartIt = parts.rend();

  for (std::vector<GamePart>::reverse_iterator currentPart = parts.rbegin();
       currentPart != parts.rend(); currentPart++) {
    if (GamePart::SNAKE_PART == currentPart->getPartType()) {
      if (lastSnakePart) {
        lastSnakePart = false;
        previousSnakePartIt = currentPart;
        continue;
      }

      previousSnakePartIt->xCoordinate = currentPart->xCoordinate;
      previousSnakePartIt->yCoordinate = currentPart->yCoordinate;
      previousSnakePartIt = currentPart;
    }
  }

  switch (direction) {
    case SNAKE_UP:
      headIt->yCoordinate--;
      DEBUG_LOG("snake up");
      break;
    case SNAKE_DOWN:
      headIt->yCoordinate++;
      DEBUG_LOG("snake up");
      break;
    case SNAKE_LEFT:
      headIt->xCoordinate--;
      DEBUG_LOG("snake up");
      break;
    case SNAKE_RIGHT:
      headIt->xCoordinate++;
      DEBUG_LOG("snake up");
      break;
    default:
      break;
  }

  eraseMap();

  for (auto& part : parts) {
    map[part.xCoordinate][part.yCoordinate] = (char)(part.getPartType());
  }
}

void SnakeManager::updateState() {
  std::vector<GamePart>::iterator collidedPart = checkForCollision();

  if (collidedPart == parts.end()) {
    currentGameState = GAME_RUNNING;
  } else {
    switch (collidedPart->getPartType()) {
      case GamePart::NONE:

        currentGameState = GAME_RUNNING;
        break;
      case GamePart::SNAKE_PART:

        currentGameState = GAME_OVER;
        break;
      case GamePart::SNAKE_MEAL:
        collidedPart->snakePartType = GamePart::MEAL_EATEN;
        parts.push_back(GamePart());
        mealUpdate();

        results.updateResult(
            POINTS_NAME,
            results.getIntResult(POINTS_NAME) + POINTS_PER_ONE_MEAL,
            results.getFloatResult(POINTS_NAME));

        currentGameState = GAME_RUNNING;
        break;
      case GamePart::SNAKE_TRAP:
        collidedPart->snakePartType = GamePart::TRAP_BROKEN;
        trapUpdate();
        parts.erase(parts.begin(), findLastPart(GamePart::SNAKE_PART));

        if (0 > results.getIntResult(POINTS_NAME)) {
          currentGameState = GAME_OVER;
        }

        currentGameState = GAME_RUNNING;
        break;
      case GamePart::WALL:

        currentGameState = GAME_OVER;
        break;
      default:

        currentGameState = GAME_RUNNING;
        break;
    }
  }
}

std::vector<GamePart>::iterator SnakeManager::checkForCollision() {
  for (std::vector<GamePart>::iterator currentPart = parts.begin();
       currentPart != parts.end(); currentPart = std::next(currentPart, 1)) {
    if (headIt != currentPart) {
      if (currentPart->xCoordinate == headIt->xCoordinate &&
          currentPart->yCoordinate == headIt->yCoordinate) {
        return currentPart;
      }
    }
  }

  return parts.end();
}

void SnakeManager::mealUpdate() {
  for (auto& part : parts) {
    if (GamePart::MEAL_EATEN == part.getPartType()) {
      part.setRandomCoordinates();
      part.snakePartType = GamePart::SNAKE_MEAL;
    }
  }
}

void SnakeManager::trapUpdate() {
  for (auto& part : parts) {
    if (GamePart::TRAP_BROKEN == part.getPartType()) {
      part.setRandomCoordinates();
      part.snakePartType = GamePart::SNAKE_MEAL;
    }
  }
}

std::vector<GamePart>::iterator SnakeManager::findLastPart(uint8_t partType) {
  for (std::vector<GamePart>::reverse_iterator part = parts.rbegin();
       part != parts.rend(); part = next(part, 1)) {
    if (partType == part->getPartType()) {
      return part.base();
    }
  }

  return parts.end();
}

GameResult SnakeManager::getResults(){
  return results;
}

int SnakeManager::getState(){
  return (int)currentGameState;
}