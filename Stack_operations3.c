#include "monty.h"

void set_monty_stack_behav(stack_t **stack, unsigned int line_number);
void set_monty_queue_behav(stack_t **stack, unsigned int line_number);


/**
 * set_monty_stack_behav - a function
 * @stack: A pointer the mode.
 * @line_number: current working line
 */
void set_monty_stack_behav(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * set_monty_queue_behav - a function
 * @stack: points to mode
 * @line_number: Tworking line number
 */
void set_monty_queue_behav(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}

