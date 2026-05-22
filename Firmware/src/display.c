
#include "display.h"
#include "pico/stdlib.h"
#include "hardware/i2c.h"

#define I2C_PORT i2c0
#define SDA_PIN 4
#define SCL_PIN 5

void display_init()
{
    i2c_init(I2C_PORT, 100000);

    gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);

    gpio_pull_up(SDA_PIN);
    gpio_pull_up(SCL_PIN);

    sleep_ms(100);
}

void display_clear()
{
}

void display_set_cursor(int row,int col)
{
}

void display_print(const char *text)
{
}
