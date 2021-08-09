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

	if (filename == NULL)
		return (-1);


	a = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);

	if (a == -1)
		return (-1);

	if (text_content)
	{
		for (c = 0; text_content[c] != '\0'; c++)
			;
		b = write(a, text_content, c);
			if (b == -1)
				return (-1);
	}
	close(a);
	return (-1);
}
