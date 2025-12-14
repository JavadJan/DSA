#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int ft_popen(char *file,  char *const argv[], char type)
{
	if (!file || (type != 'w' && type != 'r') || !argv)
		return (-1);
	int fd[2];
	if (pipe(fd)<0)
		return -1;
	pid_t pid = fork();
	if (pid < 0)
	{
		close(fd[1]);
		close(fd[0]);
		return (-1);
	}
	if (pid == 0)
	{
		if (type == 'r') // paret read, so in child write
		{
			close(fd[0]);
			if (dup2(fd[1], STDOUT_FILENO) < 0)
			{
				close(fd[1]);
				exit (-1);
			}
			close(fd[1]);
		}
		if (type == 'w') // paretn write, so chile is reading
		{
			close(fd[1]);
			if (dup2(fd[0],STDIN_FILENO) < 0)
			{
				close(fd[0]);
				exit (-1);
			}
			close(fd[0]);
		}
		execvp(file, argv);
		exit(-1);
	}
	if (type == 'r') // in parent read, close write e.g., close(fd[1])
	{
		close(fd[1]);
		return (fd[0]); // reaturn fd[0]

	}
	else{
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
    while ((b_read = read(0, line, 9999)))
	{
		line[b_read] = '\0';
		write(fd, line, b_read);
	}
	close(fd);
    return (0);
}

//int main(void)
//{
//    char buf[1024];
//    int n;

//    // start "ls", capture its output
//    int fd_r = ft_popen("ls", (char *const[]){"ls", NULL}, 'r');

//    // start "wc -l", get its input fd
//    int fd_w = ft_popen("wc", (char *const[]){"wc", "-l", NULL}, 'w');

//    // pump data: read from ls → write to wc
//    while ((n = read(fd_r, buf, sizeof(buf))) > 0) {
//        write(fd_w, buf, n);
//    }

//    close(fd_r);
//    close(fd_w);

//    return 0;
//}
