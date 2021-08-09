#include "main.h"

/**
 *read_textfile - read text file
 *@filename: name of the file
 *@letters: letters number
 *Return:  1 on success, -1 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t a, b, c;
	char *buf;

	if (filename == NULL)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
		return (0);

	a = open(filename, O_RDONLY);
	b = read(a, buf, letters);
	c = write(STDOUT_FILENO, buf, b);

	if (a == -1 || b == -1 || c == -1 || c != b)
	{
		free(buf);
		return (0);
	}

	free(buf);
	close(a);
	return (c);
}
