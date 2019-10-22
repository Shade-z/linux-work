#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
    int fd;
    if((fd=open("lseek",O_RDWR | O_APPEND)) < 0)
    {
        perror("open file error!");
        exit(-1);
    }
    int plseek;
    if((plseek=lseek(fd, 0, SEEK_END)) == -1)
    {
        perror("lseek error!");
        exit(-1);
    }
    int writeto;
    if((writeto=write(fd,"test\n", 5)) < 0)
    {
        perror("write error!");
        exit(-1);
    }
    int readto;
    char *pread;
    if((readto=read(fd,pread,writeto)) < 0)
    {
        perror("read error");
        exit(-1);
    }

    if(write(STDOUT_FILENO, pread, readto) != readto){
        perror("ouput result error!");
        exit(-1);
    }
	return 0;
}
