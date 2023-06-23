#include <stdlib.h>

char **custom_strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);

/**
 * custom_strtow - a function
 * @str: the string
 * @delims: delimitors
 * Return: points to each word
 */

char **custom_strtow(char *str, char *delims)
{
	char **words = NULL;
	int wc, wordLen, n, x = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = get_word_count(str, delims);

	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (x < wc)
	{
		wordLen = get_word_length(str, delims);
		if (is_delim(*str, delims))
		{
			str = get_next_word(str, delims);
		}
		words[x] = malloc((wordLen + 1) * sizeof(char));
		if (words[x] == NULL)
		{
			while (x >= 0)
			{
				x--;
				free(words[x]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < wordLen)
		{
			words[x][n] = *(str + n);
			n++;
		}
		words[x][n] = '\0'; /* set end of str */
		str = get_next_word(str, delims);
		x++;
	}
	words[x] = NULL; /* last element is null for iteration */
	return (words);
}
/**
 * is_delim - pointer to the stream has delimitor char
 * @ch: the stream
 * @delims: it points to null
 * Return: 1 if success and 0 if fail
 */

int is_delim(char ch, char *delims)
{
	int x = 0;

	while (delims[x])
	{
		if (delims[x] == ch)
			return (1);
		x++;
	}
	return (0);
}

/**
 * get_word_length - length of the cur word
 * @str: the string
 * @delims: delimitors
 * Return: word length of current word
 */

int get_word_length(char *str, char *delims)
{
	int wLen = 0, pending = 1, x = 0;

	while (*(str + x))
	{
		if (is_delim(str[x], delims))
			pending = 1;
		else if (pending)
		{
			wLen++;
		}
		if (wLen > 0 && is_delim(str[x], delims))
			break;
		x++;
	}
	return (wLen);
}

/**
 * get_word_count - the word count
 * @str: the string
 * @delims: delimitors
 * Return: string count
 */

int get_word_count(char *str, char *delims)
{
	int wc = 0, pending = 1, x = 0;

	while (*(str + x))
	{
		if (is_delim(str[x], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			wc++;
		}
		x++;
	}
	return (wc);
}

/**
 * get_next_word - a string
 * @str: the next word
 * @delims: delimitors
 * Return: pointerer to the first char
 */

char *get_next_word(char *str, char *delims)
{
	int pending = 0;
	int x = 0;

	while (*(str + x))
	{
		if (is_delim(str[x], delims))
			pending = 1;
		else if (pending)
			break;
		x++;
	}
	return (str + x);
}
