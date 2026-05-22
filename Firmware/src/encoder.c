
#include "encoder.h"
#include "pico/stdlib.h"

#define ENC_A 15
#define ENC_B 16
#define ENC_BTN 17

static int last_state = 0;

void encoder_init()
{
    gpio_init(ENC_A);
    gpio_set_dir(ENC_A, GPIO_IN);
    gpio_pull_up(ENC_A);

    gpio_init(ENC_B);
    gpio_set_dir(ENC_B, GPIO_IN);
    gpio_pull_up(ENC_B);

    gpio_init(ENC_BTN);
    gpio_set_dir(ENC_BTN, GPIO_IN);
    gpio_pull_up(ENC_BTN);

    last_state = gpio_get(ENC_A);
}

int encoder_read()
{
    int current = gpio_get(ENC_A);

    if(current != last_state)
    {
        last_state = current;

        if(gpio_get(ENC_B) != current)
            return 1;
        else
            return -1;
    }

    return 0;
}

int encoder_button_pressed()
{
    if(gpio_get(ENC_BTN) == 0)
    {
        sleep_ms(20);

        while(gpio_get(ENC_BTN) == 0);

        return 1;
    }

    return 0;
}
