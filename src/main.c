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

  draw_border(ts.cols, ts.rows);

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
