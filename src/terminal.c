#include <stdio.h>
#include <stdlib.h>
#include <terminal.h>
#include <termios.h>
#include <unistd.h>

static struct termios old_termios;

void enable_raw_mode() {
  struct termios raw;
  tcgetattr(STDIN_FILENO, &old_termios);
  atexit(disable_raw_mode);

  raw = old_termios;

  raw.c_lflag &= ~(ICANON | ECHO);
  raw.c_cc[VMIN] = 0;
  raw.c_cc[VTIME] = 0;

  tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}

void disable_raw_mode() { tcsetattr(STDIN_FILENO, TCSANOW, &old_termios); }

void clear_terminal() {
  printf("\033c");
  fflush(stdout);
}
