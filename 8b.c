  /*
 	Name: Prateek Garg
	Roll No.: MT2022081

	Q 8b: Write a separate program using signal system call to catch `SIGINT`

 */
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void callback()
{
    printf("\nSignal SIGINT has been caught!\n");
    _exit(0);
}

void main()
{
    __sighandler_t signalStatus;

    signalStatus = signal(SIGINT, (void *)callback);
    if (signalStatus == SIG_ERR)
        perror("Error while assigning signal handler!");
    else
        while(1);
}
