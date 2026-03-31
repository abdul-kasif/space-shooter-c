#include <stdbool.h>
#include <stdio.h>
#include <terminal.h>
#include <termios.h>
#include <unistd.h>

int main(void) {
  enable_raw_mode();

  clear_terminal();
  printf("Press any key except 'q': \n");

  while (true) {
    int key = read_key();

    if (key == -1) {
      continue;
    }

    if (key == 'q' || key == 'Q') {
      break;
    }

    printf("%c\n", key);
  }
  clear_terminal();
  disable_raw_mode();
  return 0;
}
