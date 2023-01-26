/*
 	Name: Prateek Garg
	Roll No.: MT2022081

	21- Global file

 */
#include <errno.h>
char *fifoOneName = "./21-fifoOne";
char *fifoTwoName = "./21-fifoTwo";

void init()
{
    int fifoOneStatus, fifoTwoStatus;

    fifoOneStatus = mkfifo(fifoOneName, S_IRWXU);
    if (!(errno == EEXIST || fifoOneStatus != -1))
        perror("Error while creating FIFO file fifoOne");

    fifoTwoStatus = mkfifo(fifoTwoName, S_IRWXU);
    if (!(errno == EEXIST || fifoTwoStatus != -1))
        perror("Error while creating FIFO file fifoTwo");
}
