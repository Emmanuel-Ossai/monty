#include "monty.h"

int custom_short_stack_error(unsigned int line_number, char *op);
int custom_div_error(unsigned int line_number);
int custom_custom_pop_error(unsigned int line_number);
int custom_div_error(unsigned int line_number);
int custom_pchar_error(unsigned int line_number, char *message);

/**
 * custom_custom_pop_error - a C function that prints pop error
 * @line_number: the line number
 * Return: EXIT_FAILURE
 */
int custom_custom_pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * custom_pint_error - a C function that prints print error messages for empty
 * @line_number: the line number
 * Return: EXIT_FAILURE
 */
int custom_pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't print, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * custom_short_stack_error - a C function that prints monty math func error
 * @line_number: the line number
 * @op: operation
 * Return: EXIT_FAILURE
 */
int custom_short_stack_error(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * custom_div_error - a C function that prints division error messages
 * @line_number: the line number
 * Return: EXIT_FAILURE
 */
int custom_div_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * custom_pchar_error - a C function that prints pchar error
 * @line_number: the line number
 * @message: error message
 * Return: EXIT_FAILURE
 */
int custom_pchar_error(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}
