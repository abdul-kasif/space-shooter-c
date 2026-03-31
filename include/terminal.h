#ifndef TERMINAL_H
#define TERMINAL_H

typedef struct {
  int cols;
  int rows;
} TerminalSize;

void enable_raw_mode(void);
void disable_raw_mode(void);

int read_key(void);

TerminalSize get_terminal_size(void);

void clear_terminal(void);

#endif // !TERMINAL_H
