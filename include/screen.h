#ifndef SCREEN_H
#define SCREEN_H

#include "terminal.h"

#define GRID_ROWS 27 // y
#define GRID_COLS 60 // x

void draw_border(char grid[GRID_ROWS][GRID_COLS]);
void draw_shooter_on_grid(char grid[GRID_ROWS][GRID_COLS]);

void render_grid(const TerminalSize ts, char grid[GRID_ROWS][GRID_COLS]);

#endif // !SCREEN_H
