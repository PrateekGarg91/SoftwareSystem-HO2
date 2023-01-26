 /*
 	Name: Prateek Garg
	Roll No.: MT2022081

	Q 1c: Write a separate program (for each time domain) to set a interval timer in 10s and 10ms - `ITIMER_PROF`
 */
#include <sys/time.h> 
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void main(int argc, char *argv[])
{
    int timerStatus;

    struct itimerval timer;

    if (argc != 2)
    {
        printf("Pass 1 for 10s timer or 2 for 10ms timer\n");
        _exit(0);
    }

    if ((int)(*argv[1] - 48) == 1)
    {
        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 0;
        timer.it_value.tv_sec = 10;
        timer.it_value.tv_usec = 0;
    }
    else if ((int)(*argv[1] - 48) == 2)
    {
        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 0;
        timer.it_value.tv_sec = 0;
        timer.it_value.tv_usec = 10000;
    }

    timerStatus = setitimer(ITIMER_PROF, &timer, 0);
    if (timerStatus == -1)
        perror("Error while setting an interval timer!");

    while(1);
}
