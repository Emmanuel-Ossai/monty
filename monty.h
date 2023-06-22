#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

extern char **op_toks;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void deallocate_stack(stack_t **stack);
int stack_create(stack_t **stack);
int get_stack_mode(stack_t *stack);
void token_deallocation(void);
unsigned int get_token_array_length(void);
int execute_monty_script(FILE *script_fd);
void error_set(int error_code);
void push_to_set_monty_stack_behav(stack_t **stack, unsigned int line_number);
void print_set_monty_stack_behav(stack_t **stack, unsigned int line_number);
void print_monty_top(stack_t **stack, unsigned int line_number);
void remove_monty_top(stack_t **stack, unsigned int line_number);
void swap_monty_top(stack_t **stack, unsigned int line_number);
void add_to_set_monty_stack_behav(stack_t **stack, unsigned int line_number);
void execute_monty_nop(stack_t **stack, unsigned int line_number);
void subtract_set_monty_stack_behav(stack_t **stack, unsigned int line_number);
void divide_set_monty_stack_behav(stack_t **stack, unsigned int line_number);
void multiply_set_monty_stack_behav(stack_t **stack, unsigned int line_number);
void mod_of_set_monty_stack_behav(stack_t **stack, unsigned int line_number);
void print_monty_char(stack_t **stack, unsigned int line_number);
void print_monty_string(stack_t **stack, unsigned int line_number);
void rotate_left_monty(stack_t **stack, unsigned int line_number);
void reverse_rotate_monty(stack_t **stack, unsigned int line_number);
void set_monty_stack_behav(stack_t **stack, unsigned int line_number);
void set_monty_queue_behav(stack_t **stack, unsigned int line_number);
char **custom_strtow(char *str, char *delims);
char *custom_get_int(int n);
int custom_error_message(void);
int custom_allocation_error(void);
int custom_file_open_error(char *filename);
int custom_unknown_op_error(char *opcode, unsigned int line_number);
int custom_no_int_error(unsigned int line_number);
int custom_custom_pop_error(unsigned int line_number);
int custom_pint_error(unsigned int line_number);
int custom_short_stack_error(unsigned int line_number, char *op);
int custom_div_error(unsigned int line_number);
int custom_pchar_error(unsigned int line_number, char *message);

#endif
