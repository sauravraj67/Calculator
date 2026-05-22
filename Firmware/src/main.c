
#include <stdio.h>
#include <string.h>

#include "pico/stdlib.h"

#include "keyboard.h"
#include "display.h"
#include "encoder.h"
#include "calculator.h"
#include "ui.h"

#define EXPR_MAX 64

static char expression[EXPR_MAX];
static int cursor_pos = 0;

static void clear_expression()
{
    strcpy(expression, "");
    cursor_pos = 0;
}

static void append_char(char c)
{
    int len = strlen(expression);

    if(len >= EXPR_MAX - 1)
        return;

    expression[len] = c;
    expression[len + 1] = '\0';

    cursor_pos++;
}

static void delete_char()
{
    int len = strlen(expression);

    if(len > 0)
    {
        expression[len - 1] = '\0';
        cursor_pos--;
    }
}

int main()
{
    stdio_init_all();

    keyboard_init();
    display_init();
    encoder_init();

    ui_boot();

    sleep_ms(1200);

    clear_expression();
    ui_expression(expression);

    while(1)
    {
        char key = keyboard_scan();

        if(key)
        {
            if(key == '=')
            {
                int error = 0;

                double result =
                    evaluate_expression(expression, &error);

                ui_expression(expression);

                if(error == 1)
                    ui_error("Syntax Error");
                else if(error == 2)
                    ui_error("Divide by 0");
                else
                    ui_result(result);
            }
            else if(key == 'C')
            {
                clear_expression();
                ui_expression(expression);
            }
            else if(key == 'D')
            {
                delete_char();
                ui_expression(expression);
            }
            else
            {
                append_char(key);
                ui_expression(expression);
            }
        }

        int enc = encoder_read();

        if(enc > 0)
        {
            if(cursor_pos < strlen(expression))
                cursor_pos++;
        }
        else if(enc < 0)
        {
            if(cursor_pos > 0)
                cursor_pos--;
        }

        if(encoder_button_pressed())
        {
            clear_expression();
            ui_expression(expression);
        }

        sleep_ms(10);
    }
}
