#ifndef TERMINAL_H
#define TERMINAL_H

void enable_raw_mode(void);
void disable_raw_mode(void);

int read_key(void);

void clear_terminal(void);

#endif // !TERMINAL_H
