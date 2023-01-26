 /*
 	Name: Prateek Garg
	Roll No.: MT2022081

	Q 5: Write a program to print the system limitation of 
   	 1. Maximum length of the arguments to the exec family of functions. 
    	 2. Maximum number of simultaneous process per user id. 
    	 3. Number of clock ticks (jiffy) per second. 
     	 4. Maximum number of open files 
    	 5. Size of a page 
    	 6. Total number of pages in the physical memory 
    	 7. Number of  currently available pages in the physical memory.

 */

#include <unistd.h>
#include <stdio.h>

void print(char *text, long value, char *unit)
{
    printf("%s - %ld %s\n", text, value, unit);
    printf("========================\n");
}

void main()
{
    long value;


    value = sysconf(_SC_ARG_MAX);
    if(value == -1)
        perror("Error while getting _SC_ARG_MAX!");
    else 
        print("Maximum length of the arguments to the exec family of functions", value, "");

    value = sysconf(_SC_CHILD_MAX);
    if(value == -1)
        perror("Error while getting _SC_CHILD_MAX!");
    else 
        print("Maximum number of simultaneous process per user id", value, "");

    value = sysconf(_SC_CLK_TCK);
    if(value == -1)
        perror("Error while getting _SC_CLK_TCK!");
    else 
        print("Number of clock ticks (jiffy) per second", value, "");
        
    value = sysconf(_SC_OPEN_MAX);
    if(value == -1)
        perror("Error while getting _SC_OPEN_MAX!");
    else 
        print("Maximum number of open files", value, "");

    value = sysconf(_SC_PAGESIZE);
    if(value == -1)
        perror("Error while getting _SC_PAGESIZE!");
    else 
        print("Size of a page", value, "bytes");

    value = sysconf(_SC_PHYS_PAGES);
    if(value == -1)
        perror("Error while getting _SC_PHYS_PAGES!");
    else 
        print("Total number of pages in the physical memory", value, "");

    value = sysconf(_SC_AVPHYS_PAGES);
    if(value == -1)
        perror("Error while getting _SC_AVPHYS_PAGES!");
    else 
        print("Number of  currently available pages in the physical memory", value, "");

}
