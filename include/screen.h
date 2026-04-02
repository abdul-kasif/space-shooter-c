#ifndef SCREEN_H
#define SCREEN_H

#include "terminal.h"

#define GRID_WIDTH 60
#define GRID_HEIGHT 27

void draw_border(char grid[GRID_HEIGHT][GRID_WIDTH]);
void draw_shooter_on_grid(char grid[GRID_HEIGHT][GRID_WIDTH]);

void render_grid(const TerminalSize ts, char grid[GRID_HEIGHT][GRID_WIDTH]);

#endif // !SCREEN_H
