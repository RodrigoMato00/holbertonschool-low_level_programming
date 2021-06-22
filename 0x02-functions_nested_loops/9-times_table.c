#include "holberton.h"

/**
 * times_table - Entry point
 *
 * Description: This function prints the tables from 1 to 9
 *
 * Return:
 */
void times_table(void)
{
	int number;
	int mult;

	for (number = 0; number <= 9; number++)
	{
		for (mult = 0; mult <= 9; mult++)
		{
			int res = number * mult;

			if (res >= 10)
			{
				_putchar((res / 10) + '0');
			}
			if (res < 10 && mult > 0)
			{
				_putchar(' ');
			}
			_putchar((res % 10) + '0');
			if (mult < 9)
			{
				_putchar(',');
				_putchar(' ');
			}
		}
		_putchar('\n');
	}
}
