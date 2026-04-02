#ifndef SHOOTER_H
#define SHOOTER_H

#include "screen.h"

typedef struct {
  int x; // horizontal position
} Shooter;

void shooter_init(Shooter *s);
void shooter_move_left(Shooter *s);
void shooter_move_right(Shooter *s);

void shooter_render(char grid[GRID_ROWS][GRID_COLS], Shooter *s);

#endif // !SHOOTER_H
