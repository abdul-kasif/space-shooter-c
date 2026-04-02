#ifndef SCREEN_H
#define SCREEN_H

#include "terminal.h"

#define GRID_WIDTH 80
#define GRID_HEIGHT 20

void draw_border(char grid[GRID_HEIGHT][GRID_WIDTH]);
void render_grid(const TerminalSize ts, char grid[GRID_HEIGHT][GRID_WIDTH]);

#endif // !SCREEN_H
