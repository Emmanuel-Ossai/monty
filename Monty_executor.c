#include "monty.h"
#include <string.h>

void token_deallocation(void);
unsigned int get_token_array_length(void);
int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int execute_monty_script(FILE *script_fd);

/**
 * token_deallocation - a function
 */
void token_deallocation(void)
{
	size_t x = 0;

	if (op_toks == NULL)
		return;

	for (x = 0; op_toks[x]; x++)
		free(op_toks[x]);

	free(op_toks);
}

/**
 * get_token_array_length - a function
 * Return: the length of current op_toks
 */
unsigned int get_token_array_length(void)
{
	unsigned int toks_len = 0;

	while (op_toks[toks_len])
		toks_len++;
	return (toks_len);
}

/**
 * is_empty_line - a function
 * @line: A pointer
 * @delims: A string
 * Return: 1 if delimiters else, 0
 */
int is_empty_line(char *line, char *delims)
{
	int x, j;

	for (x = 0; line[x]; x++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[x] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}

/**
 * get_op_func - a pointer to function.
 * @opcode: match
 *
 * Return: points to function
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", push_to_set_monty_stack_behav},
		{"pall", print_set_monty_stack_behav},
		{"pint", print_monty_top},
		{"pop", remove_monty_top},
		{"swap", swap_monty_top},
		{"add", add_to_set_monty_stack_behav},
		{"nop", execute_monty_nop},
		{"sub", subtract_set_monty_stack_behav},
		{"div", divide_set_monty_stack_behav},
		{"mul", multiply_set_monty_stack_behav},
		{"mod", mod_of_set_monty_stack_behav},
		{"pchar", print_monty_char},
		{"pstr", print_monty_string},
		{"rotl", rotate_left_monty},
		{"rotr", reverse_rotate_monty},
		{"stack", set_monty_stack_behav},
		{"queue", set_monty_queue_behav},
		{NULL, NULL}
	};
	int x;

	for (x = 0; op_funcs[x].opcode; x++)
	{
		if (strcmp(opcode, op_funcs[x].opcode) == 0)
			return (op_funcs[x].f);
	}

	return (NULL);
}

/**
 * execute_monty_script - s function
 * @script_fd: a pointer to describe
 * Return: success if successful else, failure.
 */
int execute_monty_script(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (stack_create(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line,

				&len, script_fd) != -1)
	{
		line_number++;
		op_toks = custom_strtow(line, DELIMS);
		if (op_toks == NULL)
		{
			if (is_empty_line(line, DELIMS))
				continue;
			deallocate_stack(&stack);
			return (custom_allocation_error());
		}
		else if (op_toks[0][0] == '#') /* comment line */
		{
			token_deallocation();
			continue;
		}
		op_func = get_op_func(op_toks[0]);
		if (op_func == NULL)
		{
			deallocate_stack(&stack);
			exit_status = custom_unknown_op_error(op_toks[0], line_number);
			token_deallocation();
			break;
		}
		prev_tok_len = get_token_array_length();
		op_func(&stack, line_number);
		if (get_token_array_length() != prev_tok_len)
		{
			if (op_toks && op_toks[prev_tok_len])
				exit_status = atoi(op_toks[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			token_deallocation();
			break;
		}
		token_deallocation();
	}
	deallocate_stack(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (custom_allocation_error());
	}

	free(line);
	return (exit_status);
}
