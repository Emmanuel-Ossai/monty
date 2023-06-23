#include "monty.h"

int custom_error_message(void);
int custom_allocation_error(void);
int custom_file_open_error(char *filename);
int custom_unknown_op_error(char *opcode, unsigned int line_number);
int custom_no_int_error(unsigned int line_number);

/**
 * custom_error_message - a C function that prints usage error feedback
 * Return: EXIT_FAILURE
 */
int custom_error_message(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * custom_allocation_error - a C function that prints malloc error
 * Return:EXIT_FAILURE
 */
int custom_allocation_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * custom_file_open_error - a C function that prints file opening error
 * @filename: name of file
 * Return:EXIT_FAILURE
 */
int custom_file_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * custom_unknown_op_error - a c function that prints unknown instruction
 * @opcode: opcode
 * @line_number: the line number
 * Return:EXIT_FAILURE
 */
int custom_unknown_op_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
			line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * custom_no_int_error - a C function that prints invalid argument error
 * @line_number: the line number
 * Return: EXIT_FAILURE
 */
int custom_no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
