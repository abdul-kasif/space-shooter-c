#include "screen.h"
#include "terminal.h"
#include <stdio.h>
#include <unistd.h>

#define BORDER_CHAR '#'
#define EMPTY_CHAR ' '

static void compute_screen_offsets(int *left, int *top, const TerminalSize ts) {
  *left = (ts.cols - GRID_COLS) / 2;
  *top = (ts.rows - GRID_ROWS) / 2;

  if (*left < 0)
    *left = 0;
  if (*top < 0)
    *top = 0;
}

static void print_left_padding(int left) {
  for (int i = 0; i < left; i++) {
    putchar(EMPTY_CHAR);
  }
}

static void print_top_padding(int top) {
  for (int i = 0; i < top; i++) {
    putchar('\n');
  }
}

static void draw_horizontal_border(int row, char grid[GRID_ROWS][GRID_COLS]) {
  for (int i = 0; i < GRID_COLS; i++) {
    grid[row][i] = BORDER_CHAR;
  }
}

void draw_border(char grid[GRID_ROWS][GRID_COLS]) {

  // Top border
  draw_horizontal_border(0, grid);

  // Middle area
  for (int i = 1; i < GRID_ROWS - 1; i++) {
    grid[i][0] = BORDER_CHAR;
    for (int j = 1; j < GRID_COLS - 1; j++) {
      grid[i][j] = EMPTY_CHAR;
    }

    grid[i][GRID_COLS - 1] = BORDER_CHAR;
  }

  draw_horizontal_border(GRID_ROWS - 1, grid);
}

void render_grid(const TerminalSize ts, char grid[GRID_ROWS][GRID_COLS]) {

  int left_pad = 0;
  int top_pad = 0;

  compute_screen_offsets(&left_pad, &top_pad, ts);

  print_top_padding(top_pad);

  for (int i = 0; i < GRID_ROWS; i++) {
    print_left_padding(left_pad);
    for (int j = 0; j < GRID_COLS; j++) {
      putchar(grid[i][j]);
    }
    putchar('\n');
  }
}
