#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void close_fd(int fd[])
{
	close(fd[0]);
	close(fd[1]);
}

int picoshell(char **cmds[])
{
	if (!cmds || !cmds[0])
		return (-1);
	int prev_fd = -1;
	int fd[2];
	pid_t pid;
	int i = 0;
	while (cmds[i])
	{
		int next_cmd = (cmds[i + 1] != NULL);
		if (next_cmd) // it means the create pipe for next
		{
			if (pipe(fd) < 0)
			{
				//if (prev_fd)
				//	close(prev_fd);
				return (1);
			}
		}
		else{ // no next no pipe, no points to descriptor
			fd[0] = -1;
			fd[1] = -1;
		}

		pid = fork();
		if (pid < 0)
		{
			if (next_cmd) // binding the next_cmd with pipe(fd[2])
				close_fd(fd);
			if (prev_fd != -1)
				close(prev_fd);
			exit(1);
		}
		// echo hello | grep h
		if (pid == 0)
		{
			if (prev_fd != -1) // if prev_fd, it means 
			{
				if (dup2(prev_fd, STDIN_FILENO) < 0) // current read from previos fd
				{
					if (next_cmd) // the fds was created close them
						close_fd(fd);
					close(prev_fd);// close the prev_fd before to exit
					exit(1);
				}
				close(prev_fd); // afetr point with STDIN, release
			}
			if (next_cmd)
			{
				close(fd[0]); // if next exist, write
				if (dup2(fd[1], STDOUT_FILENO) < 0)
				{
					close(fd[1]);
					exit(1);
				}
				close(fd[1]);// destroy fd[1], we do not need it anymore
			}
			execvp(cmds[i][0], cmds[i]);
			perror("failed execution");
			exit(1);
		}
		if (prev_fd != -1) // close the
			close(prev_fd);
		if (next_cmd)
			prev_fd = fd[0];
		if (next_cmd == 0)// if next command exist then is created and nead to destroy;
			close(fd[0]);
		close(fd[1]);
		i++;
	}
	if (prev_fd != -1)
		close(prev_fd);
	while (wait(NULL) > 0)
	{
		/* code */
	}
	return(0);
	
}

int number_of_cmd(char **av)
{
	int i = 1;
	int cmd = 1;
	while (av[i])
	{
		if (strcmp(av[i], "|") == 0)
			cmd++;
		i++;
	}
	return (cmd);
}

int main(int ac, char *av[])
{
	char ***cmds;
	int j = 0;
	int x = 0;
	int len = 0;
	int count_cmd = number_of_cmd(av);

	cmds = calloc((number_of_cmd(av) + 1), sizeof(char **)); // allocate ptr in heap as many as command
	if (!cmds)
		return 1;
	int i = 1;
	while (i < ac)
	{
		len = 0; // echo hello | wc -l
		while (i + len < ac && strcmp(av[i + len], "|") != 0) // it is good technich current until a specefic char
			len++; // after len world face the |
		
		cmds[j] = calloc(len + 1, sizeof(char *)); // cmda[i]-> {"word0", "word1", "word2"}
		if (!(cmds[j]))
			return (1);
		for (x = 0; x < len; x++)
		{
			cmds[j][x] = av[i+ x];
		}
		cmds[j][len] = NULL;
		i += len;  // move past the command arguments
		if (i < ac && strcmp(av[i], "|") == 0)
    		i++;   // only skip the "|" if it exists
		j++;
	}
	cmds[count_cmd]= NULL;
	int res = picoshell(cmds);
	for (int j = 0; cmds[j]; j++)
	{
		for (int i = 0; cmds[j][i]; i++)
		{
			/* code */
			//printf("cmd%d %s \n", j, cmds[j][i]);
			//free(cmds[j][i]);
		}
		free(cmds[j]);
	}
	free(cmds);
	//cmds = (char **)malloc(sizeof)
	return (res);
}