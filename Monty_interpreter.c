#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_toks = NULL;

/**
 * main - a function
 * @argc: counts arguments
 * @argv: a pointer array
 * Return: success for exit success and error for exit failure
 */
int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (custom_error_message());
	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
		return (custom_file_open_error(argv[1]));
	exit_code = execute_monty_script(script_fd);
	fclose(script_fd);
	return (exit_code);
}
