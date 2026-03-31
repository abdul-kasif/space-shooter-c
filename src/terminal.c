#include <stdio.h>
#include <stdlib.h>
#include <terminal.h>
#include <termios.h>
#include <unistd.h>

static struct termios old_termios;

void enable_raw_mode(void) {
  struct termios raw;
  tcgetattr(STDIN_FILENO, &old_termios);
  atexit(disable_raw_mode);

  raw = old_termios;

  raw.c_lflag &= ~(ICANON | ECHO);
  raw.c_cc[VMIN] = 0;
  raw.c_cc[VTIME] = 0;

  tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}

void disable_raw_mode(void) { tcsetattr(STDIN_FILENO, TCSANOW, &old_termios); }

int read_key(void) {
  char c;
  ssize_t n = read(STDIN_FILENO, &c, 1);

  if (n == 1) {
    return (unsigned char)c;
  }

  return -1;
}

void clear_terminal(void) {
  printf("\033c");
  fflush(stdout);
}
