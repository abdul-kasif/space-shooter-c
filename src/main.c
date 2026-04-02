#include "screen.h"
#include "terminal.h"
#include <stdbool.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int main(void) {
  enable_raw_mode();

  clear_terminal();

  TerminalSize ts = get_terminal_size();

  char grid[GRID_ROWS][GRID_COLS];

  draw_border(grid);
  draw_shooter_on_grid(grid);

  render_grid(ts, grid);

  printf("Press any key except 'q': \n");

  while (true) {
    int key = read_key();

    if (key == -1) {
      continue;
    }

    if (key == 'q' || key == 'Q') {
      break;
    }

    printf("%c ", key);
    fflush(stdout);
  }
  clear_terminal();
  disable_raw_mode();
  return 0;
}
