#define _POSIX_C_SOURCE 200809L
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <errno.h>
//_POSIX_C_SOURCE >= 199309L


int alarm_handler(int sig)
{
	(void) sig;
}
int sandbox(void (*f)(void), unsigned int timeout,	bool verbose)
{
	struct sigaction sa;
	pid_t pid;
	int		state; // take the state of signal termination
	int 	code; // points to the exit code


	sa.sa_handler = alarm_handler;
	sa.sa_flags = 0;

	sigemptyset(&sa.sa_mask);
	sigaction(SIGALRM, &sa, NULL);// what siganel take reaction for?
	pid = fork();
	if (pid < 0)
		return -1;
	if (pid == 0)
	{
		if (!f)
			exit(1);
		f();
		exit(0);
	}
	alarm(timeout);
	if (waitpid(pid, &state, NULL) == -1)
	{
		if (errno == EINTR)
		{
			// timeout
			kill(pid, SIGKILL);
			waitpid(pid, NULL, 0);
			if (verbose)
				printf("Bad function: time out after seconds\n");
			return 0;
		}
		return -1;
	}

	if (WIFSIGNALED(state))
	{
		code = WTERMSIG(state);
		if (verbose)
			printf("Bad function: %s\n", strsignal(code));
		return (0);
	}
	if (WIFEXITED(state)) // exited with thimeout/ nice function or bad
	{
		code = WEXITSTATUS(state);
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
	/* 
	if (nice)
		return 1;
	else bad
		return 0;
	else 
		return -1;
	 */
}


