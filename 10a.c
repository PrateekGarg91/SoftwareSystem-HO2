 /*
 	Name: Prateek Garg
	Roll No.: MT2022081

	Q 10a: Write a separate program using sigaction system call to catch `SIGSEGV` signal

 */
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void signalHandler(int signalNumber)
{
    printf("Caught signal SIGSEGV (%d)\n", signalNumber);
    _exit(0);
}

void main()
{
    int status; 
    struct sigaction action;
    char *a;

    action.sa_handler = signalHandler;
    action.sa_flags = 0;

    status = sigaction(SIGSEGV, &action, NULL);
    if (status == -1)
        perror("Error while setting signal handler!");
    else
    {
        raise(SIGSEGV);
    }
}
