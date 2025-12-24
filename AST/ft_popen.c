#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_popen(char *file,  char *const argv[], char type)
{
	int fd[2];

	if (!file || !argv || (type != 'r' && type != 'w'))
   		return (-1);

	if (pipe(fd) == -1)
		return (-1);

	int pid = fork();
	if (pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		return (-1);
	}
	// parent wants to read from child input stdout so should be redirected to the write end
	if (pid == 0) // in child
	{
		if (type == 'r') // parent read from child, child write in fd[1]
		{
			close(fd[0]);
			if (dup2(fd[1], STDOUT_FILENO) == -1)
			{
				close(fd[1]);
				exit(-1);
			}
			close(fd[1]);
		}
		else if (type == 'w') // parent wants to write, child read from fd[0]
		{
			close(fd[1]);
			if (dup2(fd[0], STDIN_FILENO) == -1)
			{
				close(fd[0]);
				exit(-1);
			}
			close(fd[0]);
		}
		execvp(file, argv);
		exit(-1);
	}
	if (type == 'r')// reading mode, close write mode
	{
		close(fd[1]);
		return (fd[0]);
	}
	else // write mode, close reading mode
	{
		close(fd[0]);
		return (fd[1]);
	}
	return (-1);
}

int main()
{
    int  fd;
    char line[9999];
	int		b_read;

    fd = ft_popen("ls", (char *const []){"ls", NULL}, 'r');
	dup2(fd, STDIN_FILENO);
	close(fd);
	fd = ft_popen("wc", (char *const []){"wc", "-l", NULL}, 'w');
    while (b_read = read(0, line, 9999))
	{
		line[b_read] = '\0';
		write(fd, line, b_read);
	}
	close(fd);
    return (0);
}