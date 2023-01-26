// Question : 
 /*
 	Name: Prateek Garg
	Roll No.: MT2022081

	Q 8c: Write a separate program using signal system call to catch `SIGFPE`

 */
#include <signal.h> 
#include <stdio.h>  
#include <unistd.h> 

void callback()
{
    printf("Signal SIGFPE has been caught!\n");
    _exit(0);
}

void main()
{
    __sighandler_t signalStatus;

    signalStatus = signal(SIGFPE, (void *)callback);
    if (signalStatus == SIG_ERR)
        perror("Error while assigning signal handler!");
    else
        raise(SIGFPE);         
}
