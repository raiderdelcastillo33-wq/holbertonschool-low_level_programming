#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * close_file - Closes a file descriptor
 * @fd: File descriptor to close
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * open_source - Opens the source file
 * @filename: Name of the source file
 *
 * Return: The source file descriptor
 */
int open_source(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", filename);
		exit(98);
	}

	return (fd);
}

/**
 * open_destination - Opens or creates the destination file
 * @filename: Name of the destination file
 *
 * Return: The destination file descriptor
 */
int open_destination(char *filename)
{
	int fd;

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", filename);
		exit(99);
	}

	return (fd);
}

/**
 * copy_file - Copies data from one file to another
 * @fd_from: Source file descriptor
 * @fd_to: Destination file descriptor
 * @file_from: Name of the source file
 * @file_to: Name of the destination file
 */
void copy_file(int fd_from, int fd_to, char *file_from, char *file_to)
{
	char buffer[1024];
	ssize_t bytes_read;
	ssize_t written;
	ssize_t total;

	bytes_read = read(fd_from, buffer, 1024);
	while (bytes_read > 0)
	{
		total = 0;
		while (total < bytes_read)
		{
			written = write(fd_to, buffer + total, bytes_read - total);
			if (written == -1)
			{
				dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", file_to);
				exit(99);
			}
			total += written;
		}
		bytes_read = read(fd_from, buffer, 1024);
	}

	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", file_from);
		exit(98);
	}
}

/**
 * main - Copies the content of one file to another
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: Always 0 on success
 */
int main(int argc, char **argv)
{
	int fd_from;
	int fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open_source(argv[1]);
	fd_to = open_destination(argv[2]);
	copy_file(fd_from, fd_to, argv[1], argv[2]);
	close_file(fd_from);
	close_file(fd_to);

	return (0);
}
