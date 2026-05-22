
#include "keyboard.h"
#include "pico/stdlib.h"

#define ROWS 5
#define COLS 4

static const uint row_pins[ROWS] = {6,7,8,9,10};
static const uint col_pins[COLS] = {11,12,13,14};

static char keymap[ROWS][COLS] =
{
    {'7','8','9','/'},
    {'4','5','6','*'},
    {'1','2','3','-'},
    {'0','.','=','+'},
    {'(',')','C','D'}
};

void keyboard_init()
{
    for(int i=0;i<ROWS;i++)
    {
        gpio_init(row_pins[i]);
        gpio_set_dir(row_pins[i], GPIO_OUT);
        gpio_put(row_pins[i], 1);
    }

    for(int i=0;i<COLS;i++)
    {
        gpio_init(col_pins[i]);
        gpio_set_dir(col_pins[i], GPIO_IN);
        gpio_pull_up(col_pins[i]);
    }
}

char keyboard_scan()
{
    for(int r=0;r<ROWS;r++)
    {
        gpio_put(row_pins[r], 0);

        for(int c=0;c<COLS;c++)
        {
            if(gpio_get(col_pins[c]) == 0)
            {
                sleep_ms(20);

                if(gpio_get(col_pins[c]) == 0)
                {
                    while(gpio_get(col_pins[c]) == 0);

                    gpio_put(row_pins[r], 1);

                    return keymap[r][c];
                }
            }
        }

        gpio_put(row_pins[r], 1);
    }

    return 0;
}
