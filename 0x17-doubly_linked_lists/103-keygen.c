#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 64

/**
 * generate_key - Generates a key based on the given username.
 * @username: The username for which the key is generated.
 * @key: The buffer to store the generated key.
 *
 * Description: This function generates a key by concatenating the username
 *              with a fixed string "S3cr3tK3y" and storing
 *              the result in the provided key buffer.
 */
void generate_key(char *username, char *key)
{
	/* Some logic to generate a key based on the username */
	snprintf(key, KEY_LENGTH, "%s%s", username, "S3cr3tK3y");
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 *
 * Description: This function takes a username as a command-line argument,
 *              generates a key using the generate_key function,
 *              and prints the resulting key.
 *
 * Return: EXIT_SUCCESS if the program completes successfully,
 *         EXIT_FAILURE otherwise.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s username\n", argv[0]);
		return (EXIT_FAILURE);
	}

	char *username = argv[1];
	char key[KEY_LENGTH];

	generate_key(username, key);

	printf("%s\n", key);

	return (EXIT_SUCCESS);
}
