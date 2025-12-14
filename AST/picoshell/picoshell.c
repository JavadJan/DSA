#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>


void close_fd(int fd[])
{
	close(fd[1]);
	close(fd[0]);
}

int picoshell(char **cmds[])
{
	if (!cmds || !cmds[0])
		return (1);
	int i = 0;
	int fd[2];
	int prev_fd = -1;

	/* echo "hello" | wc -l */
	while (cmds[i]) // interate into command
	{
		//for (size_t j = 0; cmds[i][j]; j++)
		//	printf("cmd: %s ", cmds[i][j]);
		//printf("\n\n");

		int next_cmd = (cmds[i + 1] != NULL);
		if (next_cmd)
		{
			if (pipe(fd) < 0) // if we had next command it means we have pipeline
				return (1);
		}
		else // we don't have pipeline,it is just single command or we arrived last cmd
		{
			fd[1] = -1;
			fd[0] = -1; // it means we do not nead any more to create pipe, so destroy them
		}
		pid_t pid = fork();
		if (pid < 0)
		{
			if (next_cmd)
				close_fd(fd); // it means we already created pipe in obove so we nead destroy them
			if (prev_fd != -1)
				close(prev_fd); // it meanns, we maybe assigned in loop
			exit(1);
		}
		if (pid == 0) // in child we read from prev, and write to the next pipe
		{
			if (prev_fd != -1)  // current cmd is a next-cmd for previ e.g., wc -l is next for echo "hello"
			{
				if (dup2(prev_fd, STDIN_FILENO) < 0)
				{
					if (next_cmd) // it means pipe already has created for next command, so nead destroy them
						close_fd(fd);
					close(prev_fd);
					exit(1);
				}
				close(prev_fd); // afer dup2 we don't nead it anymore
			}
			if (next_cmd) // it means wa had next command and fd[1] && fd[0] has already created with descriptor by kernel
			{
				close(fd[0]); // we destroy hete, I guess it does not matter where is deleted, bec we check next_cmd
				if (dup2(fd[1], STDOUT_FILENO) < 0)
				{
					close(fd[1]);// auf jeden fall, es ist prev_fd hat noch geschlieSSen
					exit(1);
				}
				close(fd[1]); // destroy fd[1], we don't need it anymore
			}
			execvp(cmds[i][0], cmds[i]); // e.g., get wc and find the path for wc, next id param == wc -1
			perror("failed execution");
			exit(1);
		}
		if (prev_fd != -1) // if is already open close it for new assigning
			close(prev_fd);
		if (next_cmd) // if next cmds is exist then assign ot read fd
			prev_fd = fd[0];
		if (next_cmd == 0) // if next command exist then is created and nead to destroy;
			close(fd[0]); // it just when next command is null, it mean next-cmd does not need to read from it. so close it 
		close(fd[1]); // it nead to destroy auf jeden fall, because at least we have one cmd, other if (!cmds) return 1
		i++;
	}
	if (prev_fd != -1)
		close(prev_fd); // check safety
	
	while (wait(NULL) > 0)
	{
		/* code */
	}
	return(0);
}


int count_of_cmd(char **av)
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
	int count_cmd = count_of_cmd(av);

	cmds = calloc((count_of_cmd(av) + 1), sizeof(char **));
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
	//for (int j = 0; cmds[j]; j++)
	//{
	//	for (int i = 0; cmds[j][i]; i++)
	//	{
	//		/* code */
	//		printf("cmd%d %s \n", j, cmds[j][i]);
	//	}
		
	//}
	
	//cmds = (char **)malloc(sizeof)
	return (res);
}