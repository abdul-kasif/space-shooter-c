#include "screen.h"
#include "terminal.h"
#include <stdio.h>

#define BORDER_CHAR '#'
#define EMPTY_CHAR ' '

static void compute_screen_offsets(int *left, int *top, const TerminalSize ts) {
  *left = (ts.cols - SCREEN_WIDTH) / 2;
  *top = (ts.rows - SCREEN_HEIGHT) / 2;

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

static void draw_horizontal_border(void) {
  for (int i = 0; i < SCREEN_WIDTH; i++) {
    putchar(BORDER_CHAR);
  }
  putchar('\n');
}

void draw_border(const TerminalSize ts) {
  int left_pad = 0;
  int top_pad = 0;

  compute_screen_offsets(&left_pad, &top_pad, ts);

  print_top_padding(top_pad);

  // Top border
  print_left_padding(left_pad);
  draw_horizontal_border();

  // Middle area
  for (int i = 1; i < SCREEN_HEIGHT - 1; i++) {
    print_left_padding(left_pad);

    putchar(BORDER_CHAR);

    for (int j = 1; j < SCREEN_WIDTH - 1; j++) {
      putchar(EMPTY_CHAR);
    }

    putchar(BORDER_CHAR);
    putchar('\n');
  }

  // Bottom border
  print_left_padding(left_pad);
  draw_horizontal_border();
}
