#include "../Snake.hpp"

int GamePart::getPartType() {
  return snakePartType;
}

void GamePart::setRandomCoordinates(int minXCoord,
                                    int maxXCoord,
                                    int minYCoord,
                                    int maxYCoord) {
  xCoordinate = minXCoord + rand() % (maxXCoord);
  yCoordinate = minYCoord + rand() % (maxYCoord);
}

void GamePart::updatePartType(uint8_t newPartType) {
  // check if differs from every available types
  snakePartType = newPartType;
}