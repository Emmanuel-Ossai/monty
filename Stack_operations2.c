#include "monty.h"

void execute_monty_nop(stack_t **stack, unsigned int line_number);
void print_monty_char(stack_t **stack, unsigned int line_number);
void print_monty_string(stack_t **stack, unsigned int line_number);
void rotate_left_monty(stack_t **stack, unsigned int line_number);
void reverse_rotate_monty(stack_t **stack, unsigned int line_number);

/**
 * execute_monty_nop - a C function
 * @stack: pointer to the top stack
 * @line_number: current working line number.
 */
void execute_monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * print_monty_char - a C function that prints the top character
 * @stack: pointer to the top stack
 * @line_number: current working line number
 */
void print_monty_char(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		error_set(custom_pchar_error(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		error_set(custom_pchar_error(line_number, "value out of range"));
		return;
	}
	printf("%c\n", (*stack)->next->n);
}

/**
 * print_monty_string - a C functions that prints monty strings
 * @stack: pointer to the top stack
 * @line_number: current working line number
 */
void print_monty_string(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
	(void)line_number;
}

/**
 * rotate_left_monty - a C function that rotates the values
 * @stack: pointer to the top stack
 * @line_number: current working line number
 */
void rotate_left_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;
	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;
	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;
	(void)line_number;
}

/**
 * reverse_rotate_monty - a c function that reverse rotates the values
 * @stack: pointer to the top stack
 * @line_number: current working line number
 */
void reverse_rotate_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;
	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;
	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;
	(void)line_number;
}
