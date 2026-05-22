
#ifndef DISPLAY_H
#define DISPLAY_H
void display_init();
void display_clear();
void display_set_cursor(int row,int col);
void display_print(const char *text);
#endif
