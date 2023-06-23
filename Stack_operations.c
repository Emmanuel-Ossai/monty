#include "monty.h"

void push_to_set_monty_stack_behav(stack_t **stack, unsigned int line_number);
void print_set_monty_stack_behav(stack_t **stack, unsigned int line_number);
void print_monty_top(stack_t **stack, unsigned int line_number);
void remove_monty_top(stack_t **stack, unsigned int line_number);
void swap_monty_top(stack_t **stack, unsigned int line_number);

/**
 * push_to_set_monty_stack_behav - a C function pushes a value to a stack_t
 * @stack: pointer to the top stack
 * @line_number: current working line number
 */
void push_to_set_monty_stack_behav(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new;
	int x;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		error_set(custom_allocation_error());
		return;
	}

	if (op_toks[1] == NULL)
	{
		error_set(custom_no_int_error(line_number));
		return;
	}

	for (x = 0; op_toks[1][x]; x++)
	{
		if (op_toks[1][x] == '-' && x == 0)
			continue;
		if (op_toks[1][x] < '0' || op_toks[1][x] > '9')
		{
			error_set(custom_no_int_error(line_number));
			return;
		}
	}
	new->n = atoi(op_toks[1]);
	if (get_stack_mode(*stack) == STACK)
	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
}

/**
 * print_set_monty_stack_behav - a C function that prints stack_t list
 * @stack: pointer to the top of the stack
 * @line_number: current working line number
 */
void print_set_monty_stack_behav(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}

/**
 * print_monty_top - a C function that prints the top list
 * @stack: pointer to the top stack
 * @line_number: current working line number
 */
void print_monty_top(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		error_set(custom_pint_error(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}

/**
 * remove_monty_top - a C function that removes the top stack
 * @stack: pointer to the top stack
 * @line_number: current working line number
 */
void remove_monty_top(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		error_set(custom_custom_pop_error(line_number));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * swap_monty_top - a C fucntion that swaps values
 * @stack: pointer to the top stack
 * @line_number: current working line number
 */
void swap_monty_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		error_set(custom_short_stack_error(line_number, "swap"));
		return;
	}

	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}
