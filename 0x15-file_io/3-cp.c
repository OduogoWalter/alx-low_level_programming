#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

/**
 * print_error - Print an error message to stderr and exit.
 * @code: The exit code.
 * @msg: The error message.
 */
void print_error(int code, const char *msg)
{
	dprintf(2, "Error: %s\n", msg);
	exit(code);
}

/**
 * copy_file - Copy the content of one file to another.
 * @from: The source file name.
 * @to: The destination file name.
 */
void copy_file(const char *from, const char *to)
{
	int source_fd, dest_fd;
	char buffer[BUFFER_SIZE];
	ssize_t nread;

	source_fd = open(from, O_RDONLY);
	if (source_fd == -1)
		print_error(98, strerror(errno));

	dest_fd = open(to, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP);
	if (dest_fd == -1)
	{
		close(source_fd);
		print_error(99, strerror(errno));
	}

	while ((nread = read(source_fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (write(dest_fd, buffer, nread) != nread)
		{
			close(source_fd);
			close(dest_fd);
			print_error(99, strerror(errno));
		}
	}

	if (nread == -1)
	{
		close(source_fd);
		close(dest_fd);
		print_error(98, strerror(errno));
	}

	if (close(source_fd) == -1)
		print_error(100, strerror(errno));

	if (close(dest_fd) == -1)
		print_error(100, strerror(errno));
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line arguments.
 * Return: 0 for success, 97 for incorrect usage, 98 for read error, 99 for write error, 100 for close error.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(2, "Usage: %s file_from file_to\n", argv[0]);
		return (97);
	}

	copy_file(argv[1], argv[2]);
	return (0);
}

