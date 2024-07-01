// Thanks idle from stackoverflow for the means to execute the program recursively
// https://stackoverflow.com/questions/40954829/c-program-that-runs-itself-using-system

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

void ft_sendmsg(int id)
{
	printf("Sending signal USR1 to %d\n", id);
	kill(id, SIGUSR1);
	printf("Sending signal USR2 to %d\n", id);
	kill(id, SIGUSR2);
}

void ft_handler(int sig, sigaction *si, void *uc) {
	(void)uc;
	(void)si;
	printf("Caught signal %d\n", sig);
}

int main(int argc, char** argv) {
	struct sigaction sa;
	int pid = getpid();
	char cmd[100];

	if (argc < 2) 
	{
		printf("SRV ORIGINAL PID: %d\n", pid);
	}
	if (argc >= 2) 
	{
		printf("SRV RECURSIVE PID: %d\n", pid);
	}
	sprintf(cmd, "%s %d", argv[0], pid);
	system(cmd);
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		perror("sigaction");
	}
	while (1) {
		pause();
	}
	return 0;
}