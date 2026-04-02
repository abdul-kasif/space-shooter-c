#include "shooter.h"
#include "screen.h"

#define SHOOTER_ROW (GRID_ROWS - 2)

#define SHOOTER_CHAR '$'

void shooter_init(Shooter *s) { s->x = GRID_COLS / 2; }

void shooter_move_left(Shooter *s) {
  if (s->x > 1) {
    s->x--;
  }
}

void shooter_move_right(Shooter *s) {
  if (s->x < GRID_COLS - 2) {
    s->x++;
  }
}

void shooter_render(char grid[GRID_ROWS][GRID_COLS], Shooter *s) {
  grid[SHOOTER_ROW][s->x] = SHOOTER_CHAR;
}
