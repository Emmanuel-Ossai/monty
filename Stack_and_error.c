#include "monty.h"
#include <string.h>

void error_set(int error_code);
void deallocate_stack(stack_t **stack);
int stack_create(stack_t **stack);
int get_stack_mode(stack_t *stack);


/**
 * error_set - a function
 * @error_code: the integer
 */
void error_set(int error_code)
{
	int toks_len = 0, x = 0;
	char *exit_str = NULL;
	char **new_toks = NULL;

	toks_len = get_token_array_length();
	new_toks = malloc(sizeof(char *) * (toks_len + 2));
	if (!op_toks)
	{
		custom_allocation_error();
		return;
	}
	while (x < toks_len)
	{
		new_toks[x] = op_toks[x];
		x++;
	}
	exit_str = custom_get_int(error_code);
	if (!exit_str)
	{
		free(new_toks);
		custom_allocation_error();
		return;
	}
	new_toks[x++] = exit_str;
	new_toks[x] = NULL;
	free(op_toks);
	op_toks = new_toks;
}


/**
 * deallocate_stack - pointer to stack
 * @stack: a string
 */
void deallocate_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * stack_create - a function
 * @stack: pointer to an uninitialized instance
 * Return: failure if an error occurs, success if it doesn't
 **/
int stack_create(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (custom_allocation_error());

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;
	*stack = s;

	return (EXIT_SUCCESS);
}

/**
 * get_stack_mode - a function
 * @stack: points to stack
 *
 * Return: stack 0, if in stack mode
 * 1 if in queue mode, else 2
 */
int get_stack_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
