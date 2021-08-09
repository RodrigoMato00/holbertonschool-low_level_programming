#include "main.h"

/**
 *append_text_to_file - text append
 *@filename: file name
 *@text_content: write file
 *Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{

	int fd;
	int sta;
	int a;
	char *buf;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		return (-1);

	fd = open(filename, O_APPEND | O_WRONLY);
	if (fd == -1)
		return (-1);

	for (a = 0; text_content[a] != '\0'; a++)
		;
	buf = malloc(a * sizeof(char));
	if (buf == NULL)
		return (-1);

	sta = write(fd, text_content, a);
	if (sta == -1)
	{
		return (-1);
	}

	close(fd);
	free(buf);
	return (1);
}
