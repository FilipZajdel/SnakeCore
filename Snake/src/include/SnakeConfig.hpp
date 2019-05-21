#pragma once

/** Adjust to your platform */
#define DEBUG_LOG(data) std::cout<<data<<"\n"

#define MAP_SIZE 20
#define INIT_SNAKE_PARTS_NR 3
// at this moment controls are fixed
#define SNAKE_UP 'w'
#define SNAKE_DOWN 's'
#define SNAKE_LEFT 'a'
#define SNAKE_RIGHT 'd'

#define SNAKE_PART_SIGN 'x'
#define SNAKE_MEAL_SIGN 'o'
#define SNAKE_TRAP_SIGN 't'
#define MEAL_EATEN_SIGN ' '
#define TRAP_BROKEN_SIGN 'b'
#define WALL_SIGN '*'

#define POINTS_NAME "points"
#define TRAPS_NAME "traps"
#define MEALS_NAME "meals"

// RULES
#define POINTS_PER_ONE_MEAL (1)
#define PENALTY_POINTS_PER_ONE_TRAP (-1)