#include "screen.h"
#include "shooter.h"
#include "terminal.h"
#include <stdbool.h>
#include <termios.h>
#include <unistd.h>

int main(void) {
  enable_raw_mode();
  clear_terminal();

  TerminalSize ts = get_terminal_size();

  char grid[GRID_ROWS][GRID_COLS];

  Shooter player;

  shooter_init(&player);

  while (true) {
    int key = read_key();

    if (key == 'q' || key == 'Q') {
      break;
    }

    if (key == 'a') {
      shooter_move_left(&player);
    }

    if (key == 'd') {
      shooter_move_right(&player);
    }

    clear_terminal();
    draw_border(grid);
    shooter_render(grid, &player);

    render_grid(ts, grid);
    usleep(100000);
  }
  clear_terminal();
  disable_raw_mode();
  return 0;
}
