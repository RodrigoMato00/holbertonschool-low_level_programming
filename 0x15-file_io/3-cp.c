#include "main.h"

/**
 *main - ñJOFJOIFJÑOIDFDFñiajfñlk
 *@argc: lauiohdflaushdfuhasdlfuihas
 *@argv: uhdfudhfhdfñohduhsd
 *Return: kfjfiwekkEF
 */
int main(int argc, char *argv[])
{
	char buf[1024];
	int file_f, file_t, l, e;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "usage: cp file_from file_to\n");
			exit(97);
	}
	if (argv[1] == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	file_f = open(argv[1], O_RDONLY);
	if (file_f == -1)
	{
		dprintf(STDERR_FILENO, "Can't read from file %s\n", argv[1]);
		exit(98);
	}

	file_t = open(argv[2], O_CREAT | O_EXCL | O_WRONLY, 0664);
	if (file_t < 0)
		file_t = open(argv[2], O_TRUNC | O_WRONLY);
	if (file_t == -1)
	{
		dprintf(STDERR_FILENO, "Can't read from file %s\n", argv[2]);
		exit(99);
	}

	while ((l = read(file_f, buf, 1024)) != 0)
	{
		if (l == -1)
		{
			dprintf(STDERR_FILENO, "Can't read from file %s\n", argv[1]);
			exit(98);
		}
		e = write(file_t, buf, l);
		if (e == -1)
		{
			dprintf(STDERR_FILENO, "Can't read from file %s\n", argv[2]);
			exit(99);
		}
	}
	if (close(file_f) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_f);
		exit(100);
	}
	if (close(file_t) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_t);
		exit(100);
	}
	return (0);
}
