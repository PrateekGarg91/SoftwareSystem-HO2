/*
 	Name: Prateek Garg
	Roll No.: MT2022081

	22 : Global file 

 */
#include <errno.h>
char *fifoName = "./22-fifo";

void init()
{
    int fifoStatus;

    fifoStatus = mkfifo(fifoName, S_IRWXU);
    if (!(errno == EEXIST || fifoStatus != -1))
        perror("Error while creating FIFO file fifoOne");
}
