#include "screen.h"
#include <stdio.h>

void draw_border(int cols, int rows) {
  for (int i = 0; i < cols; i++) {
    printf("#");
  }
  printf("\n");

  for (int i = 1; i < rows - 1; i++) {
    printf("#");
    for (int j = 1; j < cols - 1; j++) {
      printf(" ");
    }
    printf("#\n");
  }

  for (int i = 0; i < cols; i++) {
    printf("#");
  }
  printf("\n");
}
