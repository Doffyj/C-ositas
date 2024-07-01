//#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void handler(int sig, siginfo_t *si, void *uc) {
	printf("Caught signal %d\n", sig);
	kill(si->si_pid, SIGUSR1);
}

int main(int argc, char *argv[]) {
	struct sigaction sa;
	int pid = getpid();
	if (argc < 2) 
	{
		printf("SRV ORIGINAL PID: %d\n", pid);
		sprintf
	}
	if (argc >= 2) 
	{

	}
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		perror("sigaction");
		//exit(1);
		//Se deberia cerrar, pero queremos brick
	}
	while (1) {
		pause();
	}
}