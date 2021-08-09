#include "main.h"

/**
 *append_text_to_file - text append
 *@filename: file name
 *@text_content: write file
 *Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
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

	a = open(filename, O_APPEND | O_WRONLY);
	if (a == -1)
		return (-1);

	b = write(a, text_content, c);
	if (b == -1)
		return (-1);

	close(a);
	free(buf);
	return (1);
}
