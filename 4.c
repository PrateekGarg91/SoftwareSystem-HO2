 /*
 	Name: Prateek Garg
	Roll No.: MT2022081

	Q 4: Write a program to measure how much time is taken to execute 100 `getppid()` system call. Use time stamp counter.

 */
#include <sys/time.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <stdio.h>  

#ifdef _MSC_VER
#include <intrin.h>
#else
#include <x86intrin.h>
#endif

void main()
{
    int start, end, pid;
    struct timeval timestamp;
    int iter = 0;

    start = __rdtsc();
    while(iter < 100) {
        pid = getpid();
        iter++;
    }
    end = __rdtsc();

    printf("PID: %d\n", pid);
    printf("Time taken : %d ns \n",  (int) ((end - start)/2.4));
}
