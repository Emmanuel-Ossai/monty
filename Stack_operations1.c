#include "monty.h"

void add_to_set_monty_stack_behav(stack_t **stack, unsigned int line_number);
void subtract_set_monty_stack_behav(stack_t **stack, unsigned int line_number);
void divide_set_monty_stack_behav(stack_t **stack, unsigned int line_number);
void multiply_set_monty_stack_behav(stack_t **stack, unsigned int line_number);
void mod_of_set_monty_stack_behav(stack_t **stack, unsigned int line_number);

/**
 * add_to_set_monty_stack_behav - a C function that adds the top two values
 * @stack: pointer to the top stack.
 * @line_number: current working line number
 */
void add_to_set_monty_stack_behav(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		error_set(custom_short_stack_error(line_number, "add"));
		return;
	}
	(*stack)->next->next->n += (*stack)->next->n;
	remove_monty_top(stack, line_number);
}

/**
 * subtract_set_monty_stack_behav - a C function that subtract the second value
 * @stack: pointer to the top stack
 * @line_number: current working line number
 */
void subtract_set_monty_stack_behav(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		error_set(custom_short_stack_error(line_number, "sub"));
		return;
	}
	(*stack)->next->next->n -= (*stack)->next->n;
	remove_monty_top(stack, line_number);
}

/**
 * divide_set_monty_stack_behav - a C fucntion that divides the second value
 * @stack: pointer to the top stack
 * @line_number: current working line number
 */
void divide_set_monty_stack_behav(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		error_set(custom_short_stack_error(line_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		error_set(custom_div_error(line_number));
		return;
	}
	(*stack)->next->next->n /= (*stack)->next->n;
	remove_monty_top(stack, line_number);
}

/**
 * multiply_set_monty_stack_behav - a C function that multiplies the values
 * @stack: pointer to the top stack
 * @line_number: the current working line
 */
void multiply_set_monty_stack_behav(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		error_set(custom_short_stack_error(line_number, "mul"));
		return;
	}
	(*stack)->next->next->n *= (*stack)->next->n;
	remove_monty_top(stack, line_number);
}

/**
 * mod_of_set_monty_stack_behav - a C function that calculate the modulus
 * @stack: pointer to the top stack
 * @line_number: the current working line
 */
void mod_of_set_monty_stack_behav(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		error_set(custom_short_stack_error(line_number, "mod"));
		return;
	}
	if ((*stack)->next->n == 0)
	{
		error_set(custom_div_error(line_number));
		return;
	}
	(*stack)->next->next->n %= (*stack)->next->n;
	remove_monty_top(stack, line_number);
}
