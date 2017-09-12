#include <stdio.h>
#include <sys/time.h>
#include <signal.h>

void alarm_handler(int sig);
void main()
{
	struct itimerval old,new;

	old.it_interval.tv_sec = 1;
	old.it_interval.tv_usec = 0;
	old.it_value.tv_sec = 8;
	old.it_value.tv_usec = 0;
	
	setitimer(ITIMER_REAL,&old,NULL);
	signal(SIGALRM,alarm_handler);
	while(1);
}

void alarm_handler(int sig)
{
	printf("enter alarm.\n");
}

