#include "main.h"

/**
 *create_file - creat file
 *@filename: name of file
 *@text_content: write file
 *Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int a, b, c;
	char *buf;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
	{
		a = open(filename, O_CREAT, 0600);
		if (a == -1)
			return (-1);
		return (1);
	}

	for (c = 0; text_content[c] != '\0'; c++)
		;
	buf = malloc(c * sizeof(char));
	if (buf == NULL)
		return (-1);

	a = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0600);
	if (a == -1)
		return (-1);

	b = write(a, text_content, c);
	if (b == -1)
		return (-1);

	close(a);
	free(buf);
	return (1);
}
