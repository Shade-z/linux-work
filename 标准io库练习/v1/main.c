#include "myhead.h"

int main()
{
    int fd = -1, option = 0;
	char filename[arrayLength];
	bool err = false;
	while(1){
		option = menu();
		switch(option){
			case 1:
				err = createNew_1(&fd, filename);//创建新文件
				break;
			case 2:
				err = writeTofile_1(&fd);//写文件
				break;
			case 3:
				err = readFromfile_1(&fd);//读文件
				break;
			case 4:
				err = changeMod_1(filename);//修改文件权限
				break;
			case 5:
				err = viewMod_1(&fd);//查看当前文件的权限
				break;
			case 0:
			default:
				err = true;
				break;
		}
		if(err){
			break;
		}
	}
	if(fd > 0) close(fd);//如果有打开文件,关闭文件
	return 0;

/*	if((fd=open("lseek",O_RDWR | O_APPEND)) < 0)
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
*/



/*
	int accmode, val;
	if(argc != 2){
		perror("usage: a.out <descriptor#>");
		return 1;
	}
	if((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0){
		printf("ffcntl error for fd %d", atoi(argv[1]));
		return 1;
	}
	accmode = val & O_ACCMODE;
	if(accmode == O_RDONLY) printf("read only");
	else if(accmode == O_WRONLY) printf("write only");
	else if(accmode == O_RDWR) printf("READ write");
	else printf("unknown access mode");
	if(val & O_APPEND)  printf(",append");
	if(val & O_NONBLOCK)  printf(",nonblocking");
	#if !defined(_POSIX_SOURCE) && defined(O_SYNC)
		if(val & O_SYNC)  printf(", synchronous writes");
	#endif
	putchar('\n');
*/


/*
	int val;
	if((val = fcntl(fd, F_GETFL, 0)) < 0){
		printf("ffcntl F_GETFL error");
		return ;
	}
	val != flags;
	if(fcntl(fd, F_SETFL, val) < 0){
		printf("ffcntl F_SETFL error");
		return ;
	}
*/


/*
	int fdsrc, fddes, nbytes;
	int flags = O_CREAT | O_TRUNC | O_WRONLY;
	int z;
	char buf[20], src[20], des[20];
	printf("请输入目标文件名:");
	scanf("%s",des);
	fdsrc = open("1.4.4.c", O_RDONLY);
	if(fdsrc < 0){exit(1);}
	fddes = open(des, flags, 0644);
	if(fddes < 0){exit(0);}
	while((nbytes = read(fdsrc, buf, 20))>0){
		z = write(fddes, buf, nbytes);
		if(z<0) perror("写目标文件出错");
	}
	close(fdsrc);
	close(fddes);
	printf("复制“1.4.4.c”文件为“%s”文件成功!\n",des);
*/

/*
	if(((*fd) = creat("file.hole", 0644)) < 0)
		perror("create error");
	if(write(fd,buf1,10)!=10)
		perror("buf1 write error");
	if(lseek(fd,40,SEEK_SET)==-1)
		perror("lseek error");
	if(write(fd,buf2,10)!=10)
		perror("buf2 write error");
*/
}
