
#include "calculator.h"
#include <stdlib.h>
#include <ctype.h>

static const char *ptr;
static int *global_error;

static void skip_spaces()
{
    while(isspace(*ptr))
        ptr++;
}

static double parse_expression();

static double parse_number()
{
    skip_spaces();

    double value = strtod(ptr, (char**)&ptr);

    return value;
}

static double parse_factor()
{
    skip_spaces();

    if(*ptr == '(')
    {
        ptr++;

        double value = parse_expression();

        if(*ptr == ')')
            ptr++;
        else
            *global_error = 1;

        return value;
    }

    return parse_number();
}

static double parse_term()
{
    double value = parse_factor();

    while(1)
    {
        skip_spaces();

        if(*ptr == '*')
        {
            ptr++;
            value *= parse_factor();
        }
        else if(*ptr == '/')
        {
            ptr++;

            double rhs = parse_factor();

            if(rhs == 0)
            {
                *global_error = 2;
                return 0;
            }

            value /= rhs;
        }
        else
        {
            break;
        }
    }

    return value;
}

static double parse_expression()
{
    double value = parse_term();

    while(1)
    {
        skip_spaces();

        if(*ptr == '+')
        {
            ptr++;
            value += parse_term();
        }
        else if(*ptr == '-')
        {
            ptr++;
            value -= parse_term();
        }
        else
        {
            break;
        }
    }

    return value;
}

double evaluate_expression(const char *expr, int *error)
{
    ptr = expr;
    global_error = error;
    *error = 0;

    return parse_expression();
}
