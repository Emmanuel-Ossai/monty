#include <stdlib.h>

char *custom_get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
		char *buff, int buff_size);

/**
 * custom_get_int - a C function that gets a character pointer
 * @num: the number
 * Return: char pointer
 */
char *custom_get_int(int num)
{
	unsigned int temp;
	int length = 0;
	long num_l = 0;
	char *ret;

	temp = _abs(num);
	length = get_numbase_len(temp, 10);

	if (num < 0 || num_l < 0)
		length++;
	ret = malloc(length + 1);
	if (!ret)
		return (NULL);

	fill_numbase_buff(temp, 10, ret, length);
	if (num < 0 || num_l < 0)
		ret[0] = '-';
	return (ret);
}

/**
 * _abs - a C function that gets the absolute value of an int
 * @x: the integer
 * Return: unsigned integer abs
 */
unsigned int _abs(int x)
{
	if (x < 0)
		return (-(unsigned int)x);
	return ((unsigned int)x);
}

/**
 * get_numbase_len - a C function that gets length of a buffer
 * @num: the number
 * @base: base of of number
 * Return: integer length of buffer
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
	int len = 1;

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * fill_numbase_buff - a C function that fills buffer with number
 * @num: the number to convert
 * @base: the base of number
 * @buff: result buffer
 * @buff_size: size of buffer
 * Return: nothing
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
		char *buff, int buff_size)
{
	int rem, x = buff_size - 1;

	buff[buff_size] = '\0';

	while (x >= 0)
	{
		rem = num % base;
		if (rem > 9)
			buff[x] = rem + 87;
		else
			buff[x] = rem + '0';
		num /= base;
		x--;
	}
}
