#include "main.h"

/**
 * main - check the code.
 *
 * Return: Always 0.
 */
int main(void)
{
    int r;

    r = _islower('H');
    _putchar(r + '0');
    r = _islower('o');
    _putchar(r + '0');
    r = _islower(108); /* 108 is the ASCII value for lowercase 'l' */
    _putchar(r + '0');
    _putchar('\n');
    return (0);
}
