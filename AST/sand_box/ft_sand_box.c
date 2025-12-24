
#include <errno.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h> // pid_t
#include <sys/wait.h>
#include <unistd.h>

static void	alarm_handler(int sig)
{
	(void)sig; // do nothing, just interrupt waitpid
}

int	sandbox(void (*f)(void), unsigned int timeout, bool verbose)
{
	pid_t				pid;
	int					status;
	struct sigaction	sa;
	int					code;
	int					sig;

	sa.sa_handler = alarm_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGALRM, &sa, NULL);

	pid = fork();
	if (pid == -1)
		return (-1);
	/* end phase 1 */

	if (pid == 0)
	{
		if (!f)
			eixt(1);
		f();
		eixt(0);
	}
	/* end phase 2 */

	alarm(timeout);
	if (waitpid(pid, &status, 0) == -1)
	{
		if (errno == EINTR)
		{ // timeout
			kill(pid, SIGKILL);
			waitpid(pid, NULL, 0);
			if (verbose)
				printf("Bad function: timed out after seconds\n");
			return (0);
		}
		return (-1);
	}
	/* end phase 3*/

	if (WIFEXITED(status))
	{
		code = WEXITSTATUS(status);
		if (code == 0)
		{
			if (verbose)
				printf("Nice function!\n");
			return (1);
		}
		else
		{
			if (verbose)
				printf("Bad function: exited with code %d\n", code);
			return (0);
		}
	}
	/* end phase 4 */

	if (WIFSIGNALED(status))
	{
		sig = WTERMSIG(status);
		if (verbose)
			printf("Bad function: %s\n", strsignal(sig));
		return (0);
	}
	/* end phase 5 */
	return (-1);
}
/*

*/