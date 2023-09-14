#include <stdio.h>

/**
 * print_name - Prints a name using a function pointer.
 *
 * @name: The name to be printed.
 * @f: A function pointer that takes a char pointer as an argument.
 *
 * Description:
 * This function takes a name and a function pointer as arguments.
 * It calls the function pointed to by f with the name as its argument.
 */

void print_name(char *name, void (*f)(char *))

{
	/* Call function pointed to by f with name as its argument */
	f(name);
}

/**
 * print_normal - Prints the name in its normal order.
 *
 * @name: The name to be printed.
 *
 * Description:
 * This function takes a name and prints it in its normal order.
 */

void print_normal(char *name)
{
	printf("Name: %s\n", name);
}

/**
 * print_reverse - Prints the name in reverse order.
 *
 * @name: The name to be printed in reverse.
 *
 * Description:
 * This function takes a name and prints it in reverse order.
 */

void print_reverse(char *name)
{
	int length = 0;

	while (name[length] != '\0')
	{
	    length++;
	}

	printf("Reverse Name: ");

	for (int i = length - 1; i >= 0; i--)

	{
		printf("%c", name[i]);
	}

	printf("\n");
}

/**
 * main - Entry point of the program.
 *
 * Description:
 * This is the main function that demonstrates the use of function pointers
 * to print a name in normal and reverse order.
 *
 * Return: Always returns 0 (success).
 */

int main(void)

{
	char myName[] = "Bob Dylan";

	/* Print the name using the print_normal function */
	print_name(myName, print_normal);

	/* Print the name in reverse using the print_reverse function */
	print_name(myName, print_reverse);

	return (0);
}
