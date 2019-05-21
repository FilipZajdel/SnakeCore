#pragma once
#ifndef game_part_h
#define game_part_h

class GamePart {
 public:
  GamePart(int x = 0, int y = 0, int type = SNAKE_PART)
      : xCoordinate(x), yCoordinate(y), snakePartType(type) {}
  int xCoordinate, yCoordinate;
  int snakePartType;
  enum snakePartTypes {
    NONE = 0,
    SNAKE_PART = SNAKE_PART_SIGN,
    SNAKE_MEAL = SNAKE_MEAL_SIGN,
    SNAKE_TRAP = SNAKE_TRAP_SIGN,
    MEAL_EATEN = MEAL_EATEN_SIGN,
    TRAP_BROKEN = TRAP_BROKEN_SIGN,
    WALL = WALL_SIGN,
  };
  int getPartType();
  void updatePartType(uint8_t newPartType);
  void setRandomCoordinates(int minXCoord = 1,
                            int maxXCoord = MAP_SIZE - 2,
                            int minYCoord = 1,
                            int maxYCoord = MAP_SIZE - 2);
};

#endif /** game_part_h */