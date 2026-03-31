#include <stdbool.h>
#include <stdio.h>
#include <terminal.h>
#include <termios.h>
#include <unistd.h>

int main(void) {
  enable_raw_mode();
  int i = 0;
  while (true) {
    clear_terminal();

    printf("Just Checking ");
    sleep(1);
    if (i > 3) {
      break;
    }
    i++;
  }
  disable_raw_mode();
  printf("Hello World\n");
  return 0;
}
