
#include "ui.h"
#include "display.h"
#include <stdio.h>

void ui_boot()
{
    display_clear();

    display_set_cursor(0,0);
    display_print("PicoCalc");

    display_set_cursor(1,0);
    display_print("Booting...");
}

void ui_expression(const char *expr)
{
    display_clear();

    display_set_cursor(0,0);
    display_print(expr);
}

void ui_result(double result)
{
    char buffer[32];

    sprintf(buffer, "= %.2f", result);

    display_set_cursor(1,0);
    display_print(buffer);
}

void ui_error(const char *msg)
{
    display_set_cursor(1,0);
    display_print(msg);
}
