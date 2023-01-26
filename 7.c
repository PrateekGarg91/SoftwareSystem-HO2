 /*
 	Name: Prateek Garg
	Roll No.: MT2022081

	Q 7: Write a simple program to print the created thread IDs.

 */
#include <pthread.h>
#include <stdio.h>

void sampleFunction()
{
    printf("Running in thread with thread ID: %lu\n", pthread_self());
}

void main()
{
    pthread_t threadID;

    if(pthread_create(&threadID, NULL, (void *)sampleFunction, NULL))
        perror("Error while creating thread");

    pthread_exit(NULL);
}
