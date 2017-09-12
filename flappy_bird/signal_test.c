#include <stdio.h>
#include <signal.h>

void signal_handler(int sig)
{
	printf("enter signal handler.\n");
}

void main()
{
	while(1)
	{
		signal(SIGINT,signal_handler);
	}

}
